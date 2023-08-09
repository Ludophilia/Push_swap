/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/09 20:12:53 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// 09/08 - Implement stack init from argv as stated by the exercice... 
// And what should be done then?
//		- Fetch the nbs that are in argv... if none, return an "Error".
//		- Check if they are full nbs or not (use the thing developped with
//		fract-ol)... if none, return an "Error".
//		- Check if they are within the range of an int or not... if none,
//		return an "Error".
//		-		Convert them to long integers (8 bits) via atol first.
//		- Check if every int is unique. If not, return an "Error".
//		- Init a stack and add the nbs to it. Remember: argv[1] should 
//		at the top of the stack, and the argv[2] just behind him.
//		-		So start pushing values to the stack from the end.

int	cli_are_args_full_digit(char **args)
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

// int	cli_args_check(int argc, char **argv)
// {
// 	if (argc == 1)
// 		return (-1);
// }

int	stkmgr_stacks_fill(t_stk *stacks[3])
{
	stacks[0] = stkmgr_stack_init('a');
	if (stacks[0] == NULL)
		return (-1);
	stacks[1] = stkmgr_stack_init('b');
	if (stacks[1] == NULL)
	{
		stkmgr_stack_free(stacks[0]);
		return (-1);
	}
	stacks[2] = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	// t_stk	*stacks[3];
	(void)argc;
	if (cli_are_args_full_digit(argv + 1) == -1)
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	else
		ft_dprintf(2, "Good :)\n");
	// traverse_stack(stacks[0]);
	// traverse_stck(stacks[1]);
	// stkmgr_stack_free(stacks[0]);
	// stkmgr_stack_free(stacks[1]);
	return (0);
}
