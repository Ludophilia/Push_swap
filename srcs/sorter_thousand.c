/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_thousand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:43:41 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/23 17:33:02 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort500_update_nodecost(t_list *nodas[2], t_list *nodb,
int nodecost[5])
{
	if (!nodas[1] && *(int *)nodb->content < *(int *)nodas[0]->content)
	{
		nodecost[0] = *(int *)nodas[0]->content;
		nodecost[1] = *(int *)nodb->content;
		nodecost[4] = nodecost[2] + nodecost[3];
	}
	else if (nodas[1] && *(int *)nodb->content > *(int *)nodas[0]->content
		&& *(int *)nodb->content < *(int *)nodas[1]->content)
	{
		nodecost[0] = *(int *)nodas[1]->content;
		nodecost[1] = *(int *)nodb->content;
		nodecost[4] = nodecost[2] + nodecost[3];
	}
}

static void	sort500_update_costs_for_b(t_stk **stacks, t_list *noda,
t_list *noda_next, int nodecost[5])
{
	t_list	*nodas[2];
	t_list	*nodb;
	int		j;

	j = -1;
	nodb = *stacks[1]->head;
	nodas[0] = noda;
	nodas[1] = noda_next;
	while (nodb && ++j > -1)
	{
		nodecost[3] = j;
		if (j > stacks[1]->size / 2)
			nodecost[3] = stacks[1]->size - j;
		if (nodecost[2] + nodecost[3] < nodecost[4])
			sort500_update_nodecost(nodas, nodb, nodecost);
		nodb = nodb->next;
	}
}

static void	sort500_search_candidates(t_stk **stacks, int nodecost[5])
{
	t_list	*noda[2];
	int		i;

	nodecost[0] = INT_MAX;
	nodecost[1] = INT_MAX;
	nodecost[4] = INT_MAX;
	noda[0] = *stacks[0]->head;
	noda[1] = noda[0]->next;
	i = -1;
	while (noda[0] && noda[1] && nodecost[4] != 0 && ++i > -1)
	{
		nodecost[2] = i;
		if (i > stacks[0]->size / 2)
			nodecost[2] = stacks[0]->size - i;
		if (stkmgr_is_min(*(int *)noda[0]->content, stacks[0]))
			sort500_update_costs_for_b(stacks, noda[0], NULL, nodecost);
		if (*(int *)noda[0]->content + 1 != *(int *)noda[1]->content)
			sort500_update_costs_for_b(stacks, noda[0], noda[1], nodecost);
		noda[0] = noda[0]->next;
		if (noda[0] && noda[0]->next)
			noda[1] = noda[0]->next;
		else if (noda[0] && noda[0]->next == NULL)
			noda[1] = *stacks[0]->head;
	}
}

static int	sort500_insertion_sort(t_stk **stacks, t_list **instrs)
{
	int	a_target[2];
	int	b_target[2];
	int	nodecost[5];

	while (stacks[1]->size != 0)
	{
		sort500_search_candidates(stacks, nodecost);
		a_target[0] = nodecost[0];
		b_target[0] = nodecost[1];
		a_target[1] = sort_get_nbpos(a_target[0], stacks[0]);
		b_target[1] = sort_get_nbpos(b_target[0], stacks[1]);
		if (a_target[1] == -1 || b_target[1] == -1)
			return (-1);
		if (sort_rotate_stk(a_target, stacks[0], instrs) == -1
			|| sort_rotate_stk(b_target, stacks[1], instrs) == -1
			|| game_push(stacks[1], stacks[0], instrs) == -1)
			return (-1);
	}
	if (sort_reset_stk(stacks[0], instrs) == -1)
		return (-1);
	return (0);
}

int	sort_over_100nbs(t_stk **stacks, int divider, t_list **instrs)
{
	if (sort100_presort(stacks, divider, instrs) == -1
		|| sort_upto_3nbs(stacks[0], instrs) == -1
		|| sort500_insertion_sort(stacks, instrs) == -1)
		return (-1);
	return (0);
}
