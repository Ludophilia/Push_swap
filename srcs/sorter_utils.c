/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:17:19 by jegerman          #+#    #+#             */
/*   Updated: 2025/03/13 20:50:11 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_nb(t_list *node)
{
	return (*(int *)node->content);
}

int	sort_optimize_cost(int pos, t_stk *stack, long *cands_rots)
{
	*cands_rots = pos;
	if (pos > stack->size / 2)
		*cands_rots = stack->size - pos;
	return (0);
}

int	sort_node_is_smallest(t_list *node_test, t_stk *stack)
{
	t_list	*node;
	int		nb_test;

	nb_test = get_nb(node_test);
	node = stack->head;
	while (node)
	{
		if (get_nb(node) < nb_test)
			return (0);
		node = node->next;
	}
	return (1);
}

int	sort_get_nb_pos(t_pnbr *target, t_stk *stack)
{
	t_list	*node;
	int		pos;

	pos = 0;
	node = stack->head;
	while (node)
	{
		if (get_nb(node) == target->nb)
		{
			target->pos = pos;
			return (pos);
		}
		++pos;
		node = node->next;
	}
	return (-1);
}

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
			&& ((order == DIR_FWD && prev > nb)
				|| (order == DIR_REV && prev < nb)))
			return (0);
		prev = nb;
		current = current->next;
	}
	return (1);
}