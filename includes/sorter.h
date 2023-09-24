/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:07:03 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/23 18:37:42 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H

# define SORTER_H

# include "pushswap_commons.h"
# include "gamemgr.h"

int	sort_get_pos_stk(int target, t_stk *stack);
int	sort_rotate_stk(int target[2], t_stk *stack, t_list **instrs);
int	sort_reset_stk(t_stk *stack, t_list **instrs);

int	sort_2nbs(t_stk *stack, t_list **instrs);
int	sort_upto_3nbs(t_stk *stack, t_list **instrs);
int	sort_upto_5nbs(t_stk **stacks, t_list **instrs);

int	sort100_presort(t_stk **stacks, int divider, t_list **instrs);
int	sort_upto_100nbs(t_stk **stacks, int divider, t_list **instrs);
int	sort_over_100nbs(t_stk **stacks, int divider, t_list **instrs);

int	sort_choose_algorithm(t_stk **stacks, t_list **instrs);

#endif