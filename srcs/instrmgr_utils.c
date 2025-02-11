/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrmgr_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:17:29 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/11 18:03:17 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int	game_cmp_inst(char *ins1, char *ins2, size_t len, char *strs[2])
{
	int	res[2];

	if (strs[0] == NULL || strs[1] == NULL)
		return (0);
	if (ft_strlen(strs[0]) != len || ft_strlen(strs[1]) != len)
		return (0);
	res[0] = (!ft_strncmp(strs[0], ins1, len)
			&& !ft_strncmp(strs[1], ins2, len));
	res[1] = (!ft_strncmp(strs[0], ins2, len)
			&& !ft_strncmp(strs[1], ins1, len));
	return (res[0] || res[1]);
}

int	game_smp_inst(char *new, t_list *nodes[2], char *strs[2])
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

t_list	*game_lstseclast(t_list *lst)
{
	while (lst)
	{
		if (lst->next != NULL && lst->next->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
