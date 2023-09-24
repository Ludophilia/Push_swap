/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmgr_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:06:28 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/24 17:26:04 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackmgr.h"

int	stkmgr_stack_is_sorted(t_stk *stack, int rev)
{
	int		i;
	int		last[2];
	t_list	*current;

	current = *stack->head;
	i = -1;
	while (current)
	{
		last[1] = *(int *)current->content;
		if (++i > 0)
			if ((!rev && (last[0] > last[1])) || (rev && (last[0] < last[1])))
				return (0);
		last[0] = *(int *)current->content;
		current = current->next;
	}
	return (1);
}

void	stkmgr_stack_free(t_stk *stack)
{
	ft_lstclear(stack->head, free);
	free(stack->head);
	free(stack);
}

void	stkmgr_free_ressources(t_stk **stacks, t_list **instrs)
{
	stkmgr_stack_free(stacks[0]);
	stkmgr_stack_free(stacks[1]);
	ft_lstclear(instrs, free);
}

void	stkmgr_get_minimum(int min[2], t_stk *stack)
{
	t_list	*nodes;
	int		i;

	min[0] = INT_MAX;
	min[1] = -1;
	nodes = *stack->head;
	i = 0;
	while (nodes)
	{
		if (*(int *)nodes->content < min[0])
		{
			min[0] = *(int *)nodes->content;
			min[1] = i;
		}
		i++;
		nodes = nodes->next;
	}
}

int	stkmgr_is_min(int nb, t_stk *stack)
{
	t_list	*node;

	node = *stack->head;
	while (node)
	{
		if (nb > *(int *)node->content)
			return (0);
		node = node->next;
	}
	return (1);
}
