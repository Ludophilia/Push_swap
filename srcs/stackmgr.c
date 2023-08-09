/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:40:36 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/09 13:49:46 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackmgr.h"

t_stk	*mgr_stack_init(char name)
{
	t_stk	*stack;
	t_list	**head;

	stack = ft_calloc(1, sizeof(t_stk));
	if (stack == NULL)
		return (NULL);
	head = ft_calloc(1, sizeof(head));
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

void	mgr_stack_free(t_stk *stack)
{
	ft_lstclear(stack->head, free);
	free(stack->head);
	free(stack);
}

t_list	**mgr_stack_push(int nb, t_stk *stack)
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

t_list	*mgr_stack_pop(t_stk *stack)
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

void	traverse_stack(t_stk *stack)
{
	t_list	*node;

	ft_dprintf(2, "Name: stack %c; stack size: %i\n",
		stack->name, stack->size);
	if (stack->size == 0)
	{
		ft_printf("[empty]\n");
		return ;
	}
	node = *stack->head;
	while (node != NULL)
	{
		ft_dprintf(1, "%i\n", *(int *)node->content);
		node = node->next;
	}
}
