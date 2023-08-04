/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:34:38 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/02 18:47:15 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memmove.h"

void print_arr(void *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		ft_printf("%i ", ((int *)arr)[i]);
	ft_printf("\n");
}

int	main(void)
{
	int	*arr;

	arr = (int[6]){1, 2, 3, 4, 5};
	print_arr(arr, 6);
	ft_memmove(arr + 1, arr, 5 * sizeof(int));
	*arr = 0;
	print_arr(arr, 6);
	ft_memmove(arr, arr + 1, 5 * sizeof(int));
	arr[5] = 0;
	print_arr(arr, 6);
	return (0);
}

