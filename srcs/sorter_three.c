/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:05:39 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/09 13:07:33 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

void	sort_get_data_from_stack(int *nbs, int *minmax, t_stk *stack)
{
	t_list	*node;
	int		i;

	*(long *)minmax = 0x7FFFFFFFL;
	node = *stack->head;
	i = -1;
	while (++i < stack->size)
	{
		nbs[i] = *(int *)node->content;
		if (nbs[i] < minmax[0])
			minmax[0] = nbs[i];
		if (nbs[i] > minmax[1])
			minmax[1] = nbs[i];
		node = node->next;
	}
}

int	sort_2nbs(t_stk *stack, t_list **instrs)
{
	int	error_status;
	int	nbs[3];
	int	minmax[2];

	error_status = 0;
	sort_get_data_from_stack(nbs, minmax, stack);
	if (*stack->name == 'a' && minmax[0] == nbs[1] && minmax[1] == nbs[0])
		error_status = game_swap(stack, 0, instrs) == -1;
	else if (*stack->name == 'b' && minmax[0] == nbs[0] && minmax[1] == nbs[1])
		error_status = game_swap(stack, 0, instrs) == -1;
	if (error_status)
		return (-1);
	return (0);
}

int	sort_3nbs(t_stk *stackA, t_list **instrs)
{
	int	error_status;
	int	nbs[3];
	int	minmax[2];

	error_status = 0;
	sort_get_data_from_stack(nbs, minmax, stackA);
	if (minmax[0] == nbs[0] && minmax[1] == nbs[1])
		error_status = (game_rev_rotate(stackA, 0, instrs) == -1
				|| game_swap(stackA, 0, instrs) == -1);
	else if (minmax[0] == nbs[2] && minmax[1] == nbs[1])
		error_status = game_rev_rotate(stackA, 0, instrs) == -1;
	else if (minmax[0] == nbs[1] && minmax[1] == nbs[2])
		error_status = game_swap(stackA, 0, instrs) == -1;
	else if (minmax[0] == nbs[1] && minmax[1] == nbs[0])
		error_status = game_rotate(stackA, 0, instrs) == -1;
	else if (minmax[0] == nbs[2] && minmax[1] == nbs[0])
		error_status = (game_swap(stackA, 0, instrs) == -1
				|| game_rev_rotate(stackA, 0, instrs) == -1);
	if (error_status)
		return (-1);
	return (0);
}

int	sort_upto_3nbs(t_stk *stack, t_list **instrs)
{
	if (stkmgr_stack_is_sorted(stack, 0) || stack->size > 3)
		return (0);
	if (stack->size == 2 && sort_2nbs(stack, instrs) == -1)
		return (-1);
	else if (stack->size == 3 && sort_3nbs(stack, instrs) == -1)
		return (-1);
	return (0);
}
