/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:40:36 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/06 16:34:46 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackmgr.h"

int	init_stack(t_stk *stack)
{
	t_list	**head;

	head = ft_calloc(1, sizeof(head));
	if (head == NULL)
		return (-1);
	stack->head = head;
	stack->size = 0;
	return (0);
}

void free_stack(t_stk *stack)
{
	ft_lstclear(stack->head, free);
	free(stack->head);
}

t_list	**push_stack(int nb, t_stk *stack)
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

t_list	*pop_stack(t_stk *stack)
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
