/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/16 19:55:45 by jgermany         ###   ########.fr       */
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

// 100 -> 699 max ; 500 -> 5499 max.
int	sort_choose_algorithm(t_stk **stacks, t_list **instrs)
{	
	if (stacks[0]->size <= 5
		&& sort_upto_5nbs(stacks[0], stacks[1], instrs) == -1)
		return (-1);
	else if (stacks[0]->size > 5 && stacks[0]->size <= 75
		&& sort_upto_100nbs(stacks, 2, instrs) == -1)
		return (-1);
	else if (stacks[0]->size > 75 && stacks[0]->size <= 250
		&& sort_upto_100nbs(stacks, 4, instrs) == -1)
		return (-1);
	else if (stacks[0]->size > 250
		&& sort_upto_100nbs(stacks, 8, instrs) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stk	*stacks[3];
	t_list	*instrs[1];
	int		init_status;

	init_status = cli_project_init(argc, argv, stacks, instrs);
	if (init_status == 0)
		return (0);
	if (init_status == -1)
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	(void)tmp_traverse_stack;
	if (sort_choose_algorithm(stacks, instrs) == -1)
		return (1); // Please free ressources.
	tmp_traverse_instructions(*instrs);
	stkmgr_stack_free(stacks[0]);
	stkmgr_stack_free(stacks[1]);
	ft_lstclear(instrs, free);
	return (0);
}
