/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:46:10 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/27 21:27:57 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_stk_is_sorted(t_stk *stack, int order)
{
	int		pos;
	int		prev;
	int		nb;
	t_list	*current;

	current = stack->head;
	pos = -1;
	while (current)
	{
		nb = get_nb(current);
		if (++pos > 0
			&& ((order == DIR_STRAIGHT && prev > nb)
				|| (order == DIR_REVERSE && prev < nb)))
			return (0);
		prev = nb;
		current = current->next;
	}
	return (1);
}

int	sort_rotate_stk(t_pnbr *target, t_stk *stack, t_psw *game)
{
	int	fwd;

	fwd = DIR_STRAIGHT;
	if (target->pos > stack->size / 2)
		fwd = DIR_REVERSE;
	while (target->nb != get_nb(stack->head))
	{
		if (fwd && game_rotate(stack, 0, game) == -1)
			return (-1);
		else if (!fwd && game_rev_rotate(stack, 0, game) == -1)
			return (-1);
	}
	return (0);
}

int	sort_reset_stk(t_stk *stack, t_psw *game)
{
	t_pnbr	nb;
	int		dir;

	dir = DIR_STRAIGHT;
	if (stack->id == ID_STK_B)
		dir = DIR_REVERSE;
	if (sort_stk_is_sorted(stack, dir))
		return (0);
	nb.nb = 0;
	if (sort_get_nb_pos(&nb, stack) == -1
		|| sort_rotate_stk(&nb, stack, game))
		return (-1);
	return (0);
}

// 26/02 - Now sort for 500 numbers
int	sort_choose_algorithm(t_psw *game)
{
	if (game->stack_a->size <= 3
		&& sort_upto_3nbs(game->stack_a, game) == -1)
		return (-1);
	else if (game->stack_a->size > 3 && game->stack_a->size <= 5
		&& sort_upto_5nbs(game->stack_a, game->stack_b, game) == -1)
		return (-1);
	else if (game->stack_a->size > 5 && game->stack_a->size <= 75
		&& sort_upto_100nbs(game->stack_a, game->stack_b, 2, game) == -1)
		return (-1);
	else if (game->stack_a->size > 75 && game->stack_a->size <= 250
		&& sort_upto_100nbs(game->stack_a, game->stack_b, 4, game) == -1)
		return (-1);
	else if (game->stack_a->size > 250
		&& sort_over_100nbs(game->stack_a, game->stack_b, 9, game) == -1)
		return (-1);
	return (0);
}
