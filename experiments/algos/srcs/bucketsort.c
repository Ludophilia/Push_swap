/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucketsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:05:52 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/27 23:24:49 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bucketsort.h"

static void	fill_sorted(int *sorted, t_list ***buckets, int buck_size)
{
	int		ij[2];
	t_list	*node;

	*(long *)ij = -1;
	while (++ij[0] < buck_size)
	{
		node = *buckets[ij[0]];
		while (node)
		{
			sorted[++ij[1]] = *(int *)node->content;
			node = node->next;
		}
	}
}

static int	add_nb_to_a_bucket(int nb, t_list ***buckets, int buck_size)
{
	int		*new_nb;
	t_list	*new_node;

	new_nb = ft_calloc(1, sizeof(int));
	if (new_nb == NULL)
	{
		free_buckets(buckets, buck_size);
		return (-1);
	}
	*new_nb = nb;
	new_node = ft_lstnew(new_nb);
	if (new_node == NULL)
	{
		free_buckets(buckets, buck_size);
		return (-1);
	}
	ft_lstadd_back(buckets[nb / 10], new_node);
	return (0);
}

static int	*init_bucket_sort(int *nbs, int size, t_list ****buckets,
int *buck_size)
{
	int	*sorted;
	int	i;

	i = -1;
	*buck_size = get_size_freq_arr2(nbs, size) / 10 + 1;
	if (*buck_size == 1)
		return (NULL);
	*buckets = ft_calloc(*buck_size, sizeof(t_list **));
	if (*buckets == NULL)
		return (NULL);
	while (++i < *buck_size)
	{
		(*buckets)[i] = ft_calloc(1, sizeof(t_list *));
		if ((*buckets)[i] == NULL)
			free_buckets(*buckets, i);
	}
	sorted = ft_calloc(size, sizeof(int));
	if (sorted == NULL)
	{
		free_buckets(*buckets, *buck_size);
		return (NULL);
	}
	return (sorted);
}

static void	lst_insertion_sort(t_list **bucket)
{
	t_list	*head[2];
	t_list	*prev_head0;
	t_list	*tmp_next;

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
}

// What a memory hog, especially with big numbers like 21474836. And it was so 
// difficult to implement... But it's faster than quicksort...
int	*bucket_sort(int *nbs, int size)
{
	t_list	***buckets;
	int		buck_size;
	int		*sorted;
	int		ij[2];

	sorted = init_bucket_sort(nbs, size, &buckets, &buck_size);
	if (sorted == NULL)
		return (NULL);
	*(long *)ij = -1;
	while (++ij[0] < size)
	{
		if (add_nb_to_a_bucket(nbs[ij[0]], buckets, buck_size) == -1)
			return (NULL);
	}
	while (++ij[1] < buck_size)
		lst_insertion_sort(buckets[ij[1]]);
	fill_sorted(sorted, buckets, buck_size);
	free_buckets(buckets, buck_size);
	return (sorted);
}
