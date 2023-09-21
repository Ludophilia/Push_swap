/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/21 19:43:20 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	sort_choose_algorithm(t_stk **stacks, t_list **instrs)
{
	if (stacks[0]->size <= 5
		&& sort_upto_5nbs(stacks, instrs) == -1)
		return (-1);
	else if (stacks[0]->size > 5 && stacks[0]->size <= 75
		&& sort_upto_100nbs(stacks, 2, instrs) == -1)
		return (-1);
	else if (stacks[0]->size > 75 && stacks[0]->size <= 250
		&& sort_upto_100nbs(stacks, 4, instrs) == -1)
		return (-1);
	else if (stacks[0]->size > 250
		&& sort_upto_100nbs(stacks, 9, instrs) == -1)
		return (-1);
	return (0);
}

// - The idea: test every possible path from nba and UPDATE each time the costs 
// in the arr of uint32_t (nba->content, totalcost) if inferior 

//		- define arr of uint32_t (nba->content, totalcost)
//		- Iterate on stack a.
//			- If (i == 0) and stack b is not empty, try updatecost_from_a from
//			 the first node.
//			- else, try updatecost_from_a on every nba such as:
//			nba->content + 1 != nba->next->content

//		- Return the cheapest nodeA?

// - Procedure: updatecost_from_a(nodeA, nodeA_next, *totalcost)
//	- Iterate on stack b.
//	- Find the CHEAPEST nbb such as: 
//		- nbb > nodeA && nodeA_next > nbb (if nodeA_next) (store nodeA_next 
//		in nodecost)
//		- nbb < nodeA (else) (store nodeA in nodecost)
//		- 

// Updating of nodecost should be done only and only if...
// new_cost (i + stackbcost) < nodecost[1]
void	update_costs_from_a(t_stk **stacks, t_list *noda, t_list *noda_next,
int **nodecost)
{
	t_list	*nodb;

	nodb = stacks[1]->head;
	while (nodb)
	{
		nodb = nodb->next;
	}
}

// nodecost may be redifined outside...
void	search_candids_stkab(t_stk **stacks, t_list **instrs)
{
	int		nodecost[3];
	t_list	*noda[2];
	int		i;

	nodecost[0] = 0x7FFFFFFF;
	nodecost[2] = 0x7FFFFFFF;
	noda[0] = *stacks[0]->head;
	noda[1] = noda[0]->next;
	i = -1;
	while (noda[0] && noda[1] && (++i > -1))
	{
		nodecost[1] = i;
		if (i >= stacks[0]->size / 2)
			nodecost[1] = stacks[0]->size - i;
		if (i == 0 && stacks[1]->size != 0)
			update_costs_from_a(stacks, noda[0], NULL, nodecost);
		else if (*(int *)noda[0]->content + 1 != *(int *)noda[1]->content)
			update_costs_from_a(stacks, noda[0], noda[1], nodecost);
		noda[0] = noda[0]->next;
		if (noda[0])
			noda[1] = noda[0]->next;
	}
}

// - 10 IQ Insertion Sort.
// 	- [ ] Select a number in stack a nba, and a number in stack b nbb.
// 	this number should be the cheapest possible in terms of rotations
// 	while making insertion sort possible. 
// 	- [ ] Rotate the stacks in the cheapest fashion.
// 	- [ ] Push from b to a.
//	- [ ] Repeat until stack a is empty
//	- [ ] Don't forget smart rotate in the end :)
int	sort500_smart_insertion_sort(t_stk **stacks, t_list **instrs)
{
	//  
	// 
	// 
}

int	sort_over_100nbs(t_stk **stacks, int divider, t_list **instrs)
{
	if (sort100_presort(stacks, divider, instrs) == -1
		|| sort_upto_3nbs(stacks[0], instrs) == -1
		|| sort500_smart_insertion_sort(stacks, instrs) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stk	*stacks[3];
	t_list	*instrs[1];
	int		init_status;

	init_status = cli_project_init(argc, argv, stacks, instrs);
	if (init_status == 0)
		return (0);
	if (init_status == -1 && ft_dprintf(2, "Error\n"))
		return (1);
	if (sort_choose_algorithm(stacks, instrs) == -1
		|| game_opti_instrs(instrs) == -1)
	{
		stkmgr_free_ressources(stacks, instrs);
		return (1);
	}
	game_print_instrs(*instrs);
	stkmgr_free_ressources(stacks, instrs);
	return (0);
}

// 100 -> 699 max ; 500 -> 5499 max.

// static void	tmp_traverse_stack(t_stk *stack)
// {
// 	t_list	*node;

// 	ft_dprintf(2, "Name: stack %s; stack size: %i\n",
// 		stack->name, stack->size);
// 	if (stack->size == 0)
// 	{
// 		ft_printf("[empty]\n");
// 		return ;
// 	}
// 	node = *stack->head;
// 	while (node != NULL)
// 	{
// 		ft_printf("%i\n", *(int *)node->content);
// 		node = node->next;
// 	}
// }