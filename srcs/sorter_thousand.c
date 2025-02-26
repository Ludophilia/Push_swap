/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_thousand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:43:41 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/26 22:36:07 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	sort500_node_is_min(t_lists *nodes_test, t_stk *stack)
{
	t_list	*node;
	t_list	*node_test;
	int		nb_test;

	node_test = *(int *)nodes_test->node->content;
	node = stack->head;
	while (node)
	{
		if (nb_test > *(int *)node->content)
		{
			nodes_test->next = NULL;
			return (0);
		}
		node = node->next;
	}
	return (1);
}

// A function to get list nb, please
static int	sort500_update_nodecost(t_lists *nodes_a, t_list *node_b,
	t_cost *costs)
{
	if (nodes_a->next == NULL && *(int *)node_b->content < *(int *)nodes_a->next->content)
	{
		costs->nba = *(int *)nodes_a->next->content;
		costs->nbb = *(int *)node_b->content;
	}
	else if (nodes_a->next && *(int *)node_b->content > *(int *)nodes_a->next->content
		&& *(int *)node_b->content < *(int *)nodes_a->next->content)
	{
		costs->nba = *(int *)nodes_a->next->content;
		costs->nbb = *(int *)node_b->content;
	}
	costs->rots_tt = costs->rots_a + costs->rots_b;
	return (0);
}

static int	sort500_update_costs_for_b(t_lists *nodes_a, t_stk *stack_b,
	t_cost *costs)
{
	t_list	*node_b;
	int		pos_b;

	pos_b = -1;
	node_b = stack_b->head;
	while (node_b)
	{
		costs->rots_b = ++pos_b;
		if (pos_b > stack_b->size / 2)
			costs->rots_b = stack_b->size - pos_b;
		if (costs->rots_a + costs->rots_b < costs->rots_tt)
			sort500_update_nodecost(nodes_a, node_b, costs);
		node_b = node_b->next;
	}
	return (0);
}

// Wow, c'est dur a lire...
static t_cost	sort500_search_candidates(t_stk *stack_a, t_stk *stack_b)
{
	t_cost	costs;
	t_lists	nodes_a;
	int		pos_a;

	costs = (t_cost){.nba = LLONG_MAX, .nbb = LLONG_MAX, .rots_tt = LLONG_MAX};
	nodes_a = (t_lists){.node = stack_a->head, .next = stack_a->head->next};
	nodes_a.node_nb = *(int *)nodes_a.node->content;
	nodes_a.next_nb = *(int *)nodes_a.next->content;
	pos_a = -1;
	while (nodes_a.node && costs.rots_tt != 0)
	{
		costs.rots_a = ++pos_a;
		if (pos_a > stack_a->size / 2)
			costs.rots_a = stack_a->size - pos_a;
		if (sort500_node_is_min(nodes_a.node, stack_a)
			|| nodes_a.node_nb + 1 != nodes_a.next_nb) // a function for a number
			sort500_update_costs_for_b(&nodes_a, stack_b, &costs);
		nodes_a.node = nodes_a.node->next;
		if (nodes_a.node && nodes_a.node->next)
			nodes_a.next = nodes_a.node->next;
		else if (nodes_a.node && nodes_a.node->next == NULL)
			nodes_a.next = stack_a->head;
	}
	return (costs);
}	

static int	sort500_insertion_sort(t_stk *stack_a, t_stk *stack_b, int divider,
	t_psw *game)
{
	t_pnbr	nba;
	t_pnbr	nbb;
	t_cost	costs;

	while (stack_b->size)
	{
		costs = sort500_search_candidates(stack_a, stack_b);
		nba.nb = costs.nba;
		nbb.nb = costs.nbb;
		if (sort_get_nb_pos(&nba, stack_a) == -1 
			|| sort_get_nb_pos(&nbb, stack_b) == -1
			|| sort_rotate_stk(&nba, stack_a, game) == -1
			|| sort_rotate_stk(&nbb, stack_b, game) == -1
			|| game_push(stack_b, stack_a, game) == -1)
			return (-1);
	}
	if (sort_reset_stk(stack_a, game) == -1)
		return (-1);
	return (0);
}

// 27/02 - Refactor again.
// We need a function to easily get the number from a stack->head or a t_list.
int	sort_over_100nbs(t_stk *stack_a, t_stk *stack_b, int divider, t_psw *game)
{
	if (sort100_presort(stack_a, divider, game) == -1
		|| sort_upto_3nbs(stack_a, game) == -1
		|| sort500_insertion_sort(stack_a, stack_b, divider, game) == -1)
		return (-1);
	return (0);
}
