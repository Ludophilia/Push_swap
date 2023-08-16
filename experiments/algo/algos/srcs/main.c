/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:49:52 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/16 16:57:07 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algos.h"

// 14/08 - What to do? Implement base algorithms...

// Let's continue with lmerge sort.

int	main(int argc, char **argv)
{
	int	*nbs;

	if (argc < 2)
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	nbs = cli_init_arr_from_args(argc - 1, argv + 1);
	if (nbs == NULL)
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	// insertion_sort(nbs, argc - 1);
	// selection_sort(nbs, argc - 1);
	// bubble_sort(nbs, argc - 1);
	cli_print_nbs(nbs, argc - 1);
	free(nbs);
	return (0);
}
