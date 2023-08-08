/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:05:41 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/08 20:25:38 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 6/08 - What to do now?

// Implement every push_swap operations... INCLUDING the error cases,
// and test everything of course.

// - sa/sb/ss: swap instructions
// - pa/pb: push instructions
// - ra/rb/rr: rotate
// - rra/rrb/rrr: reverse rotate

// Generic rotate instruction
// rra - move every element down in the stack a. the last one becomes the 
// first one. Does nothing if size stack < 2.
void	pusw_rev_rotate(t_stk *stack0, t_stk *stack1)
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

			// Need to change the one before the last as well.
			
			// *stacks[i]->head = nodes[0]->next;
			// nodes[1]->next = nodes[0];
			// nodes[0]->next = NULL;
		}
		else
			stacks[i] = 0;
	}
	if (stacks[0] && !stacks[1])
		ft_printf("rr%c\n", stack0->name);
	else if (!stacks[0] && stacks[1])
		ft_printf("rr%c\n", stack1->name);
	else if (stacks[0] && stacks[1])
		ft_printf("rr\n");
}

void	pusw_rotate(t_stk *stack0, t_stk *stack1)
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
	if (stacks[0] && !stacks[1])
		ft_printf("r%c\n", stack0->name);
	else if (!stacks[0] && stacks[1])
		ft_printf("r%c\n", stack1->name);
	else if (stacks[0] && stacks[1])
		ft_printf("rr\n");
}

void	pusw_push(t_stk *from_stack, t_stk *to_stack)
{
	t_list	*from_node;

	from_node = mgr_stack_pop(from_stack);
	if (from_node == NULL)
		return ;
	if (to_stack->head == NULL)
		*to_stack->head = from_node;
	else
		ft_lstadd_front(to_stack->head, from_node);
	ft_printf("p%c\n", to_stack->name);
	to_stack->size++;
}

void	pusw_swap(t_stk *stack0, t_stk *stack1)
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
	if (stacks[0] && !stacks[1])
		ft_printf("s%c\n", stack0->name);
	else if (!stacks[0] && stacks[1])
		ft_printf("s%c\n", stack1->name);
	else if (stacks[0] && stacks[1])
		ft_printf("ss\n");
}

int	main(void)
{
	t_stk	*stacks[3];

	stacks[0] = mgr_stack_init('a');
	stacks[1] = mgr_stack_init('b');
	stacks[2] = NULL;
	if (stacks[0] == NULL || stacks[1] == NULL) 
		return (1);
	if (mgr_stack_push(1, stacks[0]) == NULL
		|| mgr_stack_push(2, stacks[0]) == NULL
		|| mgr_stack_push(3, stacks[0]) == NULL
		|| mgr_stack_push(4, stacks[0]) == NULL)
		return (1);
	traverse_stack(stacks[0]);
	pusw_push(stacks[0], stacks[1]);
	pusw_push(stacks[0], stacks[1]);
	pusw_rotate(stacks[0], NULL);
	pusw_rotate(stacks[1], NULL);
	pusw_rotate(stacks[0], stacks[1]);
	traverse_stack(stacks[0]);
	traverse_stack(stacks[1]);
	pusw_push(stacks[1], stacks[0]);
	pusw_rotate(stacks[0], stacks[1]);
	traverse_stack(stacks[0]);
	traverse_stack(stacks[1]);
	mgr_stack_free(stacks[0]);
	mgr_stack_free(stacks[1]);
	return (0);
}
