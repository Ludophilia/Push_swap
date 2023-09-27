/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:23:21 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/27 19:58:22 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"
#include "gamemgr.h" // tmp

void	tmp_print_instrs(t_list *start)
{
	ft_printf("\n");
	while (start)
	{
		ft_printf("%s", (char *)start->content);
		start = start->next;
	}
}

// 3 + 1 length
//	pa pb
//	sa sb ss
//	ra rb rr

// 4 : 
//	rra rrb rrr
int	tmp_selec_instr2(char *instr, t_stk **stks)
{
	int 	(*handler)(t_stk *, t_stk *);
	t_stk	*stkargs[2];
	size_t	instr_len;

	instr_len = ft_strlen(instr);

	// Choose handler and store it in the ptr...
	if (instr_len == 3 && *instr == 'p')
		handler = instr_push;
	else if (instr_len == 3 && *instr == 's')
		handler = instr_swap;
	else if (instr_len == 3 && *instr == 'r')
		handler = instr_rotate;
	else if (instr_len == 4 && instr[0] == 'r' && instr[1] == 'r')
		handler = instr_rev_rotate;
	else
		handler = NULL;

	// Choose the correct stack args configuration
	if (instr_len == 3 && instr[0] == 'p' && instr[1] == 'a')
	{
		stkargs[0] = stks[1];
		stkargs[1] = stks[0];
	}
	if (instr_len == 3 && instr[0] == 'p' && instr[1] == 'b')
	{
		stkargs[0] = stks[1];
		stkargs[1] = stks[0];
	}	

	// //////////////////////////////////////////////////////
	if (handler && handler(stkargs[0], stkargs[1]) == 0)
		return (0);
	return (-1);
}

int	tmp_selec_instr(char *instr, t_stk **stks)
{
	size_t	instr_len;

	instr_len = ft_strlen(instr);

	// Filter here
	if (ft_strncmp(instr, "pa\n", 4) == 0
			&& instr_push(stks[1], stks[0]) == -1)
		return (-1);
	else if (ft_strncmp(instr, "pb\n", 4) == 0
			&& instr_push(stks[0], stks[1]) == -1)
		return (-1);

	// Function pointer opportunity?
	if (ft_strncmp(instr, "sa\n", 4) == 0
			&& instr_swap(stks[0], NULL) == -1)
		return (-1);
	else if (ft_strncmp(instr, "sb\n", 4) == 0
			&& instr_swap(stks[1], NULL) == -1)
		return (-1);
	else if (ft_strncmp(instr, "ss\n", 4) == 0
			&& instr_swap(stks[0], stks[1]) == -1)
		return (-1);

	// Function pointer opportunity?
	if (ft_strncmp(instr, "ra\n", 4) == 0
			&& instr_rotate(stks[0], NULL) == -1)
		return (-1);
	else if (ft_strncmp(instr, "rb\n", 4) == 0
			&& instr_rotate(stks[1], NULL) == -1)
		return (-1);
	else if (ft_strncmp(instr, "rr\n", 4) == 0
			&& instr_rotate(stks[0], stks[1]) == -1)
		return (-1);

	// Function pointer opportunity?
	if (ft_strncmp(instr, "rra\n", 5) == 0
			&& instr_rotate(stks[0], NULL) == -1)
		return (-1);
	else if (ft_strncmp(instr, "rrb\n", 5) == 0
			&& instr_rotate(stks[1], NULL) == -1)
		return (-1);
	else if (ft_strncmp(instr, "rrr\n", 5) == 0
			&& instr_rotate(stks[0], stks[1]) == -1)
		return (-1);	

	return (0);
}


int	tmp_exec_instrs(t_list **instrs)
{
	t_list	*instr;

	instr = *instrs;
	while (instr)
	{
		// WOW.
		instr = instr->next;
	}
	return (0);	
}

// NEXT - Check if everything sorted. "KO\n" or "OK\n"?
int	main(int argc, char *argv[])
{
	t_stk	*stacks[3];
	t_list	*instrs[1];
	int		init_status;

	init_status = cli_project_init(argc, argv, stacks, instrs);
	if (init_status == 0)
		return (0);
	if (init_status == -1 && ft_dprintf(2, "Error\n"))
		return (1);
	if (instmgr_get_instrs(instrs) == -1 && ft_dprintf(2, "Error\n"))
	{
		stkmgr_free_ressources(stacks, instrs);
		return (1);
	}
	tmp_print_instrs(*instrs);
	// Now execute the instructions.
	stkmgr_free_ressources(stacks, instrs);
	return (0);
}
