/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:22:03 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/13 16:43:00 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	cli_check_if_full_digits(char **argv)
{
	t_ctr	ct;

	if (*argv == NULL)
		return (-1);
	ct.i = -1;
	while (argv[++ct.i])
	{
		ct.j = 0;
		if (argv[ct.i][ct.j] == '-' || argv[ct.i][ct.j] == '+')
			ct.j++;
		while (ft_isdigit(argv[ct.i][ct.j]))
			ct.j++;
		if (argv[ct.i][ct.j] != '\0')
			return (-1);
	}
	return (0);
}

static long	*cli_conv_args_to_nbs(char **argv, int argc)
{
	long	*nbs;
	t_ctr	ct;
	long	candidate;

	nbs = ft_calloc(argc, sizeof(long));
	if (nbs == NULL)
		return (NULL);
	ct.i = -1;
	while (argv[++ct.i])
	{
		candidate = cli_atol(argv[ct.i]);
		ct.j = -1;
		while (++ct.j < ct.i)
			if (nbs[ct.j] == candidate)
				candidate = LLONG_MAX;
		if (candidate < INT_MIN || candidate > INT_MAX)
		{
			free(nbs);
			return (NULL);
		}
		nbs[ct.i] = candidate;
	}
	return (nbs);
}

static long	*cli_get_nbs_from_argv(char **argv, int *argcp)
{
	long	*cli_nbs;
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
		if (on_heap)
			cli_free_strs(argv);
		return (NULL);
	}
	cli_nbs = cli_conv_args_to_nbs(argv, *argcp);
	if (on_heap)
		cli_free_strs(argv);
	if (cli_nbs == NULL)
		return (NULL);
	return (cli_nbs);
}

static int	*cli_substitute_nbs_to_rank(long *nbs, int size)
{
	int		*ranked;
	t_ctr	ct;
	t_min	min;

	if (cli_init_ranked_nbs(&ranked, nbs, size) == -1)
		return (NULL);
	ct = (t_ctr){.i = -1, .k = 0};
	while (++ct.i < size)
	{
		ct.j = -1;
		min = (t_min){.nb = LLONG_MAX, .pos = -1};
		while (++ct.j < size)
		{
			if (nbs[ct.j] < min.nb)
			{
				min.nb = nbs[ct.j];
				min.pos = ct.j;
			}
		}
		nbs[min.pos] = LLONG_MAX;
		ranked[min.pos] = ct.k++;
	}
	free(nbs);
	return (ranked);
}

int	cli_project_init(int argc, char **argv, t_psw *game)
{
	long	*cli_nbs;
	int		*ranked;

	if (argc == 1)
		return (0);
	argv++;
	argc--;
	cli_nbs = cli_get_nbs_from_argv(argv, &argc);
	if (cli_nbs == NULL)
		return (-1);
	ranked = cli_substitute_nbs_to_rank(cli_nbs, argc);
	if (ranked == NULL)
		return (-1);
	if (stkmgr_stacks_init(ranked, argc, game) == -1)
	{
		free(ranked);
		return (-1);
	}
	free(ranked);
	return (1);
}
