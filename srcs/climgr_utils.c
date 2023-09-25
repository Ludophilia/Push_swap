/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climgr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:25:41 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/25 18:52:26 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "climgr.h"

void	cli_free_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

int	cli_strslen(char **strs)
{
	int	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
}

long	cli_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] >= '\t' && str[i] <= '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * res + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

int	cli_is_nb_in_nbs(int nb, int *nbs, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (nb == nbs[i])
			return (1);
	return (0);
}

int	cli_set_subt_nbs(int **subt_nbs_tmp, int *ijk, int *nbs, int size)
{
	ijk[0] = -1;
	ijk[2] = 0;
	subt_nbs_tmp[0] = ft_calloc(size, sizeof(int));
	if (subt_nbs_tmp[0] == NULL)
	{
		free(nbs);
		return (-1);
	}
	subt_nbs_tmp[1] = ft_calloc(size, sizeof(int));
	if (subt_nbs_tmp[1] == NULL)
	{
		free(nbs);
		free(*subt_nbs_tmp);
		return (-1);
	}
	return (0);
}
