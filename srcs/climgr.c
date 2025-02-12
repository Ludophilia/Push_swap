/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:22:03 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/12 15:53:05 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	cli_check_if_full_digits(char **args)
{
	t_ctr	ct;

	if (*args == NULL)
		return (-1);
	ct.i = -1;
	while (args[++ct.i])
	{
		ct.j = 0;
		if (args[ct.i][ct.j] == '-' || args[ct.i][ct.j] == '+')
			ct.j++;
		while (ft_isdigit(args[ct.i][ct.j]))
			ct.j++;
		if (args[ct.i][ct.j] != '\0')
			return (-1);
	}
	return (0);
}

static int	*cli_integerize_args(char **argv, int argc)
{
	int		*nbs;
	t_ctr	ct;
	long	candidate;

	nbs = ft_calloc(argc, sizeof(int));
	if (nbs == NULL)
		return (NULL);
	ct.i = -1;
	while (argv[++ct.i])
	{
		candidate = cli_atol(argv[ct.i]);
		ct.j = -1;
		while (++ct.j < ct.i)
			if (nbs[ct.j] == candidate)
				candidate = INT_MAX + 1;
		if (candidate < INT_MIN || candidate > INT_MAX)
		{
			free(nbs);
			return (NULL);
		}
		nbs[ct.i] = candidate;
	}
	return (nbs);
}

// Still not there...
static int	*cli_substitute_nbs_by_rank(int *nbs, int size)
{
	t_ctr	ct;
	int		min[2];
	int		*subt_nbs_tmp[2];

	if (cli_set_subt_nbs(subt_nbs_tmp, nbs, size) == -1)
		return (NULL);
	ct = (t_ctr){ .i = -1, .k = 0 };
	while (++ct.i < size)
	{
		ct.j = -1;
		*(long *)min = INT_MAX;
		while (++ct.j < size)
		{
			if (nbs[ct.j] <= min[0]
				&& !cli_is_nb_in_nbs(nbs[ct.j], subt_nbs_tmp[1], ct.i))
			{
				min[0] = nbs[ct.j];
				min[1] = ct.j;
			}
		}
		subt_nbs_tmp[1][ct.k] = min[0];
		subt_nbs_tmp[0][min[1]] = ct.k++;
	}
	free(nbs);
	free(subt_nbs_tmp[1]);
	return (*subt_nbs_tmp);
}

static int	*cli_get_nbs_from_argv(char **argv, int *argcp)
{
	int		*cli_nbs;
	int		on_heap;

	on_heap = 0;
	if (*argcp == 1 && ft_strchr(*argv, ' '))
	{
		on_heap = 1;
		argv = ft_split(*argv, ' ');
		if (argv == NULL)
			return (NULL);
		*argcp = cli_strslen(argv);
	}
	if (cli_check_if_full_digits(argv) == -1)
	{
		if (on_heap == 1)
			cli_free_strs(argv);
		return (NULL);
	}
	cli_nbs = cli_integerize_args(argv, *argcp);
	if (on_heap == 1)
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
