/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucketsort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:03:58 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/27 23:16:43 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bucketsort.h"

void	print_bucket(t_list *bucket, int number)
{
	printf("Bucket #%i\n", number);
	if (!bucket)
	{
		printf("(Empty)\n\n");
		return ;
	}
	while (bucket)
	{
		ft_printf("%i\n", *(int *)bucket->content);
		bucket = bucket->next;
	}
	printf("\n");
}

int	get_size_freq_arr2(int *nbs, int size)
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

void	free_buckets(t_list ***buckets, int buck_size)
{
	int	i;

	i = 0;
	while ((i < buck_size) && buckets[i])
	{
		ft_lstclear(buckets[i], free);
		free(buckets[i]);
		i++;
	}
	free(buckets);
}
