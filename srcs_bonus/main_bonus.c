/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:23:21 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/26 20:02:21 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	tmp_get_instrs(t_list **instrs)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		// Analyse instrs conformity here
		free(input);
		input = get_next_line(0);
	}
	return (0);
}

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
	if (tmp_get_instrs(instrs) == -1 && ft_dprintf(2, "Error\n"))
		return (1);

	// 
	// 
	stkmgr_free_ressources(stacks, instrs);
	return (0);
}