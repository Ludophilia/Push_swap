/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamemgr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:05:41 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/13 20:36:51 by jegerman         ###   ########.fr       */
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
	char 	*inst_name;

	from_node = stkmgr_stack_pop(from_stack);
	if (from_node == NULL)
		return (-1);
	if (to_stack->head == NULL)
		to_stack->head = from_node;
	else
		ft_lstadd_front(&to_stack->head, from_node);
	to_stack->size++;
	inst_name = ft_strjoin("p", to_stack->name);
	if (inst_name == NULL
		|| (game != NULL && imgr_store_instr(inst_name, game) == -1))
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
	if (game != NULL && (*stacks || stacks[1])
		&& imgr_choose_instr("s", *stacks, stacks[1], game) == -1)
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
	if (game != NULL && (*stacks || stacks[1])
		&& imgr_choose_instr("r", *stacks, stacks[1], game) == -1)
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
			stacks[i] = NULL;
	}
	if (game != NULL && (stacks[0] || stacks[1])
		&& imgr_choose_instr("rr", *stacks, stacks[1], game) == -1)
		return (-1);
	return (0);
}
