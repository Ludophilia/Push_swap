/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:23:21 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/28 13:45:47 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	main(int argc, char *argv[])
{
	t_stk	*stacks[3];
	t_list	*instrs[1];
	int		init_status;

	init_status = cli_project_init(argc, argv, stacks, instrs);
	if (init_status == 0)
		return (0);
	if (init_status == -1 && ft_dprintf(2, "Error\n"))
		return (1);
	if ((instmgr_get_instrs(instrs) == -1 && ft_dprintf(2, "Error\n"))
		|| exc_execute_instrs(instrs, stacks) == -1)
	{
		stkmgr_free_ressources(stacks, instrs);
		return (1);
	}
	if (stkmgr_stack_is_sorted(stacks[0], STRAIGHT) && stacks[1]->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stkmgr_free_ressources(stacks, instrs);
	return (0);
}
