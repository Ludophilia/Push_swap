/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamemgr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:05:41 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/16 18:34:14 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_list	*game_lstseclast(t_list *lst)
{
	while (lst)
	{
		if (lst->next != NULL && lst->next->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	game_push(t_stk *from_stack, t_stk *to_stack, t_psw *game)
{
	t_list	*from_node;

	from_node = stkmgr_stack_pop(from_stack);
	if (from_node == NULL)
		return (-1);
	if (to_stack->head == NULL)
		to_stack->head = from_node;
	else
		ft_lstadd_front(&to_stack->head, from_node);
	to_stack->size++;
	if (game_store_instr("p", to_stack->name, game) == -1)
		return (-1);
	return (0);
}

int	game_swap(t_stk *stack0, t_stk *stack1, t_psw *game)
{
	t_stk	**stacks;
	t_list	*first;
	t_list	*second;
	void	*tmp;
	int		i;

	stacks = (t_stk *[3]){stack0, stack1, 0};
	i = -1;
	while (stacks[++i])
	{
		if (stacks[i]->head && (stacks[i]->head)->next)
		{
			first = stacks[i]->head;
			second = (stacks[i]->head)->next;
			tmp = first->content;
			first->content = second->content;
			second->content = tmp;
		}
		else
			stacks[i] = NULL;
	}
	if ((stacks[0] || stacks[1])
		&& game_choose_instr("s", stacks[0], stacks[1], game) == -1)
		return (-1);
	return (0);
}

int	game_rotate(t_stk *stack0, t_stk *stack1, t_psw *game)
{
	t_stk	**stacks;
	t_list	*first;
	t_list	*last;
	int		i;

	stacks = (t_stk *[3]){stack0, stack1, 0};
	i = -1;
	while (stacks[++i])
	{
		if (stacks[i]->size > 1)
		{
			first = stacks[i]->head;
			last = ft_lstlast(stacks[i]->head);
			stacks[i]->head = first->next;
			last->next = first;
			first->next = NULL;
		}
		else
			stacks[i] = NULL;
	}
	if ((stacks[0] || stacks[1])
		&& game_choose_instr("r", stacks[0], stacks[1], game) == -1)
		return (-1);
	return (0);
}

int	game_rev_rotate(t_stk *stack0, t_stk *stack1, t_psw *game)
{
	t_stk	**stacks;
	t_list	*last;
	t_list	*second_last;
	int		i;

	stacks = (t_stk *[3]){stack0, stack1, 0};
	i = -1;
	while (stacks[++i])
	{
		if (stacks[i]->size > 1)
		{
			second_last = game_lstseclast(stacks[i]->head);
			last = ft_lstlast(stacks[i]->head);
			last->next = stacks[i]->head;
			stacks[i]->head = last;
			second_last->next = NULL;
		}
		else
			stacks[i] = 0;
	}
	if ((stacks[0] || stacks[1])
		&& game_choose_instr("rr", stacks[0], stacks[1], game) == -1)
		return (-1);
	return (0);
}
