/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:05:41 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/07 20:52:58 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 6/08 - What to do now?

// Implement every push_swap operations... INCLUDING the error cases,
// and test everything of course.

// - sa/sb/ss: swap instructions 
// - pa/pb: push instructions
// - ra/rb/rr: rotate
// - rra/rrb/rrr: reverse rotate

// Generic swap instruction
void	pusw_swap(t_stk *stacks[3])
{
	t_list	*nodes[2];
	int		is_valid[2];
	int		i;

	i = -1;
	ft_bzero(is_valid, 2 * sizeof(int));
	while (stacks[++i])
	{
		if (*stacks[i]->head && (*stacks[i]->head)->next)
		{
			nodes[0] = *stacks[i]->head;
			nodes[1] = (*stacks[i]->head)->next;
			nodes[0]->next = nodes[1]->next;
			nodes[1]->next = nodes[0];
			*stacks[i]->head = nodes[1];
			is_valid[i] = 1;
		}
	}
	if (is_valid[0] && !is_valid[1])
		ft_printf("s%c\n", stacks[0]->name);
	else if (!is_valid[0] && is_valid[1])
		ft_printf("s%c\n", stacks[1]->name);
	else if (is_valid[0] && is_valid[1])
		ft_printf("ss\n");
}

int	main(void)
{
	t_stk	*stack_a;
	t_stk	*stack_b;

	stack_a = mgr_stack_init('a');
	stack_b = mgr_stack_init('b');
	if (stack_a == NULL || stack_b == NULL) 
		return (1);
	if (mgr_stack_push(1, stack_a) == NULL)
		return (1);
	if (mgr_stack_push(2, stack_a) == NULL)
		return (1);
	if (mgr_stack_push(3, stack_a) == NULL)
		return (1);
	if (mgr_stack_push(1, stack_b) == NULL)
		return (1);
	if (mgr_stack_push(2, stack_b) == NULL)
		return (1);
	pusw_swap((t_stk *[3]){stack_b, stack_a, 0});
	traverse_stack(stack_a);
	traverse_stack(stack_b);
	// if (pusw_swap(stack_a) == -1)
	// 	return (1);
	// traverse_stack(stack_a);
	// if (pusw_swap(stack_a) == -1)
	// 	return (1);
	// traverse_stack(stack_a);
	mgr_stack_free(stack_a);
	mgr_stack_free(stack_b);
	return (0);
}
