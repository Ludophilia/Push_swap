/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrmgr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:16:21 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/11 18:34:21 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static int	instmgr_store_instr(char *instr_name, t_psw *game)
{
	t_list	*instr_node;

	instr_node = ft_lstnew(instr_name);
	if (instr_node == NULL)
	{
		ft_lstclear(&game->instrs, free);
		return (-1);
	}
	ft_lstadd_back(&game->instrs, instr_node);
	return (0);
}

static int	instmgr_chk_instr(char *instr_name, t_psw *game)
{
	char	**instr_names;
	size_t	instr_len;

	instr_len = ft_strlen(instr_name);
	if (instr_len != 3 || instr_len != 4)
		return (-1);
	if (instr_len == 3)
		instr_names = game->names_l3;
	else
		instr_names = game->names_l4;
	while (*instr_names)
	{
		if (ft_strncmp(instr_name, *instr_names, instr_len) == 0)
			return (0);
		++instr_names;
	}
	return (-1);
}

int	instmgr_load_instrs(t_psw *game)
{
	char	*instr_name;

	instr_name = get_next_line(STDIN_FILENO);
	while (instr_name)
	{
		if (instmgr_chk_instr(instr_name, game) == -1
			|| instmgr_store_instr(instr_name, game) == -1)
		{
			free(instr_name);
			return (-1);
		}
		instr_name = get_next_line(STDIN_FILENO);
	}
	return (0);
}
