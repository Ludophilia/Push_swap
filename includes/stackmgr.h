/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmgr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:00:02 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/12 12:10:54 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKMGR_H

# define STACKMGR_H

# include "pusw_commons.h"

t_stk	*stkmgr_stack_init(char name);
t_list	*stkmgr_stack_pop(t_stk *stack);
t_list	**stkmgr_stack_push(int nb, t_stk *stack);
void	stkmgr_stack_free(t_stk *stack);
int		stkmgr_stacks_fill(int size, int *cli_nbs, t_stk *stacks[3]);

#endif