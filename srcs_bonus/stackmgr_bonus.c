/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmgr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:58:40 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/14 18:21:25 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static int	stkmgr_config_args(char *inst_name, t_stk **stk_args, t_psw *game)
{
	if (!imgr_chk_instr(inst_name, 3,
			"sa\n", "ra\n", "rra", "pb\n", "ss\n", "rr\n", "rrr", 0))
		stk_args[0] = game->stack_a;
	else if (!imgr_chk_instr(inst_name, 3, "pa\n", "sb\n", "rb\n", "rrb", 0))
		stk_args[0] = game->stack_b;
	if (!imgr_chk_instr(inst_name, 3, "pa\n", 0))
		stk_args[1] = game->stack_a;
	else if (!imgr_chk_instr(inst_name, 3, "pb\n", "ss\n", "rr\n", "rrr", 0))
		stk_args[1] = game->stack_b;
	if (stk_args[0] == NULL && stk_args[1] == NULL)
		return (-1);
	return (0);
}

static int	stkmgr_choose_handler(char *inst_name, t_hdl *inst_handler)
{
	size_t	inst_len;

	inst_len = ft_strlen(inst_name);
	if (inst_len == 3 && *inst_name == 'p')
		*inst_handler = game_push;
	else if (inst_len == 3 && *inst_name == 's')
		*inst_handler = game_swap;
	else if (inst_len == 3 && *inst_name == 'r')
		*inst_handler = game_rotate;
	else if (inst_len == 4 && !ft_strncmp(inst_name, "rr", 2))
		*inst_handler = game_rev_rotate;
	if (*inst_handler == NULL)
		return (-1);
	return (0);
}

static int	stkmgr_exec_instr(char *inst_name, t_psw *game)
{
	t_hdl	inst_handler;
	t_stk	*stk_args[2];

	ft_bzero(stk_args, sizeof(stk_args));
	inst_handler = NULL;
	if (stkmgr_choose_handler(inst_name, &inst_handler) == -1
		|| stkmgr_config_args(inst_name, stk_args, game) == -1
		|| inst_handler(stk_args[0], stk_args[1], NULL) == -1)
		return (-1);
	return (0);
}

int	stkmgr_exec_instrs(t_psw *game)
{
	t_list	*inst_node;
	char	*inst_name;

	inst_node = game->instrs;
	while (inst_node)
	{
		inst_name = (char *)inst_node->content;
		if (stkmgr_exec_instr(inst_name, game) == -1)
			return (-1);
		inst_node = inst_node->next;
	}
	return (0);
}
