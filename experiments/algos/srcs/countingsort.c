/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countingsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:11:08 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/25 15:42:54 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algos.h"

static int	get_size_freq_arr(int *nbs, int size)
{
	int	max;
	int	i;

	i = -1;
	max = 0;
	while (++i < size)
	{
		if (nbs[i] < 0)
			return (-1);
		if (nbs[i] > max)
			max = nbs[i];
	}
	return (max);
}

static long	init_counting_sort(int *nbs, int size, int **sorted, int **pos)
{
	long	max;

	max = get_size_freq_arr(nbs, size);
	if (max == -1)
		return (-1);
	*sorted = ft_calloc(size, sizeof(int));
	if (*sorted == NULL)
		return (-1);
	*pos = ft_calloc(1 + max, sizeof(int));
	if (*pos == NULL)
	{
		free(*pos);
		return (-1);
	}
	return (1 + max);
}

int	*stable_counting_sort(int *nbs, int size)
{
	int		*sorted;
	int		*pos;
	long	ij[2];
	long	max;

	sorted = NULL;
	pos = NULL;
	max = init_counting_sort(nbs, size, &sorted, &pos);
	if (max == -1)
		return (NULL);
	ij[0] = -1;
	ij[1] = 0;
	while (++ij[0] < size)
		++pos[nbs[ij[0]]];
	while (++ij[1] < max)
		pos[ij[1]] += pos[ij[1] - 1];
	ij[0] = size;
	while (--ij[0] >= 0)
	{
		sorted[pos[nbs[ij[0]]] - 1] = nbs[ij[0]];
		pos[nbs[ij[0]]]--;
	}
	return (sorted);
}
