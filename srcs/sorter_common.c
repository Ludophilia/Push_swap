/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:46:10 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/13 20:50:00 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_rotate_stk(t_pnbr *target, t_stk *stack, t_psw *game)
{
	int	fwd;

	fwd = DIR_FWD;
	if (target->pos > stack->size / 2)
		fwd = DIR_REV;
	while (target->nb != get_nb(stack->head))
	{
		if (fwd && game_rotate(stack, NULL, game) == -1)
			return (-1);
		else if (!fwd && game_rev_rotate(stack, NULL, game) == -1)
			return (-1);
	}
	return (0);
}

int	sort_reset_stk(t_stk *stack, t_psw *game)
{
	t_pnbr	nb;
	int		dir;

	dir = DIR_FWD;
	if (stack->id == ID_STKB)
		dir = DIR_REV;
	if (sort_stk_is_sorted(stack, dir))
		return (0);
	nb.nb = 0;
	if (sort_get_nb_pos(&nb, stack) == -1
		|| sort_rotate_stk(&nb, stack, game))
		return (-1);
	return (0);
}

int	sort_choose_algorithm(t_psw *game)
{
	t_stk	*stack_a;
	t_stk	*stack_b;

	stack_a = game->stack_a;
	stack_b = game->stack_b;
	if (stack_b->size == 0
		&& sort_stk_is_sorted(stack_a, DIR_FWD))
		return (0);
	if ((stack_a->size <= 3
			&& sort_upto_3nbs(stack_a, game) == -1)
		|| (stack_a->size > 3 && stack_a->size <= 5
			&& sort_upto_5nbs(stack_a, stack_b, game) == -1)
		|| (stack_a->size > 5 && stack_a->size <= 75
			&& sort_upto_100nbs(stack_a, stack_b, 2, game) == -1)
		|| (stack_a->size > 75 && stack_a->size <= 250
			&& sort_upto_100nbs(stack_a, stack_b, 4, game) == -1)
		|| (stack_a->size > 250
			&& sort_over_100nbs(stack_a, stack_b, 5, game) == -1))
		return (-1);
	return (0);
}
