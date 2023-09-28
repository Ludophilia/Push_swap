/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamemgr_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:56:30 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/28 13:08:04 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEMGR_BONUS_H

# define GAMEMGR_BONUS_H

# include "stackmgr.h"
# include "pushswap_commons.h"

int	gameinst_push(t_stk *from_stack, t_stk *to_stack);
int	gameinst_swap(t_stk *stack0, t_stk *stack1);
int	gameinst_rotate(t_stk *stack0, t_stk *stack1);
int	gameinst_rev_rotate(t_stk *stack0, t_stk *stack1);

#endif