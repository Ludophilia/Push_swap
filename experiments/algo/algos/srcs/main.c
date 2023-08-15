/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:49:52 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/15 21:44:47 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algos.h"

// 14/08 - What to do? Implement base algorithms...

// Let's continue with insertion sort.

// For an array of size n, n passes as always...

// First pass:
// - Only sort 1 element, the first one.

// Second pass:
// - Only sort 2 elements, the first one and its right neighbor.
// - If the last element is inferior to the last before, swap them.

// Third pass:
// - Only sort 3 elements, the first one, second one and its right neighbor.
// - If the last element is inferior to the last before, swap them.
// - Decrement...
// - If the right element is inferior to the last before, swap them.
// ...

// ...


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
	// selection_sort(nbs, argc - 1);
	// bubble_sort(nbs, argc - 1);
	cli_print_nbs(nbs, argc - 1);
	free(nbs);
	return (0);
}
