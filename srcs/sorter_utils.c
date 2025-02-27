/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:17:19 by jegerman          #+#    #+#             */
/*   Updated: 2025/02/27 21:28:52 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_nb(t_list *node)
{
	return (*(int *)node->content);
}

int	sort_optimize_cost(int pos, t_stk *stack, t_cnd *cands)
{
	cands->rots_a = pos;
	if (pos > stack->size / 2)
		cands->rots_a = stack->size - pos;
	return (0);
}

int	sort_node_is_min(t_lists *nodes_test, t_stk *stack)
{
	t_list	*node;
	int		nb_test;

	nb_test = get_nb(nodes_test->first);
	node = stack->head;
	while (node)
	{
		if (nb_test > get_nb(node))
		{
			nodes_test->next = NULL;
			return (0);
		}
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
