/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:22:03 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/25 19:45:26 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "climgr.h"

static int	cli_check_if_full_digits(char **args)
{
	int		ij[2];
	char	*arg;

	if (*args == NULL)
		return (-1);
	ij[0] = -1;
	while (args[++ij[0]])
	{
		arg = args[ij[0]];
		ij[1] = 0;
		if (arg[ij[1]] == '-' || arg[ij[1]] == '+')
			ij[1]++;
		if (ft_isdigit(arg[ij[1]]) == 0)
			return (-1);
		while (ft_isdigit(arg[ij[1]]))
			ij[1]++;
		if (arg[ij[1]] != 0)
			return (-1);
	}
	return (0);
}

static int	*cli_integerize_args(char **argv, int argc)
{
	int		*nbs;
	int		ij[2];
	long	candidate;

	nbs = ft_calloc(argc, sizeof(int));
	if (nbs == NULL)
		return (NULL);
	ij[0] = -1;
	while (argv[++ij[0]])
	{
		candidate = cli_atol(argv[ij[0]]);
		ij[1] = -1;
		while (++ij[1] < ij[0])
			if (nbs[ij[1]] == candidate)
				candidate = (2147483647L + 1);
		if (candidate > INT_MAX || candidate < INT_MIN)
		{
			free(nbs);
			return (NULL);
		}
		nbs[ij[0]] = candidate;
	}
	return (nbs);
}

static int	*cli_substitute_nbs_by_rank(int *nbs, int size)
{
	int	ijk[3];
	int	min[2];
	int	*subt_nbs_tmp[2];

	if (cli_set_subt_nbs(subt_nbs_tmp, ijk, nbs, size) == -1)
		return (NULL);
	while (++ijk[0] < size)
	{
		ijk[1] = -1;
		*(long *)min = INT_MAX;
		while (++ijk[1] < size)
		{
			if (nbs[ijk[1]] <= min[0] && !cli_is_nb_in_nbs(
					nbs[ijk[1]], subt_nbs_tmp[1], ijk[0]))
			{
				min[0] = nbs[ijk[1]];
				min[1] = ijk[1];
			}
		}
		subt_nbs_tmp[1][ijk[2]] = min[0];
		subt_nbs_tmp[0][min[1]] = ijk[2]++;
	}
	free(nbs);
	free(subt_nbs_tmp[1]);
	return (*subt_nbs_tmp);
}

static int	*cli_get_nbs_from_argv(char **argv, int *argc_ptr)
{
	int	*cli_nbs;
	int	sp;

	sp = 0;
	if (*argc_ptr == 1)
	{
		argv = ft_split(*argv, ' ');
		if (argv == NULL)
			return (NULL);
		*argc_ptr = cli_strslen(argv);
		sp = 1;
	}
	if (cli_check_if_full_digits(argv) == -1)
	{
		if (sp == 1)
			cli_free_strs(argv);
		return (NULL);
	}
	cli_nbs = cli_integerize_args(argv, *argc_ptr);
	if (sp == 1)
		cli_free_strs(argv);
	if (cli_nbs == NULL)
		return (NULL);
	return (cli_nbs);
}

int	cli_project_init(int argc, char **argv, t_stk *stks[3], t_list **instrs)
{
	int	*cli_nbs;

	if (argc == 1)
		return (0);
	argv++;
	argc--;
	cli_nbs = cli_get_nbs_from_argv(argv, &argc);
	if (cli_nbs == NULL)
		return (-1);
	cli_nbs = cli_substitute_nbs_by_rank(cli_nbs, argc);
	if (cli_nbs == NULL)
		return (-1);
	if (stkmgr_stacks_init(argc, cli_nbs, stks) == -1)
	{
		free(cli_nbs);
		return (-1);
	}
	*instrs = 0;
	return (1);
}
