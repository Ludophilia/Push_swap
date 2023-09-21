/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:18:02 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/21 16:55:19 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

static int	sort5_smart_reset(t_stk *stack, int rev, t_list **instrs)
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
	if (i >= stack->size / 2)
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

static void	sort5_search_candid_stka(int candidates[2], t_stk **stacks)
{
	t_list	*nodes[2];
	int		i;

	*(long *)candidates = (0xFFFFFFFFL << 32) + 0x7FFFFFFF;
	nodes[0] = *stacks[0]->head;
	nodes[1] = *stacks[1]->head;
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
		stkmgr_get_minimum(candidates, stacks[0]);
}

static int	sort5_smart_rot_stka(t_stk **stacks, t_list **instr)
{
	int		fwd;
	int		candidates[2];

	sort5_search_candid_stka(candidates, stacks);
	fwd = 1;
	if (candidates[1] >= stacks[0]->size / 2)
		fwd = 0;
	while (*(int *)(*stacks[0]->head)->content != candidates[0])
	{
		if (fwd && game_rotate(stacks[0], 0, instr) == -1)
			return (-1);
		else if (!fwd && game_rev_rotate(stacks[0], 0, instr) == -1)
			return (-1);
	}
	return (0);
}

static int	sort5_insertion_sort(t_stk **stacks, t_list **instrs)
{
	while (*stacks[1]->head)
	{
		if (sort5_smart_rot_stka(stacks, instrs) == -1
			|| game_push(stacks[1], stacks[0], instrs) == -1)
			return (-1);
	}
	if (sort5_smart_reset(stacks[0], 0, instrs) == -1)
		return (-1);
	return (0);
}

int	sort_upto_5nbs(t_stk **stacks, t_list **instrs)
{
	if (stkmgr_stack_is_sorted(stacks[0], 0) || (stacks[0]->size > 5))
		return (0);
	while (stacks[0]->size > 3)
		if (game_push(stacks[0], stacks[1], instrs) == -1)
			return (-1);
	if (sort_upto_3nbs(stacks[0], instrs) == -1)
		return (-1);
	if (stacks[0]->size == 2 && sort_2nbs(stacks[1], instrs) == -1)
		return (-1);
	if (stacks[1]->size > 0
		&& sort5_insertion_sort(stacks, instrs) == -1)
		return (-1);
	return (0);
}
