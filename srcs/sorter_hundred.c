/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_hundred.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:29:47 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/24 20:45:21 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// int	sort100_presort(t_stk *stack_a, t_stk *stack_b, int divider, t_psw *game)
// {
// 	int	ij[2];
// 	int	piv[3];
// 	int	nod[2];

// 	nod[1] = stacks[0]->size - 3;
// 	piv[2] = stacks[0]->size / divider;
// 	ij[0] = -1;
// 	while (stacks[0]->size > 3 && ++ij[0] > -1)
// 	{
// 		ij[1] = stacks[0]->size;
// 		*(long *)piv = (piv[2] * (ij[0] + 1L) << 32) + piv[2] * ij[0];
// 		while (ij[1]-- > 0)
// 		{
// 			nod[0] = *(int *)(*stacks[0]->head)->content;
// 			if (nod[0] < nod[1] && (nod[0] >= piv[0] && nod[0] < piv[1]))
// 				if (game_push(stacks[0], stacks[1], instrs) == -1
// 					|| (nod[0] >= (piv[0] + (piv[1] - piv[0]) / 2)
// 						&& game_rotate(stacks[1], 0, instrs) == -1))
// 					return (-1);
// 			if (!(nod[0] < nod[1] && (nod[0] >= piv[0] && nod[0] < piv[1]))
// 				&& game_rotate(stacks[0], 0, instrs) == -1)
// 				return (-1);
// 		}
// 	}
// 	return (0);
// }

int	sort100_presort(t_stk *stack_a, t_stk *stack_b, int divider, t_psw *game)
{
	t_ctr	ct;
	t_extr	pivr;
	t_extr	nba;

	nba.max = stack_a->size - 3;
	pivr.rge = stack_a->size / divider;
	ct.i = -1;
	while (stack_a->size > 3 && ++ct.i > -1)
	{
		ct.j = stack_a->size;
		pivr = (t_extr){pivr.rge * ct.i, pivr.rge * (ct.i + 1), pivr.rge};
		while (ct.j--)
		{
			nba.cur = *(int *)stack_a->head->content;
			if (nba.cur < nba.max && nba.cur >= pivr.min && nba.cur < pivr.max)
				if (game_push(stack_a, stack_b, game) == -1
					|| (nba.cur >= (pivr.min + pivr.rge / 2)
						&& game_rotate(stack_b, NULL, game) == -1))
					return (-1);
			else
				if (game_rotate(stack_a, NULL, game) == -1)
					return (-1);
		}
	}
	return (0);
}

static int	sort100_selection_sort(t_stk *stack_a, t_stk *stack_b, int divider,
	t_psw *game)
{
	int	b_target[2];

	while (stacks[1]->size > 1)
	{
		b_target[0] = *(int *)(*stacks[0]->head)->content - 1;
		b_target[1] = sort_get_nbpos(b_target[0], stacks[1]);
		if (b_target[1] == -1
			|| sort_rotate_stk(b_target, stacks[1], game) == -1
			|| game_push(stacks[1], stacks[0], game) == -1)
			return (-1);
	}
	if (game_push(stacks[1], stacks[0], game) == -1)
		return (-1);
	return (0);
}

// 24/03 - Now that's what needed to be done
int	sort_upto_100nbs(t_stk *stack_a, t_stk *stack_b, int divider, t_psw *game)
{
	if (sort100_presort(stack_a, stack_b, divider, game) == -1
		|| sort_upto_3nbs(stack_a, game) == -1
		|| sort100_selection_sort(stack_a, stack_b, divider, game) == -1)
		return (-1);
	return (0);
}
