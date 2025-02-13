/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:40:36 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/13 18:55:23 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stkmgr_free_ressources(t_psw *game)
{
	ft_lstclear(&game->stack_a.head, free);
	ft_lstclear(&game->stack_b.head, free);
	ft_lstclear(&game->instrs, free);
}

t_list	*stkmgr_stack_push(int nb, t_stk *stack)
{
	t_list	*node;
	int		*nb_mem;

	nb_mem = ft_calloc(1, sizeof(int));
	if (nb_mem == NULL)
		return (NULL);
	*nb_mem = nb;
	node = ft_lstnew(nb_mem);
	if (node == NULL)
	{
		free(nb_mem);
		return (NULL);
	}
	ft_lstadd_front(&stack->head, node);
	stack->size++;
	return (stack->head);
}

t_list	*stkmgr_stack_pop(t_stk *stack)
{
	t_list	*node;

	node = stack->head;
	if (node == NULL)
		return (NULL);
	stack->head = node->next;
	node->next = NULL;
	stack->size--;
	return (node);
}

int	stkmgr_stacks_init(int *ranked, int size, t_psw *game)
{
	int	i;

	game->stack_a = (t_stk){.id = ID_STK_A, .head = NULL, .size = 0};
	game->stack_b = (t_stk){.id = ID_STK_B, .head = NULL, .size = 0};
	game->instrs = NULL;
	i = size;
	while (--i >= 0)
	{
		if (stkmgr_stack_push(ranked[i], &game->stack_a) == NULL)
		{
			ft_lstclear(&game->stack_a.head, free);
			return (-1);
		}
	}
	return (0);
}
