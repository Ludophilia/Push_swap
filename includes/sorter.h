/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:07:03 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/16 18:36:17 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H

# define SORTER_H

# include "pushswap_commons.h"
# include "gamemgr.h"

int	sort_2nbs(t_stk *stack, t_list **instrs);
int	sort_upto_3nbs(t_stk *stack, t_list **instrs);
int	sort_upto_5nbs(t_stk *stackA, t_stk *stackB, t_list **instrs);
int	sort_upto_100nbs(t_stk **stacks, int divider, t_list **instrs);

#endif