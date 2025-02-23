/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_hundred.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:29:47 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/23 18:57:06 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort100_presort(t_stk **stacks, int divider, t_list **instrs)
{
	int	ij[2];
	int	piv[3];
	int	nod[2];

	nod[1] = stacks[0]->size - 3;
	piv[2] = stacks[0]->size / divider;
	ij[0] = -1;
	while (stacks[0]->size > 3 && ++ij[0] > -1)
	{
		ij[1] = stacks[0]->size;
		*(long *)piv = (piv[2] * (ij[0] + 1L) << 32) + piv[2] * ij[0];
		while (ij[1]-- > 0)
		{
			nod[0] = *(int *)(*stacks[0]->head)->content;
			if (nod[0] < nod[1] && (nod[0] >= piv[0] && nod[0] < piv[1]))
				if (game_push(stacks[0], stacks[1], instrs) == -1
					|| (nod[0] >= (piv[0] + (piv[1] - piv[0]) / 2)
						&& game_rotate(stacks[1], 0, instrs) == -1))
					return (-1);
			if (!(nod[0] < nod[1] && (nod[0] >= piv[0] && nod[0] < piv[1]))
				&& game_rotate(stacks[0], 0, instrs) == -1)
				return (-1);
		}
	}
	return (0);
}

static int	sort100_selection_sort(t_stk **stacks, t_list **instrs)
{
	int	b_target[2];

	while (stacks[1]->size > 1)
	{
		b_target[0] = *(int *)(*stacks[0]->head)->content - 1;
		b_target[1] = sort_get_nbpos(b_target[0], stacks[1]);
		if (b_target[1] == -1
			|| sort_rotate_stk(b_target, stacks[1], instrs) == -1
			|| game_push(stacks[1], stacks[0], instrs) == -1)
			return (-1);
	}
	if (game_push(stacks[1], stacks[0], instrs) == -1)
		return (-1);
	return (0);
}

// 24/03 - Now that's what needed to be done
int	sort_upto_100nbs(t_stk **stacks, int divider, t_list **instrs)
{
	if (sort100_presort(stacks, divider, instrs) == -1
		|| sort_upto_3nbs(stacks[0], instrs) == -1
		|| sort100_selection_sort(stacks, instrs) == -1)
		return (-1);
	return (0);
}
