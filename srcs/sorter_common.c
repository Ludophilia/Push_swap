/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:46:10 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/11 18:03:43 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_get_pos_stk(int target, t_stk *stack)
{
	t_list	*node;
	int		i;

	i = 0;
	node = *stack->head;
	while (node)
	{
		if (*(int *)node->content == target)
			return (i);
		i++;
		node = node->next;
	}
	return (-1);
}

int	sort_rotate_stk(int target[2], t_stk *stack, t_list **instrs)
{
	int	fwd;

	fwd = 1;
	if (target[1] > stack->size / 2)
		fwd = 0;
	while (target[0] != *(int *)(*stack->head)->content)
	{
		if (fwd && game_rotate(stack, 0, instrs) == -1)
			return (-1);
		else if (!fwd && game_rev_rotate(stack, 0, instrs) == -1)
			return (-1);
	}
	return (0);
}

int	sort_reset_stk(t_stk *stack, t_list **instrs)
{
	int		target[2];
	int		rev;

	rev = 0;
	if (*stack->name == 'b')
		rev = 1;
	if (stkmgr_stack_is_sorted(stack, rev))
		return (0);
	target[0] = 0;
	target[1] = sort_get_pos_stk(target[0], stack);
	if (target[1] == -1 || sort_rotate_stk(target, stack, instrs))
		return (-1);
	return (0);
}

int	sort_choose_algorithm(t_stk **stacks, t_list **instrs)
{
	if (stacks[0]->size <= 3 && sort_upto_3nbs(stacks[0], instrs) == -1)
		return (-1);
	else if (stacks[0]->size > 3 && stacks[0]->size <= 5
		&& sort_upto_5nbs(stacks, instrs) == -1)
		return (-1);
	else if (stacks[0]->size > 5 && stacks[0]->size <= 75
		&& sort_upto_100nbs(stacks, 2, instrs) == -1)
		return (-1);
	else if (stacks[0]->size > 75 && stacks[0]->size <= 250
		&& sort_upto_100nbs(stacks, 4, instrs) == -1)
		return (-1);
	else if (stacks[0]->size > 250
		&& sort_over_100nbs(stacks, 9, instrs) == -1)
		return (-1);
	return (0);
}
