/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmgr_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:06:28 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/15 13:45:40 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stkmgr_stack_is_sorted(t_stk *stack, int order)
{
	int		i;
	int		prev;
	int		nb;
	t_list	*current;

	current = stack->head;
	i = -1;
	while (current)
	{
		nb = *(int *)current->content;
		if (++i > 0
			&& ((order == DIR_STRAIGHT && prev > nb)
				|| (order == DIR_REVERSE && prev < nb)))
				return (0);
		prev = *(int *)current->content;
		current = current->next;
	}
	return (1);
}

// void	stkmgr_get_minimum(int min[2], t_stk *stack)
// {
// 	t_list	*nodes;
// 	int		i;

// 	min[0] = INT_MAX;
// 	min[1] = -1;
// 	nodes = *stack->head;
// 	i = 0;
// 	while (nodes)
// 	{
// 		if (*(int *)nodes->content < min[0])
// 		{
// 			min[0] = *(int *)nodes->content;
// 			min[1] = i;
// 		}
// 		i++;
// 		nodes = nodes->next;
// 	}
// }

// int	stkmgr_is_min(int nb, t_stk *stack)
// {
// 	t_list	*node;

// 	node = *stack->head;
// 	while (node)
// 	{
// 		if (nb > *(int *)node->content)
// 			return (0);
// 		node = node->next;
// 	}
// 	return (1);
// }
