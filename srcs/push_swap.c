/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:05:41 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/04 21:11:41 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

typedef struct s_stk
{
	t_list	**head;
	int		size;
}	t_stk;

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

// returns a node (t_list *) or NULL
// remove the element/node at the top of the stack
// and return it if exists...
t_list	*pop_stack(t_stk *stack)
{
	t_list	*node;

	node = *stack->head;
	if (node == NULL)
		return (NULL);
	stack->head = &node->next;
	node->next = NULL;
	stack->size--;
	return (node);
}

// Takes head, returns head or null
// Adds a nb to the stack
t_list	**push_stack(int nb, t_stk *stack)
{
	t_list	*node;
	int		*nb_store;

	nb_store = ft_calloc(1, sizeof(int));
	if (nb_store == NULL)
		return (NULL);
	*nb_store = 420; (void)nb;
	node = ft_lstnew(nb_store);
	if (node == NULL)
		return (NULL);
	if (stack->head == NULL)
		*stack->head = node;
	else
		ft_lstadd_front(stack->head, node);
	stack->size++;
	printf("stack->head: %p, content: %i\n",
		stack->head, *(int *)((*(stack->head))->content));
	printf("stack->head: %p, content: %i\n",
		stack->head, *(int *)((*(stack->head))->content));
	printf("stack->head: %p, content: %i\n\n",
		stack->head, *(int *)((*(stack->head))->content));
	// printf("content: %i, next: %p\n\n",
	// 	*((int *)((*stack->head)->content)), (*stack->head)->next);
	// ft_printf("content: %i, next: %p\n\n",
	// 	*(int *)(*stack->head)->content, (*stack->head)->next);
	return (stack->head);
}

void	traverse_stack(t_stk *stack)
{
	// node = *stack->head;
	// ft_dprintf(1, "size : %i\n", stack->size);
	// ft_dprintf(1, "content: %i\n", *(int *)(*stack->head)->content);
	printf("stack->head: %p, content: %i\n",
		stack->head, *(int *)((*(stack->head))->content));
	printf("stack->head: %p, content: %i\n",
		stack->head, *(int *)((*(stack->head))->content));
	printf("stack->head: %p, content: %i\n",
		stack->head, *(int *)((*(stack->head))->content));
	printf("stack->head: %p, content: %i\n",
		stack->head, *(int *)((*(stack->head))->content));
	// while (node != NULL)
	// {
	// 	ft_dprintf(1, "Stack size : %i\n", stack->size);
	// 	ft_dprintf(1, "%i\n", *(int *)node->content);
	// 	node = node->next;
	// }
}
// 2/08 - What to do?
// Implement push/pop and tests if everything works with some printf statements.
int	main(void)
{
	t_stk	stack_a;

	// stack_a = ft_calloc(1, sizeof(t_stk));
	if (init_stack(&stack_a) == -1)
		return (1);
	// printf("stack->head: %p\n\n",
	// 	(&stack_a)->head);
	if (push_stack(1, &stack_a) == NULL)
		return (1);
	// if (push_stack(2, &stack_a) == NULL)
	// 	return (1);
	// if (push_stack(3, &stack_a) == NULL)
	// 	return (1);
	traverse_stack(&stack_a);
	return (0);
}
