/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_thousand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:43:41 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/27 21:32:33 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	sort500_update_candidates(t_lists *nodes_a, t_list *node_b,
	t_cnd *cands)
{
	if (nodes_a->next == NULL && get_nb(node_b) < get_nb(nodes_a->first))
	{
		cands->nba = get_nb(nodes_a->next);
		cands->nbb = get_nb(node_b);
		cands->rots_tt = cands->rots_a + cands->rots_b;
	}
	else if (nodes_a->next && get_nb(node_b) > get_nb(nodes_a->first)
		&& get_nb(node_b) < get_nb(nodes_a->next))
	{
		cands->nba = get_nb(nodes_a->next);
		cands->nbb = get_nb(node_b);
		cands->rots_tt = cands->rots_a + cands->rots_b;
	}
	return (0);
}

static int	sort500_search_candidates_in_b(t_lists *nodes_a, t_stk *stack_b,
	t_cnd *cands)
{
	t_list	*node_b;
	int		pos_b;

	pos_b = -1;
	node_b = stack_b->head;
	while (node_b)
	{
		sort_optimize_cost(++pos_b, stack_b, &cands);
		if (cands->rots_a + cands->rots_b < cands->rots_tt)
			sort500_update_candidates(nodes_a, node_b, cands);
		node_b = node_b->next;
	}
	return (0);
}

static t_cnd	sort500_search_candidates(t_stk *stack_a, t_stk *stack_b)
{
	t_cnd	cands;
	t_lists	nodes_a;
	int		pos_a;

	cands = (t_cnd){.nba = LLONG_MAX, .nbb = LLONG_MAX, .rots_tt = LLONG_MAX};
	nodes_a = (t_lists){.first = stack_a->head, .next = stack_a->head->next};
	pos_a = -1;
	while (nodes_a.first && cands.rots_tt != 0)
	{
		sort_optimize_cost(++pos_a, stack_a, &cands);
		if (sort_node_is_min(&nodes_a, stack_a)
			|| get_nb(nodes_a.first) + 1 != get_nb(nodes_a.next))
			sort500_search_candidates_in_b(&nodes_a, stack_b, &cands);
		nodes_a.first = nodes_a.next;
		if (nodes_a.first && nodes_a.first->next)
			nodes_a.next = nodes_a.first->next;
		else if (nodes_a.first && nodes_a.first->next == NULL)
			nodes_a.next = stack_a->head;
	}
	return (cands);
}	

static int	sort500_insertion_sort(t_stk *stack_a, t_stk *stack_b, int divider,
	t_psw *game)
{
	t_pnbr	nba;
	t_pnbr	nbb;
	t_cnd	cands;

	while (stack_b->size)
	{
		cands = sort500_search_candidates(stack_a, stack_b);
		nba.nb = cands.nba;
		nbb.nb = cands.nbb;
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

int	sort_over_100nbs(t_stk *stack_a, t_stk *stack_b, int divider, t_psw *game)
{
	if (sort100_presort(stack_a, divider, game) == -1
		|| sort_upto_3nbs(stack_a, game) == -1
		|| sort500_insertion_sort(stack_a, stack_b, divider, game) == -1)
		return (-1);
	return (0);
}
