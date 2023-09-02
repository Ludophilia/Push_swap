/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:51:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/02 21:22:32 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include "pusw_commons.h"
# include "stackmgr.h"

int		pusw_rev_rotate(t_stk *stack0, t_stk *stack1, t_list **instr_head);
int		pusw_rotate(t_stk *stack0, t_stk *stack1, t_list **instr_head);
int		pusw_push(t_stk *from_stack, t_stk *to_stack, t_list **instr_head);
int		pusw_swap(t_stk *stack0, t_stk *stack1, t_list **instr_head);

int		pusw_store_instr(char *type, char *stk_name, t_list **head);
int		pusw_deter_instr(char *type, t_stk *stk0, t_stk *stk1, t_list **head);
t_list	*pusw_lstseclast(t_list *lst);

#endif
