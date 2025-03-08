/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrmgr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:16:21 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/08 16:54:23 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static int	instmgr_check_instr(char *instr, size_t len, char **game_instrs)
{
	int	match;

	match = -1;
	while (*game_instrs)
	{
		if (ft_strncmp(instr, *game_instrs, len) == 0)
			match++;
		game_instrs++;
	}
	return (match);
}

static int	instmgr_store_instr(char *instr, t_list **instrs)
{
	t_list	*new_instr;

	new_instr = ft_lstnew(instr);
	if (new_instr == NULL)
	{
		free(instr);
		ft_lstclear(instrs, free);
		return (-1);
	}
	ft_lstadd_back(instrs, new_instr);
	return (0);
}

static int	instmgr_analyse_instr(char *instr)
{
	char	**inst_3l;
	char	**inst_4l;
	size_t	inst_len;

	inst_len = ft_strlen(instr);
	if (inst_len < 3 || inst_len > 4)
		return (-1);
	inst_3l = (char *[]){"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", NULL};
	inst_4l = (char *[]){"rra\n", "rrb\n", "rrr\n", NULL};
	if (inst_len == 3 && instmgr_check_instr(instr, 4, inst_3l) == -1)
		return (-1);
	else if (inst_len == 4 && instmgr_check_instr(instr, 5, inst_4l) == -1)
		return (-1);
	return (0);
}

// 8/03 - Yeah let's get started on that front.
int	instmgr_get_instrs(t_list **instrs)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (instmgr_analyse_instr(input) == -1)
		{
			free(input);
			return (-1);
		}
		if (instmgr_store_instr(input, instrs) == -1)
			return (-1);
		input = get_next_line(0);
	}
	return (0);
}
