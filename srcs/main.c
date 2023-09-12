/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/12 15:43:02 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

static void	tmp_traverse_instructions(t_list *start)
{
	while (start)
	{
		ft_printf("%s\n", (char *)start->content);
		start = start->next;
	}
}

int	sort_upto_100nbs(t_stk *stackA, t_stk *stackB, t_list **instrs)
{
	
}

int	main(int argc, char **argv)
{
	t_stk	*stacks[3];
	t_list	*instr_head[1];
	int		init_status;

	init_status = cli_project_init(argc, argv, stacks, instr_head);
	if (init_status == 0)
		return (0);
	if (init_status == -1)
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	// tmp_traverse_stack(stacks[0]);
	// tmp_traverse_stack(stacks[1]);
	(void)tmp_traverse_stack;
	sort_upto_5nbs(stacks[0], stacks[1], instr_head);
	tmp_traverse_instructions(*instr_head);
	// tmp_traverse_stack(stacks[0]);
	// tmp_traverse_stack(stacks[1]);
	stkmgr_stack_free(stacks[0]);
	stkmgr_stack_free(stacks[1]);
	ft_lstclear(instr_head, free);
	return (0);
}
