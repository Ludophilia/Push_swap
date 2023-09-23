/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:18:02 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/23 18:40:33 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

static void	sort5_search_candidates(int candidates[2], t_stk **stacks)
{
	t_list	*nodes[2];
	int		i;

	*(long *)candidates = ((long)INT_MAX << 32) + INT_MAX;
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
	if (candidates[0] == INT_MAX)
		stkmgr_get_minimum(candidates, stacks[0]);
}

static int	sort5_insertion_sort(t_stk **stacks, t_list **instrs)
{
	int	a_target[2];

	while (*stacks[1]->head)
	{
		sort5_search_candidates(a_target, stacks);
		if (sort_rotate_stk(a_target, stacks[0], instrs) == -1
			|| game_push(stacks[1], stacks[0], instrs) == -1)
			return (-1);
	}
	if (sort_reset_stk(stacks[0], instrs) == -1)
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
