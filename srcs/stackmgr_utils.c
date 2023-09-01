/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmgr_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:06:28 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/01 20:29:07 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackmgr.h"

int	stkmgr_stack_is_sorted(t_stk *stack, int rev)
{
	int		i;
	int		last[2];
	t_list	*current;

	current = *stack->head;
	i = -1;
	while (current)
	{
		last[1] = *(int *)current->content;
		if (++i > 0)
			if ((!rev && (last[0] > last[1])) || (rev && (last[0] < last[1])))
				return (0);
		last[0] = *(int *)current->content;
		current = current->next;
	}
	return (1);
}

void	stkmgr_stack_free(t_stk *stack)
{
	ft_lstclear(stack->head, free);
	free(stack->head);
	free(stack);
}
