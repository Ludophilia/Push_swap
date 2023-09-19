/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:18:02 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/19 13:29:52 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	sort5_smart_reset(t_stk *stack, int rev, t_list **instrs)
{
	t_list	*node;
	int		i;
	int		fwd;

	if (stkmgr_stack_is_sorted(stack, rev))
		return (0);
	node = *stack->head;
	i = 0;
	while (*(int *)node->content != 0)
	{
		i++;
		node = node->next;
	}
	fwd = 1;
	if (i > stack->size / 2)
		fwd = 0;
	while (*(int *)(*stack->head)->content != 0)
	{
		if (fwd && game_rotate(stack, 0, instrs) == -1)
			return (-1);
		else if (!fwd && game_rev_rotate(stack, 0, instrs) == -1)
			return (-1);
	}
	return (0);
}

void	sort5_search_candidates(int candidates[2], t_stk *stackA, t_stk *stackB)
{
	t_list	*nodes[2];
	int		min[2];
	int		i;

	*(long *)candidates = (0xFFFFFFFFL << 32) + 0x7FFFFFFF;
	nodes[0] = *stackA->head;
	nodes[1] = *stackB->head;
	i = 0;
	while (nodes[0])
	{
		if (*(int *)nodes[0]->content > *(int *)nodes[1]->content
			&& *(int *)nodes[0]->content < candidates[0])
		{
			candidates[0] = *(int *)nodes[0]->content;
			candidates[1] = i;
		}
		nodes[0] = nodes[0]->next;
		i++;
	}
	if (candidates[0] == 0x7FFFFFFF)
	{
		stkmgr_get_minimum(min, stackA);
		candidates[0] = min[0];
		candidates[1] = min[1];
	}
}

int	sort5_smart_rotate(t_stk *stackA, t_stk *stackB, t_list **instr)
{
	int		fwd;
	int		candidates[2];

	sort5_search_candidates(candidates, stackA, stackB);
	fwd = 1;
	if (candidates[1] > stackA->size / 2)
		fwd = 0;
	while (*(int *)(*stackA->head)->content != candidates[0])
	{
		if (fwd && game_rotate(stackA, 0, instr) == -1)
			return (-1);
		else if (!fwd && game_rev_rotate(stackA, 0, instr) == -1)
			return (-1);
	}
	return (0);
}

int	sort5_insertion_sort(t_stk *stackA, t_stk *stackB, t_list **instrs)
{
	while (*stackB->head)
	{
		if (sort5_smart_rotate(stackA, stackB, instrs) == -1
			|| game_push(stackB, stackA, instrs) == -1)
			return (-1);
	}
	if (sort5_smart_reset(stackA, 0, instrs) == -1)
		return (-1);
	return (0);
}

int	sort_upto_5nbs(t_stk *stackA, t_stk *stackB, t_list **instrs)
{
	if (stkmgr_stack_is_sorted(stackA, 0) || (stackA->size > 5))
		return (0);
	while (stackA->size > 3)
		if (game_push(stackA, stackB, instrs) == -1)
			return (-1);
	if (sort_upto_3nbs(stackA, instrs) == -1)
		return (-1);
	if (stackA->size == 2 && sort_2nbs(stackB, instrs) == -1)
		return (-1);
	if (stackB->size > 0 && sort5_insertion_sort(stackA, stackB, instrs) == -1)
		return (-1);
	return (0);
}
