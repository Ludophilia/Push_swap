/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:05:39 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/22 14:51:34 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort_get_numbers_and_extrema(int *nbs, t_extr *extr, t_stk *stack)
{
	t_list	*node;
	int		i;

	*extr = (t_extr){.min = LLONG_MAX, .max = -1};
	node = stack->head;
	i = -1;
	while (++i < stack->size)
	{
		nbs[i] = *(int *)node->content;
		if (nbs[i] < extr->min)
			extr->min = nbs[i];
		if (nbs[i] > extr->max)
			extr->max = nbs[i];
		node = node->next;
	}
}

static int	sort_3nbs(t_stk *stack, t_psw *game)
{
	int		nbs[3];
	t_extr	extr;

	sort_get_numbers_and_extrema(nbs, &extr, stack);
	if (extr.min == nbs[0] && extr.max == nbs[1]
		&& (game_rev_rotate(stack, NULL, game) == -1
			|| game_swap(stack, NULL, game) == -1))
		return (-1);
	else if (extr.min == nbs[1] && extr.max == nbs[2]
		&& game_swap(stack, NULL, game) == -1)
		return (-1);
	else if (extr.min == nbs[1] && extr.max == nbs[0]
		&& game_rotate(stack, NULL, game) == -1)
		return (-1);
	else if (extr.min == nbs[2] && extr.max == nbs[1]
		&& game_rev_rotate(stack, NULL, game) == -1)
		return (-1);
	else if (extr.min == nbs[2] && extr.max == nbs[0]
		&& (game_swap(stack, NULL, game) == -1
			|| game_rev_rotate(stack, NULL, game) == -1))
		return (-1);
	return (0);
}

int	sort_2nbs(t_stk *stack, t_psw *game)
{
	int		nbs[3];
	t_extr	extr;

	sort_get_numbers_and_extrema(nbs, &extr, stack);
	if (stack->id == ID_STK_A && extr.min == nbs[1] && extr.max == nbs[0]
		&& game_swap(stack, NULL, game) == -1)
		return (-1);
	else if (stack->id == ID_STK_B && extr.min == nbs[0] && extr.max == nbs[1]
		&& game_swap(stack, NULL, game) == -1)
		return (-1);
	return (0);
}

int	sort_upto_3nbs(t_stk *stack, t_psw *game)
{
	if (stkmgr_stack_is_sorted(stack, DIR_STRAIGHT))
		return (0);
	if (stack->size == 2 && sort_2nbs(stack, game) == -1)
		return (-1);
	else if (stack->size == 3 && sort_3nbs(stack, game) == -1)
		return (-1);
	return (0);
}
