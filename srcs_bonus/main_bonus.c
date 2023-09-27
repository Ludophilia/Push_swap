/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:23:21 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/27 14:26:20 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	tmp_print_instrs(t_list *start)
{
	while (start)
	{
		ft_printf("%s", (char *)start->content);
		start = start->next;
	}
}

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
	if (instmgr_get_instrs(instrs) == -1 && ft_dprintf(2, "Error\n"))
	{
		stkmgr_free_ressources(stacks, instrs);
		return (1);
	}
	tmp_print_instrs(*instrs);
	// Now execute the instructions.
	// Check if everything sorted.
	// "KO\n" or "OK\n"?
	stkmgr_free_ressources(stacks, instrs);
	return (0);
}
