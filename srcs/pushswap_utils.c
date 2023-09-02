/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:45:44 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/02 21:18:28 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*pusw_lstseclast(t_list *lst)
{
	while (lst)
	{
		if (lst->next != NULL && lst->next->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	pusw_store_instr(char *type, char *stk_name, t_list **head)
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

int	pusw_deter_instr(char *type, t_stk *stk0, t_stk *stk1, t_list **head)
{
	char *stk_name;

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
	if (pusw_store_instr(type, stk_name, head) == -1)
		return (-1);
	return (0);
}
