/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_thousand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:43:41 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/28 17:30:24 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	sort1000_update_candidates(t_list *node_a, t_list *next_a,
	t_list *node_b, t_cnd *cands)
{
	if (next_a == NULL && get_nb(node_b) < get_nb(node_a))
	{
		cands->nba = get_nb(node_a);
		cands->nbb = get_nb(node_b);
		cands->rots_tt = cands->rots_a + cands->rots_b;
	}
	else if (next_a && get_nb(node_b) > get_nb(node_a)
		&& get_nb(node_b) < get_nb(next_a))
	{
		cands->nba = get_nb(next_a);
		cands->nbb = get_nb(node_b);
		cands->rots_tt = cands->rots_a + cands->rots_b;
	}
	return (0);
}

static int	sort1000_search_candidates_in_b(t_list *node_a, t_list *next_a,
	t_stk *stack_b, t_cnd *cands)
{
	t_list	*node_b;
	int		pos_b;

	pos_b = -1;
	node_b = stack_b->head;
	while (node_b)
	{
		sort_optimize_cost(++pos_b, stack_b, &cands->rots_b);
		if (cands->rots_a + cands->rots_b < cands->rots_tt)
			sort1000_update_candidates(node_a, next_a, node_b, cands);
		node_b = node_b->next;
	}
	return (0);
}

static t_cnd	sort1000_search_candidates(t_stk *stack_a, t_stk *stack_b)
{
	t_cnd	cands;
	t_list	*node_a;
	t_list	*next_a;
	int		pos_a;

	cands = (t_cnd){.nba = LLONG_MAX, .nbb = LLONG_MAX, .rots_tt = LLONG_MAX};
	node_a = stack_a->head;
	next_a = stack_a->head->next;
	pos_a = -1;
	while (node_a && cands.rots_tt > 1)
	{
		sort_optimize_cost(++pos_a, stack_a, &cands.rots_a);
		if (sort_node_is_smallest(node_a, stack_a))
			sort1000_search_candidates_in_b(node_a, NULL, stack_b, &cands);
		if (get_nb(node_a) + 1 != get_nb(next_a))
			sort1000_search_candidates_in_b(node_a, next_a, stack_b, &cands);
		node_a = node_a->next;
		if (node_a && node_a->next)
			next_a = node_a->next;
		else if (node_a && node_a->next == NULL)
			next_a = stack_a->head;
	}
	return (cands);
}	

static int	sort1000_insertion_sort(t_stk *stack_a, t_stk *stack_b, t_psw *game)
{
	t_cnd	cands;
	t_pnbr	nba;
	t_pnbr	nbb;

	while (stack_b->size)
	{
		cands = sort1000_search_candidates(stack_a, stack_b);
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
		|| sort1000_insertion_sort(stack_a, stack_b, game) == -1)
		return (-1);
	return (0);
}
