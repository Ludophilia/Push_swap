/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:18:02 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/22 18:49:14 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort5_get_min_highest(t_pnbr *target_nb, t_stk* stack_a,
	t_stk* stack_b)
{
	t_list	*node_a;
	t_list	*node_b;
	int		i;

	*target_nb = (t_pnbr){.nb = LLONG_MAX, .pos = -1};
	node_a = stack_a->head;
	node_b = stack_b->head;
	i = 0;
	while (node_a)
	{
		if (*(int *)node_a->content > *(int *)node_b->content
			&& *(int *)node_a->content < target_nb->nb)
		{
			target_nb->nb = *(int *)node_a->content;
			target_nb->pos = i;
		}
		node_a = node_a->next;
		i++;
	}
	if (target_nb->pos < 0)
		stkmgr_get_minimum(targt, stack_a);
}

// 23/02 - There is still work left to do
static int	sort5_insertion_sort(t_stk* stack_a, t_stk* stack_b, t_psw *game)
{
	int	candidates[2];
	t_pnbr	target_nb;

	while (*stacks[1]->head)
	{
		sort5_get_min_highest(&target_nb, stack_a, stack_b);

		if (sort_rotate_stk(candidates, stacks[0], instrs) == -1
			|| game_push(stacks[1], stacks[0], instrs) == -1)
			return (-1);
	}
	if (sort_reset_stk(stacks[0], instrs) == -1)
		return (-1);
	return (0);
}

int	sort_upto_5nbs(t_stk* stack_a, t_stk* stack_b, t_psw *game)
{
	if (stkmgr_stack_is_sorted(stack_a, DIR_STRAIGHT))
		return (0);
	while (stack_a->size > 3)
		if (game_push(stack_a, stack_b, game) == -1)
			return (-1);
	if (sort_upto_3nbs(stack_a, game) == -1
		|| (stack_b->size == 2 && sort_2nbs(stack_b, game) == -1))
		return (-1);
	if (stack_b->size > 0
		&& sort5_insertion_sort(stack_a, stack_b, game) == -1)
		return (-1);
	return (0);
}
