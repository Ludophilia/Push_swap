/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:46:10 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/23 18:56:06 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_rotate_stk(t_pnbr *target, t_stk *stack, t_psw *game)
{
	int	fwd;

	fwd = DIR_STRAIGHT;
	if (target->pos > stack->size / 2)
		fwd = DIR_REVERSE;
	while (target->nb != *(int *)stack->head->content)
	{
		if (fwd && game_rotate(stack, NULL, game) == -1)
			return (-1);
		else if (!fwd && game_rev_rotate(stack, NULL, game) == -1)
			return (-1);
	}
	return (0);
}

int	sort_get_nbpos(t_pnbr *target, t_stk *stack)
{
	t_list	*node;
	int		pos;

	pos = 0;
	node = stack->head;
	while (node)
	{
		if (*(int *)node->content == target->nb)
			return (pos);
		node = node->next;
		++pos;
	}
	return (-1);
}

int	sort_reset_stk(t_stk *stack, t_psw *game)
{
	t_pnbr	target;
	int		dir;

	dir = DIR_STRAIGHT;
	if (stack->id == ID_STK_B)
		dir = DIR_REVERSE;
	if (stkmgr_stack_is_sorted(stack, dir))
		return (0);
	target.nb = 0;
	target.pos = sort_get_nbpos(&target, stack);
	if (target.pos == -1 || sort_rotate_stk(&target, stack, game))
		return (-1);
	return (0);
}

// 24/03 - Now sort for 100 numbers
int	sort_choose_algorithm(t_psw *game)
{
	if (game->stack_a->size <= 3
		&& sort_upto_3nbs(game->stack_a, game) == -1)
		return (-1);
	else if (game->stack_a->size > 3 && game->stack_a->size <= 5
		&& sort_upto_5nbs(game->stack_a, game->stack_b, game) == -1)
		return (-1);
	else if (game->stack_a.size > 5 && game->stack_a.size <= 75
		&& sort_upto_100nbs(stacks, 2, instrs) == -1)
		return (-1);
	// else if (game->stack_a.size > 75 && game->stack_a.size <= 250
	// 	&& sort_upto_100nbs(stacks, 4, instrs) == -1)
	// 	return (-1);
	// else if (game->stack_a.size > 250
	// 	&& sort_over_100nbs(stacks, 9, instrs) == -1)
	// 	return (-1);
	return (0);
}
