/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:46:10 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/16 18:41:23 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// int	sort_get_pos_stk(int target, t_stk *stack)
// {
// 	t_list	*node;
// 	int		i;

// 	i = 0;
// 	node = *stack->head;
// 	while (node)
// 	{
// 		if (*(int *)node->content == target)
// 			return (i);
// 		i++;
// 		node = node->next;
// 	}
// 	return (-1);
// }

// int	sort_rotate_stk(int target[2], t_stk *stack, t_list **instrs)
// {
// 	int	fwd;

// 	fwd = 1;
// 	if (target[1] > stack->size / 2)
// 		fwd = 0;
// 	while (target[0] != *(int *)(*stack->head)->content)
// 	{
// 		if (fwd && game_rotate(stack, 0, instrs) == -1)
// 			return (-1);
// 		else if (!fwd && game_rev_rotate(stack, 0, instrs) == -1)
// 			return (-1);
// 	}
// 	return (0);
// }

// int	sort_reset_stk(t_stk *stack, t_list **instrs)
// {
// 	int		target[2];
// 	int		rev;

// 	rev = DIR_STRAIGHT;
// 	if (*stack->name == 'b')
// 		rev = DIR_REVERSE;
// 	if (stkmgr_stack_is_sorted(stack, rev))
// 		return (0);
// 	target[0] = 0;
// 	target[1] = sort_get_pos_stk(target[0], stack);
// 	if (target[1] == -1 || sort_rotate_stk(target, stack, instrs))
// 		return (-1);
// 	return (0);
// }

// 14/02 - Here we are...
int	sort_choose_algorithm(t_psw *game)
{
	if (game->stack_a.size <= 3
		&& sort_upto_3nbs(game->stack_a, &game) == -1)
		return (-1);
	// else if (game->stack_a.size > 3 && game->stack_a.size <= 5
	// 	&& sort_upto_5nbs(stacks, instrs) == -1)
	// 	return (-1);
	// else if (game->stack_a.size > 5 && game->stack_a.size <= 75
	// 	&& sort_upto_100nbs(stacks, 2, instrs) == -1)
	// 	return (-1);
	// else if (game->stack_a.size > 75 && game->stack_a.size <= 250
	// 	&& sort_upto_100nbs(stacks, 4, instrs) == -1)
	// 	return (-1);
	// else if (game->stack_a.size > 250
	// 	&& sort_over_100nbs(stacks, 9, instrs) == -1)
	// 	return (-1);
	return (0);
}
