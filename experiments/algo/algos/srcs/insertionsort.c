/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:27:39 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/16 16:53:08 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algos.h"

void insertion_sort(int *nbs, int size)
{
	int	ij[2];
	int	tmp;

	ij[0] = -1;
	while (++ij[0] < size)
	{
		ij[1] = ij[0] + 1;
		while (--ij[1])
		{
			if (nbs[ij[1] - 1] > nbs[ij[1]])
			{
				tmp = nbs[ij[1] - 1];
				nbs[ij[1] - 1] = nbs[ij[1]];
				nbs[ij[1]] = tmp;
			}
		}
	}
}
