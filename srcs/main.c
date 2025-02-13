/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/13 16:52:41 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_psw	game;
	int		status;

	status = cli_project_init(argc, argv, &game);
	if (status == 0)
		return (0);
	if (status == -1 && ft_dprintf(2, "Error\n"))
		return (1);

	// Why that boolean structure? If not sorted, choose an algo an optimize
	// the instructions...
	if (stkmgr_stack_is_sorted(stacks[0], 0) == 0
		&& (sort_choose_algorithm(stacks, instrs) == -1
			|| game_opti_instrs(instrs) == -1))
	{
		stkmgr_free_ressources(stacks, instrs);
		return (1);
	}

	game_print_instrs(*instrs);
	stkmgr_free_ressources(stacks, instrs);
	return (0);
}
