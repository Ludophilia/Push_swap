/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:18:02 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/27 21:27:57 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort5_get_minimum(t_pnbr *min, t_stk *stack)
{
	t_list	*node;
	int		pos;

	node = stack->head;
	pos = 0;
	while (node)
	{
		if (get_nb(node) < min->nb)
		{
			min->nb = get_nb(node);
			min->pos = pos;
		}
		++pos;
		node = node->next;
	}
}

static int	sort5_get_next_highest_on_stack_a(int nbr_b, t_pnbr *next_high,
	t_stk *stack_a)
{
	t_list	*node_a;
	int		nbr_a;
	int		pos;

	node_a = stack_a->head;
	pos = 0;
	while (node_a)
	{
		nbr_a = get_nb(node_a);
		if (nbr_a > nbr_b && nbr_a < next_high->nb)
		{
			next_high->nb = nbr_a;
			next_high->pos = pos;
		}
		++pos;
		node_a = node_a->next;
	}
	if (next_high->pos < 0)
		sort5_get_minimum(next_high, stack_a);
	return (0);
}

static int	sort5_insertion_sort(t_stk *stack_a, t_stk *stack_b, t_psw *game)
{
	t_pnbr	next_high;
	int		nbr_b;

	while (stack_b->head != NULL)
	{
		nbr_b = get_nb(stack_b->head);
		next_high = (t_pnbr){.nb = LLONG_MAX, .pos = -1};
		if (sort5_get_next_highest_on_stack_a(nbr_b, &next_high, stack_a)
			|| sort_rotate_stk(&next_high, stack_a, game) == -1
			|| game_push(stack_b, stack_a, game) == -1)
			return (-1);
	}
	if (sort_reset_stk(stack_a, game) == -1)
		return (-1);
	return (0);
}

int	sort_upto_5nbs(t_stk *stack_a, t_stk *stack_b, t_psw *game)
{
	if (sort_stk_is_sorted(stack_a, DIR_STRAIGHT))
		return (0);
	while (stack_a->size > 3)
		if (game_push(stack_a, stack_b, game) == -1)
			return (-1);
	if (sort_upto_3nbs(stack_a, game) == -1
		|| (stack_b->size == 2 && sort_2nbs(stack_b, game) == -1)
		|| (stack_b->size > 0
			&& sort5_insertion_sort(stack_a, stack_b, game) == -1))
		return (-1);
	return (0);
}
