/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:23:21 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/11 19:28:58 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

int	main(int argc, char *argv[])
{
	t_psw	game;
	int		status;

	status = cli_project_init(argc, argv, &game);
	if (status == 0)
		return (0);
	if (status == -1 && ft_dprintf(2, "Error\n"))
		return (1);
	if ((instmgr_load_instrs(&game) == -1 && ft_dprintf(2, "Error\n"))
		|| stkmgr_exec_instrs(&game) == -1)
	{
		stkmgr_free_ressources(&game);
		return (1);
	}
	if (sort_stk_is_sorted(game.stack_a, DIR_STRAIGHT)
		&& game.stack_b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stkmgr_free_ressources(&game);
	return (0);
}
