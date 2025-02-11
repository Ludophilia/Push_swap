/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:50:17 by jegerman          #+#    #+#             */
/*   Updated: 2025/02/11 17:57:07 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS

# define PUSHSWAP_BONUS

# include "pushswap.h"

int	gameinst_push(t_stk *from_stack, t_stk *to_stack);
int	gameinst_swap(t_stk *stack0, t_stk *stack1);
int	gameinst_rotate(t_stk *stack0, t_stk *stack1);
int	gameinst_rev_rotate(t_stk *stack0, t_stk *stack1);

int	instmgr_get_instrs(t_list **instrs);

int	exc_execute_instrs(t_list **instrs, t_stk **stacks);

#endif