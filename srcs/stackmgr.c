/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:40:36 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/10 15:39:12 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackmgr.h"

t_list	**stkmgr_stack_push(int nb, t_stk *stack)
{
	t_list	*node;
	int		*nb_store;

	nb_store = ft_calloc(1, sizeof(int));
	if (nb_store == NULL)
		return (NULL);
	*nb_store = nb;
	node = ft_lstnew(nb_store);
	if (node == NULL)
	{
		free(nb_store);
		return (NULL);
	}
	if (stack->head == NULL)
		*stack->head = node;
	else
		ft_lstadd_front(stack->head, node);
	stack->size++;
	return (stack->head);
}

t_list	*stkmgr_stack_pop(t_stk *stack)
{
	t_list	*node;

	node = *stack->head;
	if (node == NULL)
		return (NULL);
	*stack->head = node->next;
	node->next = NULL;
	stack->size--;
	return (node);
}

t_stk	*stkmgr_stack_init(char *name)
{
	t_stk	*stack;
	t_list	**head;

	stack = ft_calloc(1, sizeof(t_stk));
	if (stack == NULL)
		return (NULL);
	head = ft_calloc(1, sizeof(t_list *));
	if (head == NULL)
	{
		free(stack);
		return (NULL);
	}
	stack->name = name;
	stack->head = head;
	stack->size = 0;
	return (stack);
}

int	stkmgr_stacks_init(int size, int *cli_nbs, t_stk *stacks[3])
{
	int	i;

	ft_bzero(stacks, 3 * sizeof(t_stk *));
	stacks[0] = stkmgr_stack_init("a");
	if (stacks[0] == NULL)
		return (-1);
	stacks[1] = stkmgr_stack_init("b");
	if (stacks[1] == NULL)
	{
		stkmgr_stack_free(stacks[0]);
		return (-1);
	}
	i = size;
	while (--i >= 0)
	{
		if (stkmgr_stack_push(cli_nbs[i], stacks[0]) == NULL)
		{
			free(cli_nbs);
			stkmgr_stack_free(stacks[0]);
			stkmgr_stack_free(stacks[1]);
			return (-1);
		}
	}
	free(cli_nbs);
	return (0);
}
