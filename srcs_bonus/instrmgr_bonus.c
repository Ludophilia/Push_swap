/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrmgr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:16:21 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/19 15:56:11 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

int	imgr_is_instr(char *inst_name, size_t inst_len, char *inst_refs, ...)
{
	va_list	refs;

	va_start(refs, inst_refs);
	while (inst_refs)
	{
		if (ft_strncmp(inst_name, inst_refs, inst_len) == 0)
		{
			va_end(refs);
			return (1);
		}
		inst_refs = va_arg(refs, char *);
	}
	va_end(refs);
	return (0);
}

static int	imgr_chk_if_instr_valid(char *inst_name)
{
	size_t	inst_len;

	inst_len = ft_strlen(inst_name);
	if (inst_len != 3 && inst_len != 4)
		return (-1);
	if ((inst_len == 3 && imgr_is_instr(inst_name, 3, "sa\n", "sb\n",
				"ss\n", "pa\n", "pb\n", "ra\n", "rb\n", "rr\n", NULL))
		|| (inst_len == 4 && imgr_is_instr(inst_name, 4, "rra\n",
				"rrb\n", "rrr\n", NULL)))
		return (0);
	return (-1);
}

int	imgr_load_instrs(t_psw *game)
{
	char	*inst_name;

	inst_name = get_next_line(STDIN_FILENO);
	while (inst_name)
	{
		if (imgr_chk_if_instr_valid(inst_name) == -1
			|| imgr_store_instr(inst_name, game) == -1)
		{
			free(inst_name);
			return (-1);
		}
		inst_name = get_next_line(STDIN_FILENO);
	}
	return (0);
}
