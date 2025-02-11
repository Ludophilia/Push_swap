/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrmgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:47:44 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/11 18:03:21 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	game_print_instrs(t_list *start)
{
	while (start)
	{
		ft_printf("%s\n", (char *)start->content);
		start = start->next;
	}
}

int	game_choose_instr(char *type, t_stk *stk0, t_stk *stk1, t_list **head)
{
	char	*stk_name;

	stk_name = NULL;
	if (stk0 && !stk1)
		stk_name = stk0->name;
	else if (!stk0 && stk1)
		stk_name = stk1->name;
	else if (stk0 && stk1)
	{
		if (!ft_strncmp(type, "r", 2) || !ft_strncmp(type, "rr", 3))
			stk_name = "r";
		else if (!ft_strncmp(type, "s", 2))
			stk_name = "s";
	}
	if (game_store_instr(type, stk_name, head) == -1)
		return (-1);
	return (0);
}

int	game_opti_instrs(t_list **instrs)
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
		if (game_cmp_inst("ra", "rb", 2, strs)
			&& game_smp_inst("rr", nodes, strs) == -1)
			return (-1);
		else if (game_cmp_inst("rra", "rrb", 3, strs)
			&& game_smp_inst("rrr", nodes, strs) == -1)
			return (-1);
		else if (game_cmp_inst("sa", "sb", 2, strs)
			&& game_smp_inst("ss", nodes, strs) == -1)
			return (-1);
		nodes[0] = nodes[0]->next;
		if (*nodes)
			nodes[1] = nodes[1]->next;
	}
	return (0);
}
