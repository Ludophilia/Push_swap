/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:49:52 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/16 22:04:45 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algos.h"

// 14/08 - What to do? Implement base algorithms...

// Let's continue with merge sort.

// Merge sort is a divide and conquer algorithm...

// Divide phase:

// The array is recursively divided into sub arrays until reaching sub arrays
// of size 1.

// Conquer phase:

// The values of two adjacent sub arr are then compared, starting from the
// first one...

// Two "pointers" (i, j...) tracks the two arrays... 

// if the value of the element in the left sub is superior to the value of the
// element in the right sub, element of right sub is picked first, else
// the left sub element is picked.

// if there is more than 2 elements, although,  When one element is chosen, the
// pointer move to the next element and does a new comparison...

void	merge_sort(int *nbs, int size)
{
	if (size > 1)
	{
		// size: 2 ; size 1/2: 1
		// size: 3 ; size 1/2: 1 ; size 2/2: (size - size 1/2)
		merge_sort(nbs)
	}
}


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
	insertion_sort(nbs, argc - 1);
	// selection_sort(nbs, argc - 1);
	// bubble_sort(nbs, argc - 1);
	cli_print_nbs(nbs, argc - 1);
	free(nbs);
	return (0);
}
