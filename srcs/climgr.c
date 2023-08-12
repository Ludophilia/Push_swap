/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:22:03 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/12 13:39:44 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "climgr.h"

static long	cli_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] >= '\t' && str[i] <= '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * res + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

int	cli_check_if_full_digits(char **args)
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

int	*cli_integerize_args(int argc, char **argv)
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

int	cli_project_init(int argc, char **argv, t_stk *stacks[3])
{
	int	*cli_nbs;

	if (argc == 1)
		return (0);
	argv++;
	argc--;
	if (cli_check_if_full_digits(argv) == -1)
		return (-1);
	cli_nbs = cli_integerize_args(argc, argv);
	if (cli_nbs == NULL)
		return (-1);
	if (stkmgr_stacks_fill(argc, cli_nbs, stacks) == -1)
		return (-1);
	return (1);
}
