/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:05:41 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/08 14:20:38 by jgermany         ###   ########.fr       */
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
void	pusw_swap_stacks(t_stk *stack0, t_stk *stack1)
{
	t_stk	**stacks;
	t_list	*nodes[2];
	int		i;

	stacks = (t_stk *[3]){stack0, stack1, 0};
	i = -1;
	while (stacks[++i])
	{
		if (*stacks[i]->head && (*stacks[i]->head)->next)
		{
			nodes[0] = *stacks[i]->head;
			nodes[1] = (*stacks[i]->head)->next;
			nodes[0]->next = nodes[1]->next;
			nodes[1]->next = nodes[0];
			*stacks[i]->head = nodes[1];
		}
		else
			stacks[i] = 0;
	}
	if (stacks[0] && !stacks[1])
		ft_printf("s%c\n", stack0->name);
	else if (!stacks[0] && stacks[1])
		ft_printf("s%c\n", stack1->name);
	else if (stacks[0] && stacks[1])
		ft_printf("ss\n");
}

int	main(void)
{
	t_stk	*stacks[3];

	stacks[0] = mgr_stack_init('a');
	stacks[1] = mgr_stack_init('b');
	stacks[2] = NULL;
	if (stacks[0] == NULL || stacks[1] == NULL) 
		return (1);
	if (mgr_stack_push(1, stacks[0]) == NULL)
		return (1);
	if (mgr_stack_push(2, stacks[0]) == NULL)
		return (1);
	if (mgr_stack_push(3, stacks[0]) == NULL)
		return (1);
	if (mgr_stack_push(1, stacks[1]) == NULL)
		return (1);
	if (mgr_stack_push(2, stacks[1]) == NULL)
		return (1);
	pusw_swap_stacks(stacks[0], stacks[1]);
	pusw_swap_stacks(stacks[0], NULL);
	pusw_swap_stacks(stacks[1], NULL);
	traverse_stack(stacks[0]);
	traverse_stack(stacks[1]);
	// if (pusw_swap(stacks[0]) == -1)
	// 	return (1);
	// traverse_stack(stacks[0]);
	// if (pusw_swap(stacks[0]) == -1)
	// 	return (1);
	// traverse_stack(stacks[0]);
	mgr_stack_free(stacks[0]);
	mgr_stack_free(stacks[1]);
	return (0);
}
