/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:49:52 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/27 23:24:36 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algos.h"

// 14/08 - What to do? 
// Implement base algorithms...
// The last one will be quicksort. Bucket sort and then radix sort in the end.
int	main(int argc, char **argv)
{
	int	*nbs;
	int	*sorted;

	if (argc < 2)
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	nbs = cli_init_arr_from_args(argc - 1, argv + 1);
	if (nbs == NULL)
	{
		free(nbs);
		ft_dprintf(2, "Error\n");
		return (1);
	}
	sorted = bucket_sort(nbs, argc - 1);
	if (sorted == NULL)
	{
		free(nbs);
		ft_dprintf(2, "Error\n");
		return (1);
	}
	cli_print_nbs(sorted, argc - 1);
	free(sorted);
	free(nbs);
	return (0);
}
