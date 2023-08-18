/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:14:09 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/18 20:34:48 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algos.h"

static int	*init_merge(int merged_size, int ijk[3], int overflow[2])
{
	int	*merge;

	merge = ft_calloc(merged_size, sizeof(int));
	if (merge == NULL)
		return (NULL);
	*(long *)overflow = 0;
	*(long *)ijk = 0;
	ijk[2] = -1;
	return (merge);
}

static int	*merge_nbs(int *lnbs, int lsize, int *rnbs, int rsize)
{
	int	*merge;
	int	ijk[3];
	int	overflow[2];

	merge = init_merge(lsize + rsize, ijk, overflow);
	if (!merge)
		return (NULL);
	while (++ijk[2] < lsize + rsize)
	{
		if (overflow[1] || (!overflow[0] && lnbs[ijk[0]] <= rnbs[ijk[1]]))
		{
			merge[ijk[2]] = lnbs[ijk[0]++];
			if (ijk[0] == lsize)
				overflow[0] = 1;
		}
		else if (overflow[0] || (!overflow[1] && rnbs[ijk[1]] < lnbs[ijk[0]]))
		{
			merge[ijk[2]] = rnbs[ijk[1]++];
			if (ijk[1] == rsize)
				overflow[1] = 1;
		}
	}
	free(lnbs);
	free(rnbs);
	return (merge);
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
		sorted[i] = nbs[i];
	if (size >= 2)
	{
		tmp = sorted;
		sorted = merge_nbs(merge_sort(sorted, size / 2),
				size / 2,
				merge_sort(sorted + size / 2, size - (size / 2)),
				size - (size / 2));
		free(tmp);
		return (sorted);
	}
	return (sorted);
}
