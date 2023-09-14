/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/14 15:18:35 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	tmp_traverse_stack(t_stk *stack)
{
	t_list	*node;

	ft_dprintf(2, "Name: stack %s; stack size: %i\n",
		stack->name, stack->size);
	if (stack->size == 0)
	{
		ft_printf("[empty]\n");
		return ;
	}
	node = *stack->head;
	while (node != NULL)
	{
		ft_printf("%i\n", *(int *)node->content);
		node = node->next;
	}
}

static void	tmp_traverse_instructions(t_list *start)
{
	while (start)
	{
		ft_printf("%s\n", (char *)start->content);
		start = start->next;
	}
}

// if (game_push(stacks[0], stacks[1], instrs) == -1)
// 	return (-1);
// if ((node[0] >= (pivot[0] + (pivot[1] - pivot[0]) / 2)
// 		&& game_rotate(stacks[1], 0, instrs) == -1))
// 	return (-1);
int	sort_presort_100(t_stk **stacks, t_list **instrs)
{
	int	ij[2];
	int	pivot[3];
	int	node[2];

	node[1] = stacks[0]->size - 3;
	pivot[2] = stacks[0]->size / 2;
	ij[0] = 0;
	while (stacks[0]->size > 3)
	{
		ij[1] = stacks[0]->size;
		while (ij[1]-- > 0)
		{
			node[0] = *(int *)(*stacks[0]->head)->content;
			pivot[0] = (pivot[2] * ij[0]);
			pivot[1] = pivot[2] * (ij[0] + 1);
			if (node[0] < node[1] && node[0] >= pivot[0] && node[0] < pivot[1])
			{
				if (game_push(stacks[0], stacks[1], instrs) == -1
					|| (node[0] >= (pivot[0] + (pivot[1] - pivot[0]) / 2)
						&& game_rotate(stacks[1], 0, instrs) == -1))
					return (-1);
			}
			else
				if (game_rotate(stacks[0], 0, instrs) == -1)
					return (-1);
		}
		ij[0]++;
	}
	return (0);
}

int	sort_upto_100nbs(t_stk **stacks, t_list **instrs)
{
	if (sort_presort_100(stacks, instrs) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stk	*stacks[3];
	t_list	*instrs[1];
	int		init_status;

	init_status = cli_project_init(argc, argv, stacks, instrs);
	if (init_status == 0)
		return (0);
	if (init_status == -1)
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	// tmp_traverse_stack(stacks[0]);
	// tmp_traverse_stack(stacks[1]);
	(void)tmp_traverse_stack;
	sort_upto_100nbs(stacks, instrs);
	// sort_upto_5nbs(stacks[0], stacks[1], instrs);
	tmp_traverse_instructions(*instrs);
	// tmp_traverse_stack(stacks[0]);
	// tmp_traverse_stack(stacks[1]);
	stkmgr_stack_free(stacks[0]);
	stkmgr_stack_free(stacks[1]);
	ft_lstclear(instrs, free);
	return (0);
}
