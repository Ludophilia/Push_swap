/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:49:52 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/14 21:58:58 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algos.h"

int	*init_arr_from_cli(int argc, char **argv)
{
	int	*nbs;
	int	i;

	nbs = ft_calloc(argc, sizeof(int));
	if (nbs == NULL)
		return (NULL);
	i = -1;
	while (argv[++i])
		nbs[i] = ft_atoi(argv[i]);
	return (nbs);
}

void	print_arr(int *arr, int size)
{
	int *start;

	start = arr;
	while ((arr - start) < size)
		ft_printf("%i\n", *arr++);
}

// 14/08 - What to do? Implement base algorithms...
// Let's start with bubble sort.

// 1 2 3 4 5...

// Start from index 0.
// Take the first two indices: nb0 nb1
// if nb0 > nb1, nb0 and nb1 should be swapped... else, do nothing
// Take the first two indices + 1: nb1 nb2
// if nb1 > nb2, nb0 and nb1 should be swapped... else, do nothing

// and so on... until reached end of the list.

// repeat until the arr is fullt sorted?
void	bubble_sort(int *nbs)
{
	// Dprogramming.
}



int	main(int argc, char **argv)
{
	int	*nbs;

	if (argc < 2)
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	nbs = init_arr_from_cli(argc - 1, argv + 1);
	if (nbs == NULL)
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	print_arr(nbs, argc - 1);
	free(nbs);
	return (0);
}