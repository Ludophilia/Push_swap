/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_commons.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:56:09 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/11 18:42:34 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_COMMONS_H

# define PUSHSWAP_COMMONS_H

# include "../libs/libft/includes/libft.h"
# include <limits.h>
# include <stdint.h>

typedef struct s_stk
{
	char	*name;
	t_list	**head;
	int		size;
}	t_stk;

typedef enum e_dir
{
	STRAIGHT,
	REVERSE
}	t_dir;

#endif
