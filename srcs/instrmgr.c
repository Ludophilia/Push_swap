/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrmgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:47:44 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/04 19:32:20 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	game_cmp_inst(char *int_1, char *int_2, t_list *curr_int,
	t_list *next_int)
{
	char	*curr_intc;
	char	*next_intc;
	size_t	len;
	int		ret[2];
	
	curr_intc = (char *)curr_int->content;
	next_intc = (char *)next_int->content;
	len = ft_strlen(int_1);
	if (len != ft_strlen(int_2))
		return (-1);
	ret[0] = (!ft_strncmp(curr_intc, int_1, len)
			&& !ft_strncmp(next_intc, int_2, len));
	ret[1] = (!ft_strncmp(curr_intc, int_2, len)
			&& !ft_strncmp(next_intc, int_1, len));
	if (ret[0] == 0 && ret[1] == 0)
		return (-1);
	return (ret[0] || ret[1]);
}

static int	game_smp_inst(char *new, t_list *nodes[2])
{
	new = ft_strdup(new);
	if (new == NULL)
		return (-1);
	free(nodes[0]->content);
	nodes[0]->content = new;
	nodes[0]->next = nodes[1]->next;
	ft_lstdelone(nodes[1], free);
	nodes[1] = nodes[0]->next;
	return (0);
}

// 28/02 - Last effort before the finish line.
int	insmgr_opti_instrs(t_list **instrs)
{
	t_list	*curr_int;
	t_list	*next_int;

	curr_int = *instrs;
	if (curr_int)
		next_int = curr_int->next;
	while (curr_int && next_int)
	{
		if (game_cmp_inst("ra", "rb", curr_int, next_int)
			&& game_smp_inst("rr", nodes, strs) == -1)
			return (-1);
		else if (game_cmp_inst("rra", "rrb", 3, strs)
			&& game_smp_inst("rrr", nodes, strs) == -1)
			return (-1);
		else if (game_cmp_inst("sa", "sb", 2, strs)
			&& game_smp_inst("ss", nodes, strs) == -1)
			return (-1);
		curr_int = curr_int->next;
		if (curr_int)
			next_int = next_int->next;
	}
	return (0);
}

int	insmgr_store_instr(char *type, char *name, t_psw *game)
{
	t_list	*instr_node;
	t_list	**instr_head;
	char	*instr;

	instr_head = &game->instrs;
	instr = ft_strjoin(type, name);
	if (instr == NULL)
	{
		ft_lstclear(instr_head, free);
		return (-1);
	}
	instr_node = ft_lstnew(instr);
	if (instr_node == NULL)
	{
		free(instr);
		ft_lstclear(instr_head, free);
		return (-1);
	}
	ft_lstadd_back(instr_head, instr_node);
	return (0);
}

int	insmgr_choose_instr(char *type, t_stk *stack0, t_stk *stack1, t_psw *game)
{
	char	*stack_name;

	stack_name = NULL;
	if (stack0 && !stack1)
		stack_name = stack0->name;
	else if (!stack0 && stack1)
		stack_name = stack1->name;
	else if (stack0 && stack1
		&& (!ft_strncmp(type, "r", 2) || !ft_strncmp(type, "rr", 3)))
		stack_name = "r";
	else if (stack0 && stack1 && !ft_strncmp(type, "s", 2))
		stack_name = "s";
	if (stack_name == NULL
		|| (stack_name && insmgr_store_instr(type, stack_name, game) == -1))
		return (-1);
	return (0);
}
