/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_thousand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:43:41 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/23 18:35:58 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

static void	sort500_update_nodecost(t_list *noda, t_list *noda_next,
t_list *nodb, int nodecost[5])
{
	if (!noda_next && *(int *)nodb->content < *(int *)noda->content)
	{
		nodecost[0] = *(int *)noda->content;
		nodecost[1] = *(int *)nodb->content;
		nodecost[4] = nodecost[2] + nodecost[3];
	}
	else if (noda_next && *(int *)nodb->content > *(int *)noda->content
		&& *(int *)nodb->content < *(int *)noda_next->content)
	{
		nodecost[0] = *(int *)noda_next->content;
		nodecost[1] = *(int *)nodb->content;
		nodecost[4] = nodecost[2] + nodecost[3];
	}
}

static void	sort500_update_costs_from_a(t_stk **stacks, t_list *noda,
t_list *noda_next, int nodecost[5])
{
	int		j;
	t_list	*nodb;

	j = -1;
	nodb = *stacks[1]->head;
	while (nodb && (++j > -1))
	{
		nodecost[3] = j;
		if (j >= stacks[1]->size / 2)
			nodecost[3] = stacks[1]->size - j;
		if (nodecost[2] + nodecost[3] < nodecost[4])
			sort500_update_nodecost(noda, noda_next, nodb, nodecost);
		nodb = nodb->next;
	}
}

// Will it always work?
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
	while (noda[0] && noda[1] && (++i > -1))
	{
		nodecost[2] = i;
		if (i >= stacks[0]->size / 2)
			nodecost[2] = stacks[0]->size - i;
		if (i == 0 && stacks[1]->size != 0)
			sort500_update_costs_from_a(stacks, noda[0], NULL, nodecost);
		else if (*(int *)noda[0]->content + 1 != *(int *)noda[1]->content)
			sort500_update_costs_from_a(stacks, noda[0], noda[1], nodecost);
		noda[0] = noda[0]->next;
		if (noda[0])
			noda[1] = noda[0]->next;
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
		a_target[1] = sort_get_pos_stk(a_target[0], stacks[0]);
		b_target[1] = sort_get_pos_stk(b_target[0], stacks[1]);
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
