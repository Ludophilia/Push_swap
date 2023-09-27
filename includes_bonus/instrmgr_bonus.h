/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrmgr_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:17:00 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/27 18:14:42 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRMGR_BONUS_H

# define INSTRMGR_BONUS_H

# include "stackmgr.h"
# include "pushswap_commons.h"

int	instmgr_get_instrs(t_list **instrs);

int	instr_push(t_stk *from_stack, t_stk *to_stack);
int	instr_swap(t_stk *stack0, t_stk *stack1);
int	instr_rotate(t_stk *stack0, t_stk *stack1);
int	instr_rev_rotate(t_stk *stack0, t_stk *stack1);

#endif