/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrmgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:47:44 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/16 18:46:10 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// static int	game_cmp_inst(char *ins1, char *ins2, size_t len, char *strs[2])
// {
// 	int	res[2];

// 	if (strs[0] == NULL || strs[1] == NULL)
// 		return (0);
// 	if (ft_strlen(strs[0]) != len || ft_strlen(strs[1]) != len)
// 		return (0);
// 	res[0] = (!ft_strncmp(strs[0], ins1, len)
// 			&& !ft_strncmp(strs[1], ins2, len));
// 	res[1] = (!ft_strncmp(strs[0], ins2, len)
// 			&& !ft_strncmp(strs[1], ins1, len));
// 	return (res[0] || res[1]);
// }

// static int	game_smp_inst(char *new, t_list *nodes[2], char *strs[2])
// {
// 	new = ft_strdup(new);
// 	if (new == NULL)
// 		return (-1);
// 	free(nodes[0]->content);
// 	nodes[0]->content = new;
// 	nodes[0]->next = nodes[1]->next;
// 	ft_lstdelone(nodes[1], free);
// 	nodes[1] = nodes[0]->next;
// 	strs[0] = 0;
// 	strs[1] = 0;
// 	return (0);
// }

// int	game_opti_instrs(t_list **instrs)
// {
// 	t_list	*nodes[2];
// 	char	*strs[2];

// 	nodes[0] = *instrs;
// 	if (*nodes)
// 		nodes[1] = nodes[0]->next;
// 	while (nodes[0] && nodes[1])
// 	{
// 		strs[0] = (char *)nodes[0]->content;
// 		strs[1] = (char *)nodes[1]->content;
// 		if (game_cmp_inst("ra", "rb", 2, strs)
// 			&& game_smp_inst("rr", nodes, strs) == -1)
// 			return (-1);
// 		else if (game_cmp_inst("rra", "rrb", 3, strs)
// 			&& game_smp_inst("rrr", nodes, strs) == -1)
// 			return (-1);
// 		else if (game_cmp_inst("sa", "sb", 2, strs)
// 			&& game_smp_inst("ss", nodes, strs) == -1)
// 			return (-1);
// 		nodes[0] = nodes[0]->next;
// 		if (*nodes)
// 			nodes[1] = nodes[1]->next;
// 	}
// 	return (0);
// }

int	game_store_instr(char *type, char *stk_name, t_list **head)
{
	t_list	*new_instr;
	char	*instr;

	instr = ft_strjoin(type, stk_name);
	if (instr == NULL)
	{
		ft_lstclear(head, free);
		return (-1);
	}
	new_instr = ft_lstnew(instr);
	if (new_instr == NULL)
	{
		free(instr);
		ft_lstclear(head, free);
		return (-1);
	}
	ft_lstadd_back(head, new_instr);
	return (0);
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
