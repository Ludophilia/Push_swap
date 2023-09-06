/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamemgr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:05:41 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/06 17:02:01 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamemgr.h"

int	game_push(t_stk *from_stack, t_stk *to_stack, t_list **instr_head)
{
	t_list	*from_node;

	from_node = stkmgr_stack_pop(from_stack);
	if (from_node == NULL)
		return (-1);
	if (to_stack->head == NULL)
		*to_stack->head = from_node;
	else
		ft_lstadd_front(to_stack->head, from_node);
	to_stack->size++;
	if (game_store_instr("p", to_stack->name, instr_head) == -1)
		return (-1);
	return (0);
}

int	game_swap(t_stk *stack0, t_stk *stack1, t_list **instr_head)
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
	if (stacks[0] || stacks[1])
	{
		if (game_choose_instr("s", stacks[0], stacks[1], instr_head) == -1)
			return (-1);
	}
	return (0);
}

int	game_rotate(t_stk *stack0, t_stk *stack1, t_list **instr_head)
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
	if (stacks[0] || stacks[1])
	{
		if (game_choose_instr("r", stacks[0], stacks[1], instr_head) == -1)
			return (-1);
	}
	return (0);
}

int	game_rev_rotate(t_stk *stack0, t_stk *stack1, t_list **instr_head)
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
			nodes[0] = game_lstseclast(*stacks[i]->head);
			nodes[1] = ft_lstlast(*stacks[i]->head);
			nodes[1]->next = *stacks[i]->head;
			*stacks[i]->head = nodes[1];
			nodes[0]->next = NULL;
		}
		else
			stacks[i] = 0;
	}
	if (stacks[0] || stacks[1])
	{
		if (game_choose_instr("rr", stacks[0], stacks[1], instr_head) == -1)
			return (-1);
	}
	return (0);
}
