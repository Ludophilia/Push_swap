/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:49:52 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/18 22:33:21 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algos.h"

// 14/08 - What to do? Implement base algorithms...

// Let's continue with radix sort. The last one will be quicksort.

// Radix sort.

// A non comparative (What does this mean ?) sorting algorithm...
// ...that sorts numbers according to the value of their significant digits,

// For each "level" of significant digit (e.g. LSD: from the one that worth
// 10**0 to the one that worth 10**n, iteratively)

// The numbers are reordered following the digit hierarchy within that base.

// Example.

// 0 10 555 1 68 69

// 0 10 1 555 68 69 [10**0] 
// 0 1 10 555 68 69 [10**1]
// 0 1 10 68 69 555 [10**2]

// (how to sort negative numbers?)

int	main(int argc, char **argv)
{
	int	*nbs;
	int	*merged;

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
	merged = merge_sort(nbs, argc - 1);
	// insertion_sort(nbs, argc - 1);
	// selection_sort(nbs, argc - 1);
	// bubble_sort(nbs, argc - 1);
	cli_print_nbs(merged, argc - 1);
	free(merged);
	free(nbs);
	return (0);
}
