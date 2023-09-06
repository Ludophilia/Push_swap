/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/06 20:28:03 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "stackmgr.h"

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
		ft_printf("(%s)\n", (char *)start->content);
		start = start->next;
	}
}

// 6/09 - I still want a vizualizer and a tester.
// 7/09 - This thing has to be tested...
int	sort_compute_instr(int *nbs, int *minmax, t_stk *stack, t_list **instrs)
{
	if (minmax[0] == nbs[0] && minmax[1] == nbs[1])
	{
		if (game_rev_rotate(stack, 0, instrs) == -1
			|| game_swap(stack, 0, instrs) == -1)
			return (-1);
	}
	else if (minmax[0] == nbs[2] && minmax[1] == nbs[1])
		if (game_rev_rotate(stack, 0, instrs) == -1)
			return (-1);
	else if (minmax[0] == nbs[1] && minmax[1] == nbs[2])
		if (game_swap(stack, 0, instrs) == -1)
			return (-1);
	else if (minmax[0] == nbs[1] && minmax[1] == nbs[0])
		if (game_rotate(stack, 0, instrs) == -1)
			return (-1);
	else if (minmax[0] == nbs[2] && minmax[1] == nbs[0])
	{
		if (game_swap(stack, 0, instrs) == -1
			|| game_rev_rotate(stack, 0, instrs) == -1)
			return (-1);
	}
	return (0);
}

int	sort_three_nbs(t_stk *stack, t_list **instrs)
{
	int		nbs[3];
	t_list	*node;
	int		i;
	int		minmax[2];

	if (stkmgr_stack_is_sorted(stack, 0) || (stack->size != 3))
		return ;
	i = -1;
	minmax[0] = 0x7FFFFFFF;
	minmax[1] = -1;
	node = *stack->head;
	while (++i < stack->size)
	{
		nbs[i] = *(int *)node->content;
		if (nbs[i] < minmax[0])
			minmax[0] = nbs[i];
		if (nbs[i] > minmax[1])
			minmax[1] = nbs[i];
		node = node->next;
	}
	if (sort_compute_instr(nbs, minmax, stack, instrs) == -1)
		return (-1);
	return (0);
}

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
	// tmp_traverse_stack(stacks[0]);
	// tmp_traverse_stack(stacks[1]);
	// (void)tmp_traverse_instructions;
	// tmp_traverse_stack(stacks[0]);
	// tmp_traverse_stack(stacks[1]);
	stkmgr_stack_free(stacks[0]);
	stkmgr_stack_free(stacks[1]);
	ft_lstclear(instr_head, free);
	return (0);
}
