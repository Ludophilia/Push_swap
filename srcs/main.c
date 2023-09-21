/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/21 14:55:33 by jgermany         ###   ########.fr       */
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

//		- Procedure: updatecost_from_a(node, node_next, *totalcost)
//			- Iterate on stack b.
//			- Find the CHEAPEST nbb such as nbb > node && node_next > nbb.

//		- Return the cheapest nodeA?
void	search_candidates_stkab(t_stk **stacks, t_list **instrs)
{
	uint32_t stackcost[2];
}

// -1 IQ Insertion Sort.
// 	- Select a number in stack a nba, and a number in stack b nbb.
// 	this number should be the cheapest possible in terms of rotations
// 	while making insertion sort possible. 
// 	- Rotate the stacks in the cheapest fashion.
// 	- Push from b to a.
//	- Repeat until stack a is empty
//	- Don't forget smart rotate :)
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