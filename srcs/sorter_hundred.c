/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_hundred.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:29:47 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/25 19:16:38 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	sort100_presort_subrange(t_extr *pivr, long nba_lim, t_psw *game)
{
	long	nba;
	long	pivot;
	int		size;

	size = game->stack_a->size;
	pivot = pivr->min + pivr->range / 2;
	while (size--)
	{
		nba = *(int *)game->stack_a->head->content;
		if (nba < nba_lim && nba >= pivr->min && nba < pivr->max)
		{
			if (game_push(game->stack_a, game->stack_b, game) == -1
				|| (nba >= pivot && game_rotate(game->stack_b, 0, game) == -1))
				return (-1);
		}
		else
			if (game_rotate(game->stack_a, 0, game) == -1)
				return (-1);
	}
	return (0);
}

int	sort100_presort(t_stk *stack_a, int divider, t_psw *game)
{
	int		turn;
	t_extr	pivr;
	long	nba_lim;

	nba_lim = stack_a->size - 3;
	pivr.range = stack_a->size / divider;
	turn = 0;
	while (stack_a->size > 3)
	{
		pivr.min = pivr.range * turn;
		pivr.max = pivr.range * (turn + 1);
		if (sort100_presort_subrange(&pivr, nba_lim, game) == -1)
			return (-1);
		++turn;
	}
	return (0);
}

static int	sort100_selection_sort(t_stk *stack_a, t_stk *stack_b, t_psw *game)
{
	t_pnbr	nbb;

	while (stack_b->size > 1)
	{
		nbb.nb = *(int *)stack_a->head->content - 1;
		if (sort_get_nb_pos(&nbb, stack_b) == -1
			|| sort_rotate_stk(&nbb, stack_b, game) == -1
			|| game_push(stack_b, stack_a, game) == -1)
			return (-1);
	}
	if (game_push(stack_b, stack_a, game) == -1)
		return (-1);
	return (0);
}

int	sort_upto_100nbs(t_stk *stack_a, t_stk *stack_b, int divider, t_psw *game)
{
	if (sort100_presort(stack_a, divider, game) == -1
		|| sort_upto_3nbs(stack_a, game) == -1
		|| sort100_selection_sort(stack_a, stack_b, game) == -1)
		return (-1);
	return (0);
}
