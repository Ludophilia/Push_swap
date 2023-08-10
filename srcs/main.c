/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/10 20:22:33 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

long	cli_atol(char *str)
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

int	stkmgr_stacks_fill(int size, int *nbs, t_stk *stacks[3])
{
	int	i;

	stacks[0] = stkmgr_stack_init('a');
	if (stacks[0] == NULL)
		return (-1);
	stacks[1] = stkmgr_stack_init('b');
	if (stacks[1] == NULL)
	{
		stkmgr_stack_free(stacks[0]);
		return (-1);
	}
	i = size;
	while (i >= 0)
	{
		if (stkmgr_stack_push(nbs[i], stacks[0]) == NULL)
		{
			stkmgr_stack_free(stacks[0]);
			stkmgr_stack_free(stacks[1]);
		}
		i--;
	}
	stacks[2] = NULL;
	return (0);
}

// if -1/NULL is returned, print "Error.\n".
int	push_swap_init(int argc, char **argv, t_stk *stacks[3])
{
	int	*nbs;

	if (argc == 1)
		return (-1);
	argv++;
	argc--;
	if (cli_check_if_full_digits(argv) == -1)
		return (-1);
	nbs = cli_integerize_args(argc, argv);
	if (nbs == NULL)
		return (-1);
	if (stkmgr_stacks_fill(argc, nbs, stacks) == -1)
		return (-1);
	return (0);
}

// 09/08 - Implement stack init from argv as stated by the exercice... 
// And what should be done then?
//		- [x] Fetch the nbs that are in argv... if none, return an "Error".
//		- [x] Check if they are full nbs or not (use the thing developped with
//		fract-ol)... if none, return an "Error".
//		- [x] Check if they are within the range of an int or not... if none,
//		return an "Error".
//		-		[x] Convert them to long integers (8 bits) via atol first.
//		- [x] Check if every int is unique. If not, return an "Error".
//		- [ ] Init a stack and add the nbs to it. Remember: argv[1] should 
//		at the top of the stack, and the argv[2] just behind him.
//		-		[ ] So start pushing values to the stack from the end.
int	main(int argc, char **argv)
{
	t_stk	*stacks[3];

	if (push_swap_init(argc, argv, stacks) == -1)
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	traverse_stack(stacks[0]);
	traverse_stack(stacks[1]);
	stkmgr_stack_free(stacks[0]);
	stkmgr_stack_free(stacks[1]);
	return (0);
}
