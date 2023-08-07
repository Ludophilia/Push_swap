/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_commons.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:56:09 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/07 17:30:41 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSW_COMMONS_H

# define PUSW_COMMONS_H

# include "../libs/libft/libft.h"
# include <stdarg.h>

typedef struct s_stk
{
	char	name;
	t_list	**head;
	int		size;
}	t_stk;

#endif
