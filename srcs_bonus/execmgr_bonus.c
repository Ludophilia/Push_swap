/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execmgr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:58:40 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/28 13:16:29 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execmgr_bonus.h"

static int	exc_choose_handler(char *instr, int (**handler)(t_stk *, t_stk *))
{
	size_t	instr_len;

	instr_len = ft_strlen(instr);
	*handler = NULL;
	if (instr_len == 3 && *instr == 'p')
		*handler = gameinst_push;
	else if (instr_len == 3 && *instr == 's')
		*handler = gameinst_swap;
	else if (instr_len == 3 && *instr == 'r')
		*handler = gameinst_rotate;
	else if (instr_len == 4 && instr[0] == 'r' && instr[1] == 'r')
		*handler = gameinst_rev_rotate;
	if (*handler)
		return (0);
	return (-1);
}

static int	exc_config_args(char *instr, t_stk **stacks, t_stk *stkargs[2])
{
	if (!ft_strncmp(instr, "pa\n", 3))
	{
		stkargs[0] = stacks[1];
		stkargs[1] = stacks[0];
	}
	else if (!ft_strncmp(instr, "pb\n", 3) || !ft_strncmp(instr, "ss\n", 3)
		|| !ft_strncmp(instr, "rr\n", 3) || !ft_strncmp(instr, "rrr", 3))
	{
		stkargs[0] = stacks[0];
		stkargs[1] = stacks[1];
	}
	else if (!ft_strncmp(instr, "sa\n", 3) || !ft_strncmp(instr, "ra\n", 3)
		|| !ft_strncmp(instr, "rra", 3))
	{
		stkargs[0] = stacks[0];
	}
	else if (!ft_strncmp(instr, "sb\n", 3) || !ft_strncmp(instr, "rb\n", 3)
		|| !ft_strncmp(instr, "rrb", 3))
	{
		stkargs[0] = stacks[1];
	}
	if (stkargs[0] == NULL && stkargs[1] == NULL)
		return (-1);
	return (0);
}

static int	exc_execute_instr(char *instr, t_stk **stacks)
{
	int		(*handler)(t_stk *, t_stk *);
	t_stk	*stkargs[2];

	ft_bzero(stkargs, sizeof(stkargs));
	if (exc_choose_handler(instr, &handler) == -1
		|| exc_config_args(instr, stacks, stkargs) == -1
		|| handler(stkargs[0], stkargs[1]) == -1)
		return (-1);
	return (0);
}

int	exc_execute_instrs(t_list **instrs, t_stk **stacks)
{
	t_list	*instr;

	instr = *instrs;
	while (instr)
	{
		if (exc_execute_instr((char *)instr->content, stacks) == -1)
			return (-1);
		instr = instr->next;
	}
	return (0);
}
