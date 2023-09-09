/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:07:03 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/09 12:52:07 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H

# define SORTER_H

# include "pushswap_commons.h"
# include "gamemgr.h"

int	sort_3nbs(t_stk *stackA, t_list **instrs);
int	sort_2nbs(t_stk *stack, t_list **instrs);
int	sort_upto_3nbs(t_stk *stack, t_list **instrs);

#endif