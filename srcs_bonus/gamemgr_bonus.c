/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamemgr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:44:46 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/11 18:04:26 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static t_list	*gameinst_lstseclast(t_list *lst)
{
	while (lst)
	{
		if (lst->next != NULL && lst->next->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	gameinst_push(t_stk *from_stack, t_stk *to_stack)
{
	t_list	*from_node;

	if (from_stack->size == 0)
		return (0);
	from_node = stkmgr_stack_pop(from_stack);
	if (from_node == NULL)
		return (-1);
	if (to_stack->head == NULL)
		*to_stack->head = from_node;
	else
		ft_lstadd_front(to_stack->head, from_node);
	to_stack->size++;
	return (0);
}

int	gameinst_swap(t_stk *stack0, t_stk *stack1)
{
	t_stk	**stacks;
	t_list	*nodes[2];
	int		i;

	stacks = (t_stk *[3]){stack0, stack1, 0};
	i = -1;
	while (stacks[++i])
	{
		if (*stacks[i]->head && (*stacks[i]->head)->next)
		{
			nodes[0] = *stacks[i]->head;
			nodes[1] = (*stacks[i]->head)->next;
			nodes[0]->next = nodes[1]->next;
			nodes[1]->next = nodes[0];
			*stacks[i]->head = nodes[1];
		}
		else
			stacks[i] = 0;
	}
	return (0);
}

int	gameinst_rotate(t_stk *stack0, t_stk *stack1)
{
	t_stk	**stacks;
	t_list	*nodes[2];
	int		i;

	stacks = (t_stk *[3]){stack0, stack1, 0};
	i = -1;
	while (stacks[++i])
	{
		if (stacks[i]->size > 1)
		{
			nodes[0] = *stacks[i]->head;
			nodes[1] = ft_lstlast(*stacks[i]->head);
			*stacks[i]->head = nodes[0]->next;
			nodes[1]->next = nodes[0];
			nodes[0]->next = NULL;
		}
		else
			stacks[i] = 0;
	}
	return (0);
}

int	gameinst_rev_rotate(t_stk *stack0, t_stk *stack1)
{
	t_stk	**stacks;
	t_list	*nodes[2];
	int		i;

	stacks = (t_stk *[3]){stack0, stack1, 0};
	i = -1;
	while (stacks[++i])
	{
		if (stacks[i]->size > 1)
		{
			nodes[0] = gameinst_lstseclast(*stacks[i]->head);
			nodes[1] = ft_lstlast(*stacks[i]->head);
			nodes[1]->next = *stacks[i]->head;
			*stacks[i]->head = nodes[1];
			nodes[0]->next = NULL;
		}
		else
			stacks[i] = 0;
	}
	return (0);
}
