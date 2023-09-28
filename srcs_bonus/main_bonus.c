/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:23:21 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/28 13:11:36 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void	tmp_traverse_stack(t_stk *stack)
{
	t_list	*node;

	ft_dprintf(2, "Name: stack %s; stack size: %i\n",
		stack->name, stack->size);
	if (stack->size == 0)
	{
		ft_printf("[empty]\n");
		return ;
	}
	node = *stack->head;
	while (node != NULL)
	{
		ft_printf("%i\n", *(int *)node->content);
		node = node->next;
	}
}

// NEXT - Check if everything sorted. "KO\n" or "OK\n"?
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
	tmp_traverse_stack(stacks[0]);
	tmp_traverse_stack(stacks[1]);
	stkmgr_free_ressources(stacks, instrs);
	return (0);
}
