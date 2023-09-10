/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/10 23:48:58 by jgermany         ###   ########.fr       */
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

// int	smart_reset(t_stk *stackA, t_stk *stackB, t_list **instr)

int	sort_smart_rotate(t_stk *stackA, t_stk *stackB, t_list **instr)
{
	t_list*	nodes[2];
	int		fwd;
	int		i;
	int		candidate[2];

	nodes[0] = *stackA->head;
	nodes[1] = *stackB->head;
	fwd = 0;
	i = 0;
	candidate[0] = 0x7FFFFFFF;
	candidate[1] = -1;
	while (nodes[0])
	{
		// if (*(int *)nodes[0]->content == 1 && *(int *)nodes[1]->content == 0)
		// {
		// 	candidate = ij[0];
		// 	break ;
		// }
		if (*(int *)nodes[0]->content > *(int *)nodes[1]->content
			&& *(int *)nodes[0]->content < candidate[0])
		{
				candidate[0] = *(int *)nodes[0]->content;
				candidate[1] = i;
		}
		nodes[0] = nodes[0]->next;
		i++;
	}
	// ft_printf("candidate = %i, position = %i\n", candidate[0], candidate[1]);
	if (candidate[0] == 0x7FFFFFFF)
		return (0);
	if (candidate[1] < stackA->size / 2)
		fwd = 1;
	while (*(int *)(*stackA->head)->content != candidate[0])
	{
		if (fwd && game_rotate(stackA, 0, instr) == -1)
			return (-1);
		else if (!fwd && game_rev_rotate(stackA, 0, instr) == -1)
			return (-1);
	}
	return (0);
}

int	sort_insertion_sort(t_stk *stackA, t_stk *stackB, t_list **instrs)
{
	// t_list	*nodeB;

	// nodeB = *stackB->head;
	// if (sort_smart_rotate(stackA, stackB, instrs) == -1
	// 	|| game_push(stackB, stackA, instrs) == -1)
	// 	return (-1);
	while (*stackB->head)
	{
		if (sort_smart_rotate(stackA, stackB, instrs) == -1
			|| game_push(stackB, stackA, instrs) == -1)
			return (-1);
	}
	return (0);
	// smart_rotate(stackA, stackB, instrs);
	// game_push(stackB, stackA, instrs);

	// smart_rotate(stackA, stackB, instrs);
	// game_push(stackB, stackA, instrs);

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
	tmp_traverse_stack(stackA);
	tmp_traverse_stack(stackB);

	sort_insertion_sort(stackA, stackB, instrs);
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

	sort_upto_5nbs(stacks[0], stacks[1], instr_head);

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
