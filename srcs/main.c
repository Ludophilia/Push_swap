/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/09 14:48:48 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	tmp_traverse_stack(t_stk *stack)
{
	t_list	*node;

	ft_dprintf(2, "Name: stack %s; stack size: %i\n",
		stack->name, stack->size);
	if (stack->size == 0)
	{
		ft_printf("[empty]\n");
		return ;
	}
	node = *stack->head;
	while (node != NULL)
	{
		ft_printf("%i\n", *(int *)node->content);
		node = node->next;
	}
}

static void	tmp_traverse_instructions(t_list *start)
{
	ft_printf("Instructions:\n");
	if (start == NULL)
		ft_printf("[empty]\n");
	while (start)
	{
		ft_printf("%s\n", (char *)start->content);
		start = start->next;
	}
}

int	smart_rotate(t_stk *stackA, t_stk *stackB, t_list **instr)
{
	// 1/ SMART ROTATE STACK A 
	//	Need to know what's on top of stack b.
	//	and what's on top of stack a.
	
	// 	-> [a] 0 15 30 [b] 4 3
	// 	(ra)
	// 	-> [a] 15 30 0 [b] 4 3 (first one who meets: peek(a) > peek(b)
	// 	in a sorted list)

	// Need to know in which order the stack need to be rotated. 
	// size: 4. if i < 2 or 4/2, use ra/rb else rra/rrb
	
}

int	sort_insertion_sort(t_stk *stackA, t_stk *stackB, t_list **instrs)
{
	
}

// 5 nbs;
int	sort_upto_5nbs(t_stk *stackA, t_stk *stackB, t_list **instrs)
{
	if (stkmgr_stack_is_sorted(stackA, 0) || (stackA->size > 5))
		return (0);
	if (game_push(stackA, stackB, instrs) == -1
		|| game_push(stackA, stackB, instrs) == -1)
		return (-1);
	if (sort_upto_3nbs(stackA, instrs) == -1)
		return (-1);
	if (sort_2nbs(stackB, instrs) == -1)
		return (-1);
	// insertion sort:
		// - smart rotate (rotate stack in a direction or another till 
		// a condition is met)
		// - push to a till stack a is empty (will be ajusted)
		// - (smart) rotate stack b 'till 0 the top of the stack is 0.
	return (0);
}


// 6/09 - I still want a vizualizer and a tester.
// 7/09 - This thing has to be tested...
int	main(int argc, char **argv)
{
	t_stk	*stacks[3];
	t_list	*instr_head[1];
	int		init_status;

	init_status = cli_project_init(argc, argv, stacks, instr_head);
	if (init_status == 0)
		return (0);
	if (init_status == -1)
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	tmp_traverse_stack(stacks[0]);
	tmp_traverse_stack(stacks[1]);

	sort_upto_3nbs(stacks[0], instr_head);

	// (void)tmp_traverse_instructions;
	// sort_upto_5nbs(stacks[0], stacks[1], instr_head);
	// sort_upto_3nbs(stacks[0], instr_head);

	// game_push(stacks[0], stacks[1], instr_head);
	// game_push(stacks[0], stacks[1], instr_head);

	// sort_2nbs(stacks[0], instr_head);
	// sort_2nbs(stacks[1], instr_head);

	tmp_traverse_instructions(*instr_head);
	tmp_traverse_stack(stacks[0]);
	tmp_traverse_stack(stacks[1]);
	stkmgr_stack_free(stacks[0]);
	stkmgr_stack_free(stacks[1]);
	ft_lstclear(instr_head, free);
	return (0);
}
