/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucketsort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:12:30 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/27 23:19:10 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUCKETSORT_H

# define BUCKETSORT_H

# include "../../../libs/libft/includes/libft.h"
# include "../includes/algos.h"

void	print_bucket(t_list *bucket, int number);
int		get_size_freq_arr2(int *nbs, int size);
void	free_buckets(t_list ***buckets, int buck_size);

#endif