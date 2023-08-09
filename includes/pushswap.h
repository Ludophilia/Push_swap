/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:51:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/09 14:58:02 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "pusw_commons.h"
# include "stackmgr.h"

void	pusw_rev_rotate(t_stk *stack0, t_stk *stack1);
void	pusw_rotate(t_stk *stack0, t_stk *stack1);
void	pusw_push(t_stk *from_stack, t_stk *to_stack);
void	pusw_swap(t_stk *stack0, t_stk *stack1);

#endif
