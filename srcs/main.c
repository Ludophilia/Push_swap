/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/09 15:15:29 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// 09/08 - Implement stack init from argv as stated by the exercice... 
int	main(void)
{
	t_stk	*stacks[3];

	stacks[0] = stkmgr_stack_init('a');
	stacks[1] = stkmgr_stack_init('b');
	stacks[2] = NULL;
	if (stacks[0] == NULL || stacks[1] == NULL) 
		return (1);
	if (stkmgr_stack_push(1, stacks[0]) == NULL
		|| stkmgr_stack_push(2, stacks[0]) == NULL
		|| stkmgr_stack_push(3, stacks[0]) == NULL
		|| stkmgr_stack_push(4, stacks[0]) == NULL)
		return (1);
	traverse_stack(stacks[0]);
	traverse_stack(stacks[1]);
	pusw_push(stacks[0], stacks[1]);
	pusw_push(stacks[0], stacks[1]);
	pusw_swap(stacks[0], stacks[1]);
	pusw_swap(stacks[0], stacks[1]);
	pusw_rev_rotate(stacks[0], stacks[1]);
	pusw_rev_rotate(stacks[0], stacks[1]);
	pusw_rev_rotate(stacks[0], stacks[1]);
	pusw_rotate(stacks[0], stacks[1]);
	pusw_rotate(stacks[0], stacks[1]);
	pusw_rotate(stacks[0], stacks[1]);
	pusw_rotate(stacks[0], stacks[1]);
	traverse_stack(stacks[0]);
	traverse_stack(stacks[1]);
	stkmgr_stack_free(stacks[0]);
	stkmgr_stack_free(stacks[1]);
	return (0);
}
