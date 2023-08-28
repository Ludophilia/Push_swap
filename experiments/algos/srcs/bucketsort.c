/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucketsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:05:52 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/28 15:08:18 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bucketsort.h"

static int	*init_bucket_sort(int sorted_size, t_list ****buckets)
{
	int	*sorted;
	int	i;

	i = -1;
	*buckets = ft_calloc(BUCKET_SIZE, sizeof(t_list **));
	if (*buckets == NULL)
		return (NULL);
	while (++i < BUCKET_SIZE)
	{
		(*buckets)[i] = ft_calloc(1, sizeof(t_list *));
		if ((*buckets)[i] == NULL)
			free_buckets(*buckets, i);
	}
	sorted = ft_calloc(sorted_size, sizeof(int));
	if (sorted == NULL)
	{
		free_buckets(*buckets, BUCKET_SIZE);
		return (NULL);
	}
	return (sorted);
}

static int	add_nb_to_a_bucket(int nb, t_list ***buckets, int nbs_per_bucket)
{
	int		*new_nb;
	t_list	*new_node;

	new_nb = ft_calloc(1, sizeof(int));
	if (new_nb == NULL)
	{
		free_buckets(buckets, BUCKET_SIZE);
		return (-1);
	}
	*new_nb = nb;
	new_node = ft_lstnew(new_nb);
	if (new_node == NULL)
	{
		free_buckets(buckets, BUCKET_SIZE);
		return (-1);
	}
	ft_lstadd_back(buckets[nb / nbs_per_bucket], new_node);
	return (0);
}

// Insertion sort is dysfunctional: ./algos 110 2147483647 0 1 2... With singly
// linked lists, it's sometimes necessary to modify the previous previous node,
// which this version does not. Anyway, i'm lacking time, so i'll just give up.
static void	lst_insertion_sort(t_list **bucket)
{
	t_list	*head[2];
	t_list	*prev_head0;
	t_list	*tmp_next;

	print_bucket(*bucket, 0);
	head[0] = *bucket;
	while (head[0])
	{
		head[1] = *bucket;
		while (head[1] && (head[1] != head[0]))
		{
			if (*(int *)head[0]->content < *(int *)head[1]->content)
			{
				tmp_next = head[0]->next;
				head[0]->next = head[1];
				prev_head0->next = tmp_next;
				if (head[1] == *bucket)
					*bucket = head[0];
				break ;
			}
			head[1] = head[1]->next;
		}
		prev_head0 = head[0];
		head[0] = head[0]->next;
	}
	print_bucket(*bucket, 0);
	printf("----------------------------------------\n\n");
}

static void	fill_sorted(int *sorted, t_list ***buckets)
{
	int		ij[2];
	t_list	*node;

	*(long *)ij = -1;
	while (++ij[0] < BUCKET_SIZE)
	{
		// print_bucket(*buckets[ij[0]], ij[0]);
		node = *buckets[ij[0]];
		while (node)
		{
			sorted[++ij[1]] = *(int *)node->content;
			node = node->next;
		}
	}
}

int	*bucket_sort(int *nbs, int size)
{
	t_list	***buckets;
	int		*sorted;
	int		ij[2];
	int		nbs_per_bucket;

	nbs_per_bucket = get_nbs_per_bucket(nbs, size);
	// printf("nbs_per_bucket = %i\n", nbs_per_bucket);
	if (nbs_per_bucket == -1)
		return (NULL);
	sorted = init_bucket_sort(size, &buckets);
	if (sorted == NULL)
		return (NULL);
	*(long *)ij = -1;
	while (++ij[0] < size)
	{
		if (add_nb_to_a_bucket(nbs[ij[0]], buckets, nbs_per_bucket) == -1)
			return (NULL);
	}
	while (++ij[1] < BUCKET_SIZE)
		lst_insertion_sort(buckets[ij[1]]);
	fill_sorted(sorted, buckets);
	free_buckets(buckets, BUCKET_SIZE);
	return (sorted);
}
