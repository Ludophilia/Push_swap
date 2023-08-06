/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commons.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:56:09 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/06 13:38:39 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_COMMONS_H

# define PS_COMMONS_H

# include "../libs/libft/libft.h"

typedef struct s_stk
{
	t_list	**head;
	int		size;
}	t_stk;

#endif