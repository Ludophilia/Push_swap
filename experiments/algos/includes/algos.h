/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:03:09 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/25 15:21:23 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGOS_H

# define ALGOS_H

# include "../../../../libs/libft/includes/libft.h"

int		*cli_init_arr_from_args(int argc, char **argv);
void	cli_print_nbs(int *arr, int size);

void	bubble_sort(int *nbs, int size);
void	selection_sort(int *nbs, int size);
void 	insertion_sort(int *nbs, int size);

int		*merge_sort(int *nbs, int size);
int		*stable_counting_sort(int *nbs, int size);

#endif