/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrmgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:47:44 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/07 15:29:42 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	inmg_chk_instr(char *curr_it, char *next_it, char *inst_ref1,
	char *inst_ref2)
{
	size_t	ref_len;
	int		inst_test[2];

	ref_len = ft_strlen(inst_ref1);
	if (ref_len != ft_strlen(inst_ref2))
		return (0);
	inst_test[0] = (!ft_strncmp(curr_it, inst_ref1, ref_len)
			&& !ft_strncmp(next_it, inst_ref2, ref_len));
	inst_test[1] = (!ft_strncmp(curr_it, inst_ref2, ref_len)
			&& !ft_strncmp(next_it, inst_ref1, ref_len));
	return (inst_test[0] || inst_test[1]);
}

static int	inmg_smp_instr(char *smpl_it, t_list *instr_node)
{
	t_list	*next_node;

	next_node = instr_node->next;
	smpl_it = ft_strdup(smpl_it);
	if (smpl_it == NULL)
		return (-1);
	free(instr_node->content);
	instr_node->content = smpl_it;
	instr_node->next = next_node->next;
	ft_lstdelone(next_node, free);
	return (0);
}

int	inmg_opti_instrs(t_list **instrs)
{
	t_list	*instr_node;
	char	*curr_it;
	char	*next_it;
	int		opt_type;

	instr_node = *instrs;
	while (instr_node && instr_node->next)
	{
		curr_it = (char *)instr_node->content;
		next_it = (char *)instr_node->next->content;
		opt_type = 0;
		if (inmg_chk_instr(curr_it, next_it, "ra", "rb"))
			opt_type = OP_RR;
		else if (inmg_chk_instr(curr_it, next_it, "sa", "sb"))
			opt_type = OP_SS;
		else if (inmg_chk_instr(curr_it, next_it, "rra", "rrb"))
			opt_type = OP_RRR;
		if ((opt_type == OP_RR && inmg_smp_instr("rr", instr_node) == -1)
			|| (opt_type == OP_SS && inmg_smp_instr("ss", instr_node) == -1)
			|| (opt_type == OP_RRR && inmg_smp_instr("rrr", instr_node) == -1))
			return (-1);
		instr_node = instr_node->next;
	}
	return (0);
}

int	inmg_store_instr(char *type, char *name, t_psw *game)
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

int	inmg_choose_instr(char *type, t_stk *stack0, t_stk *stack1, t_psw *game)
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
		|| (stack_name && inmg_store_instr(type, stack_name, game) == -1))
		return (-1);
	return (0);
}
