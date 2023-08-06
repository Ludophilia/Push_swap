/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:05:41 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/06 16:56:18 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 6/08 - What to do now?
// Implement every push_swap operations... INCLUDING the error cases,
// and test everything of course.
// 
int	main(void)
{
	t_stk	stack_a;

	if (init_stack(&stack_a) == -1)
		return (1);
	if (push_stack(420, &stack_a) == NULL)
		return (1);
	if (push_stack(2, &stack_a) == NULL)
		return (1);
	if (push_stack(3, &stack_a) == NULL)
		return (1);
	if (pop_and_clean_stack(&stack_a) == -1)
		return (1);
	if (push_stack(3, &stack_a) == NULL)
		return (1);
	if (push_stack(4, &stack_a) == NULL)
		return (1);
	if (pop_and_clean_stack(&stack_a) == -1)
		return (1);
	if (pop_and_clean_stack(&stack_a) == -1)
		return (1);
	if (pop_and_clean_stack(&stack_a) == -1)
		return (1);
	traverse_stack(&stack_a);
	free_stack(&stack_a);
	return (0);
}
