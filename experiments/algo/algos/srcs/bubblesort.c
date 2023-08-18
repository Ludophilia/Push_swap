/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:14:22 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/18 20:15:41 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algos.h"

void	bubble_sort(int *nbs, int size)
{
	int	ij[2];
	int	tmp;

	ij[0] = -1;
	while (++ij[0] < size)
	{
		ij[1] = -1;
		while ((++ij[1] + 1) < (size - ij[0]))
		{
			if (nbs[ij[1]] > nbs[ij[1] + 1])
			{
				tmp = nbs[ij[1]];
				nbs[ij[1]] = nbs[ij[1] + 1];
				nbs[ij[1] + 1] = tmp;
			}
		}
	}
	return ;
}
