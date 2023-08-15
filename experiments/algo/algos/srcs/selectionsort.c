/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:27:49 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/15 19:29:56 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algos.h"

void	selection_sort(int *nbs, int size)
{
	int	ij[2];
	int	smallest;
	int	tmp;

	ij[0] = -1;
	while (++ij[0] < size)
	{
		ij[1] = -1 + ij[0];
		smallest = ij[0];
		while (++ij[1] < size)
		{
			if (nbs[ij[1]] < nbs[smallest])
				smallest = ij[1];
		}
		tmp = nbs[ij[0]];
		nbs[ij[0]] = nbs[smallest];
		nbs[smallest] = tmp;
	}
}
