/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:16:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/19 22:11:42 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main_choose_algorithm(t_stk **stacks, t_list **instrs)
{
	if (stacks[0]->size <= 5
		&& sort_upto_5nbs(stacks, instrs) == -1)
		return (-1);
	else if (stacks[0]->size > 5 && stacks[0]->size <= 75
		&& sort_upto_100nbs(stacks, 2, instrs) == -1)
		return (-1);
	else if (stacks[0]->size > 75 && stacks[0]->size <= 250
		&& sort_upto_100nbs(stacks, 4, instrs) == -1)
		return (-1);
	else if (stacks[0]->size > 250
		&& sort_upto_100nbs(stacks, 9, instrs) == -1)
		return (-1);
	return (0);
}

void	tmp_traverse_instructions(t_list *start)
{
	while (start)
	{
		ft_printf("%s\n", (char *)start->content);
		start = start->next;
	}
}

int	smp_inst(char *new, t_list *nodes[2], char *strs[2])
{
	new = ft_strdup(new);
	if (new == NULL)
		return (-1);
	free(nodes[0]->content);
	nodes[0]->content = new;
	nodes[0]->next = nodes[1]->next;
	ft_lstdelone(nodes[1], free);
	nodes[1] = nodes[0]->next;
	strs[0] = 0;
	strs[1] = 0;
	return (0);
}

int	cmp_inst(char *ins1, char *ins2, size_t len, char *strs[2])
{
	int	res[2];

	if (strs[0] == NULL || strs[1] == NULL)
		return (0);
	if (ft_strlen(strs[0]) != len || ft_strlen(strs[1]) != len)
		return (0);
	res[0] = !ft_strncmp(strs[0], ins1, len) && !ft_strncmp(strs[1], ins2, len);
	res[1] = !ft_strncmp(strs[0], ins2, len) && !ft_strncmp(strs[1], ins1, len);
	return (res[0] || res[1]);
}

int	opti_instrs(t_list **instrs)
{
	t_list	*nodes[2];
	char	*strs[2];

	nodes[0] = *instrs;
	if (*nodes)
		nodes[1] = nodes[0]->next;
	while (nodes[0] && nodes[1])
	{
		strs[0] = (char *)nodes[0]->content;
		strs[1] = (char *)nodes[1]->content;
		if (cmp_inst("ra", "rb", 2, strs) && smp_inst("rr", nodes, strs) == -1)
			return (-1);
		else if (cmp_inst("rra", "rrb", 3, strs)
			&& smp_inst("rrr", nodes, strs) == -1)
			return (-1);
		else if (cmp_inst("sa", "sb", 2, strs)
			&& smp_inst("ss", nodes, strs) == -1)
			return (-1);
		nodes[0] = nodes[0]->next;
		if (*nodes)
			nodes[1] = nodes[1]->next;
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
	if (init_status == -1 && ft_dprintf(2, "Error\n"))
		return (1);
	if (main_choose_algorithm(stacks, instrs) == -1
		|| opti_instrs(instrs) == -1)
	{
		stkmgr_free_ressources(stacks, instrs);
		return (1);
	}
	tmp_traverse_instructions(*instrs);
	stkmgr_free_ressources(stacks, instrs);
	return (0);
}

// 100 -> 699 max ; 500 -> 5499 max.
// static void	tmp_traverse_stack(t_stk *stack)
// {
// 	t_list	*node;

// 	ft_dprintf(2, "Name: stack %s; stack size: %i\n",
// 		stack->name, stack->size);
// 	if (stack->size == 0)
// 	{
// 		ft_printf("[empty]\n");
// 		return ;
// 	}
// 	node = *stack->head;
// 	while (node != NULL)
// 	{
// 		ft_printf("%i\n", *(int *)node->content);
// 		node = node->next;
// 	}
// }