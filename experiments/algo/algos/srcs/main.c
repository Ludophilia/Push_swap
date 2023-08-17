/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:49:52 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/17 22:25:35 by jgermany         ###   ########.fr       */
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

// When one element is picked, the pointer move to the next element and
// a new comparison is made...

// merge frees the array passed to it and create a new one. There is no
// other way of doing anyway.

int	*merge_nbs(int *lnbs, int lsize, int *rnbs, int rsize)
{
	int	*merged;
	int ijk[3];

	merged = ft_calloc(lsize + rsize, sizeof(int));
	if (merged == NULL)
		return (NULL);
	*(long *)&ijk = 0;
	ijk[2] = -1;
	while (++ijk[2] < lsize + rsize)
	{
		// How can mark that a value has been already selected?
		// loverflow and roverflow at 1. If it has overflown, loverflow or 
		// roverflow will prevent the value being chosen again...
		if (lnbs[ijk[0]] < rnbs[ijk[1]])
		{
			merged[ijk[2]] = lnbs[ijk[0]];
			if (ijk[0] < lsize)
				++ijk[0];
		}
		else if (rnbs[ijk[1]] < lnbs[ijk[0]])
		{
			merged[ijk[2]] = rnbs[ijk[1]];
			if (ijk[1] < rsize)
				++ijk[1];
		}
	}
	free(lnbs);
	free(rnbs);
	return (merged);
}

int	*merge_sort(int *nbs, int size)
{
	int	*sorted;
	int	*tmp;
	int	i;	

	if (!nbs || size < 1)
		return (NULL);
	sorted = ft_calloc(size, sizeof(int));
	if (sorted == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		sorted = nbs[i];
	if (size >= 2)
	{
		tmp = sorted;
		sorted = merge_nbs(merge_sort(sorted, size / 2),
			size / 2,
			merge_sort(sorted + size / 2, size - (size / 2)),
			size - (size / 2));
		free(tmp);
		return (sorted); // merge(merge_sort(), merge_sort())
	}
	return (sorted); // base case, arr of size 1.
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
