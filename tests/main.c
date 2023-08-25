/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:05:41 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/21 15:26:12 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	traverse_stack(t_stk *stack)
{
	t_list	*node;

	node = *stack->head;
	ft_dprintf(1, "stack size : %i\n", stack->size);
	while (node != NULL)
	{
		ft_dprintf(1, "%i\n", *(int *)node->content);
		node = node->next;
	}
}

int	pop_and_clean_stack(t_stk *stack)
{
	t_list	*popped_node;

	popped_node = mgr_stack_pop(stack);
	if (popped_node == NULL)
		return (-1);
	ft_lstdelone(popped_node, free);
	return (0);
}

int	main(void)
{
	t_stk	stack_a;

	if (init_stack(&stack_a) == -1)
		return (1);
	if (push_stack(420, &stack_a) == NULL)
		return (1);
	if (push_stack(2, &stack_a) == NULL)
		return (1);
	if (push_stack(3, &stack_a) == NULL)
		return (1);
	if (pop_and_clean_stack(&stack_a) == -1)
		return (1);
	if (push_stack(3, &stack_a) == NULL)
		return (1);
	if (push_stack(4, &stack_a) == NULL)
		return (1);
	if (pop_and_clean_stack(&stack_a) == -1)
		return (1);
	if (pop_and_clean_stack(&stack_a) == -1)
		return (1);
	if (pop_and_clean_stack(&stack_a) == -1)
		return (1);
	traverse_stack(&stack_a);
	free_stack(&stack_a);
	return (0);
}
