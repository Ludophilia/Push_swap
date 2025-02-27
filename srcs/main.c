/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/27 21:27:57 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	main_print_instrs(t_list *start)
{
	while (start)
	{
		ft_printf("%s\n", (char *)start->content);
		start = start->next;
	}
}

int	main(int argc, char **argv)
{
	t_psw	game;
	int		status;

	status = cli_project_init(argc, argv, &game);
	if (status == 0)
		return (0);
	if (status == -1 && ft_dprintf(2, "Error\n"))
		return (1);

	if (sort_stk_is_sorted(game.stack_a, DIR_STRAIGHT) == 0
		&& (sort_choose_algorithm(&game) == -1))
	// 		|| insmgr_opti_instrs(&game.instrs) == -1))
	{
		stkmgr_free_ressources(&game);
		return (1);
	}

	main_print_instrs(game.instrs);
	stkmgr_free_ressources(&game);
	return (0);
}
