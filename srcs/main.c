/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/13 15:41:03 by jgermany         ###   ########.fr       */
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

int	sort_upto_100nbs(t_stk *stackA, t_stk *stackB, t_list **instrs)
{
	// Pre sorting:
	// Everything on stack a to stack b.
	//		
	// [30 * 0 ; 30 * 1[ (0 ; 29)	
	// [30 * 1 ; 30 * 2[ (30 ; 59)
	// [30 * 2 ; 30 * 3[ (60 ; 89)
	// [30 * 3 ; 30 * 4[ (90 ; 119)
	// ...
	// [PIVOT * i ; PIVOT * i + 1[ (i == 0)
	// ...
	
	// except if the nbs are: (init_size - 1, init_size - 2, init_size - 3)
	// sort those numbers.
	int	max[3];
	int	ij[2];
	int	pivot;
	int	node;
	
	max[0] = (stackA->size - 1);
	max[1] = (stackA->size - 2);
	max[2] = (stackA->size - 3);
	pivot = 30;
	ij[0] = 0;
	// ft_printf("stackA->size == %i\n", stackA->size);
	while (stackA->size > 3)
	{
		// ft_printf("New turn.\n");
		// ft_printf("pivot == %i ; pivot + 1 == %i\n", pivot * ij[0],
			// pivot * (ij[0] + 1));
		ij[1] = -1;;
		while (++ij[1] < stackA->size && stackA->size > 3)
		{
			// ft_printf("current == %i\n", *(int *)(*stackA->head)->content);
			node = *(int *)(*stackA->head)->content;
			if (node == max[0] || node == max[1] || node == max[2])
			{
				if (game_rotate(stackA, 0, instrs) == -1)
					return (-1);
			}
			else if (node >= (pivot * ij[0]) && node < (pivot * (ij[0] + 1)))
			{
				if (game_push(stackA, stackB, instrs) == -1)
					return (-1);
				if ((node >= (pivot * ij[0]) / 2)
					&& game_rotate(stackB, 0, instrs) == -1)
					return (-1);
			}
		}
		// tmp_traverse_stack(stackA);
		ij[0]++;
	}
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
	sort_upto_100nbs(stacks[0], stacks[1], instrs);
	// sort_upto_5nbs(stacks[0], stacks[1], instrs);
	tmp_traverse_instructions(*instrs);
	// tmp_traverse_stack(stacks[0]);
	// tmp_traverse_stack(stacks[1]);
	stkmgr_stack_free(stacks[0]);
	stkmgr_stack_free(stacks[1]);
	ft_lstclear(instrs, free);
	return (0);
}
