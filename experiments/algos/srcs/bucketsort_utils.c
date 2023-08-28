/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucketsort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:03:58 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/28 14:28:54 by jgermany         ###   ########.fr       */
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

int	get_nbs_per_bucket(int *nbs, int size)
{
	long	max;
	int		i;
	int 	nbs_per_bucket;

	i = -1;
	max = 0;
	while (++i < size)
	{
		if (nbs[i] < 0)
			return (-1);
		if (nbs[i] > max)
			max = nbs[i];
	}
	max += 1;
	nbs_per_bucket = (max / BUCKET_SIZE) + 1;
	return (nbs_per_bucket);
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
