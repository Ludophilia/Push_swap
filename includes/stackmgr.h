/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmgr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:00:02 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/07 14:45:44 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKMGR_H

# define STACKMGR_H

# include "pusw_commons.h"

t_stk	*mgr_stack_init(char name);
t_list	*mgr_stack_pop(t_stk *stack);
t_list	**mgr_stack_push(int nb, t_stk *stack);
void	mgr_stack_free(t_stk *stack);

// Remove
void	traverse_stack(t_stk *stack);
int		pop_and_clean_stack(t_stk *stack);

#endif