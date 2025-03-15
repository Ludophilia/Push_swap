/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climgr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:25:41 by jgermany          #+#    #+#             */
/*   Updated: 2025/02/12 18:13:26 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	cli_free_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

int	cli_init_ranked_nbs(int **ranked, long *nbs, int size)
{
	*ranked = ft_calloc(size, sizeof(int));
	if (*ranked == NULL)
	{
		free(nbs);
		return (-1);
	}
	return (0);
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
