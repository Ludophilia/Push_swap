/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucketsort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:12:30 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/28 14:04:33 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUCKETSORT_H

# define BUCKETSORT_H

# include "../includes/algos.h"
# define BUCKET_SIZE 10

void	print_bucket(t_list *bucket, int number);
void	free_buckets(t_list ***buckets, int buck_size);
int		get_nbs_per_bucket(int *nbs, int size);

#endif