/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:34:35 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/18 20:16:00 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algos.h"

int	*cli_init_arr_from_args(int argc, char **argv)
{
	int	*nbs;
	int	i;

	nbs = ft_calloc(argc, sizeof(int));
	if (nbs == NULL)
		return (NULL);
	i = -1;
	while (argv[++i])
		nbs[i] = ft_atoi(argv[i]);
	return (nbs);
}

void	cli_print_nbs(int *arr, int size)
{
	int	*start;

	start = arr;
	while ((arr - start) < size)
		ft_printf("%i\n", *arr++);
}
