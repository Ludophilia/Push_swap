/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrmgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:47:44 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/15 17:37:45 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	imgr_is_next_two_instrs(t_list *inst_node, char *inst_ref1,
	char *inst_ref2)
{
	size_t	ref_len;
	int		inst_test[2];
	char	*curr_it;
	char	*next_it;

	curr_it = (char *)inst_node->content;
	next_it = (char *)inst_node->next->content;
	ref_len = ft_strlen(inst_ref1);
	if (ref_len != ft_strlen(inst_ref2)
		|| ref_len != ft_strlen(curr_it)
		|| ref_len != ft_strlen(next_it))
		return (0);
	inst_test[0] = (!ft_strncmp(curr_it, inst_ref1, ref_len)
			&& !ft_strncmp(next_it, inst_ref2, ref_len));
	inst_test[1] = (!ft_strncmp(curr_it, inst_ref2, ref_len)
			&& !ft_strncmp(next_it, inst_ref1, ref_len));
	return (inst_test[0] || inst_test[1]);
}

static int	imgr_smp_instr(char *smpl_it, t_list *inst_node)
{
	t_list	*next_node;

	next_node = inst_node->next;
	smpl_it = ft_strdup(smpl_it);
	if (smpl_it == NULL)
		return (-1);
	free(inst_node->content);
	inst_node->content = smpl_it;
	inst_node->next = next_node->next;
	ft_lstdelone(next_node, free);
	return (0);
}

int	imgr_opti_instrs(t_list **instrs)
{
	t_list	*inst_node;
	int		opt_type;

	inst_node = *instrs;
	while (inst_node && inst_node->next)
	{
		opt_type = -1;
		if (imgr_is_next_two_instrs(inst_node, "ra", "rb"))
			opt_type = OP_RR;
		else if (imgr_is_next_two_instrs(inst_node, "sa", "sb"))
			opt_type = OP_SS;
		else if (imgr_is_next_two_instrs(inst_node, "rra", "rrb"))
			opt_type = OP_RRR;
		if ((opt_type == OP_RR
				&& imgr_smp_instr("rr", inst_node) == -1)
			|| (opt_type == OP_SS
				&& imgr_smp_instr("ss", inst_node) == -1)
			|| (opt_type == OP_RRR
				&& imgr_smp_instr("rrr", inst_node) == -1))
			return (-1);
		inst_node = inst_node->next;
	}
	return (0);
}

int	imgr_store_instr(char *inst_name, t_psw *game)
{
	t_list	*inst_node;

	inst_node = ft_lstnew(inst_name);
	if (inst_node == NULL)
	{
		free(inst_name);
		return (-1);
	}
	ft_lstadd_back(&game->instrs, inst_node);
	return (0);
}

int	imgr_choose_instr(char *type, t_stk *stack0, t_stk *stack1, t_psw *game)
{
	char	*stack_name;
	char	*inst_name;

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
	inst_name = ft_strjoin(type, stack_name);
	if (inst_name == NULL
		|| stack_name == NULL
		|| imgr_store_instr(inst_name, game) == -1)
		return (-1);
	return (0);
}
