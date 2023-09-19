/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmgr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:00:02 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/19 13:44:26 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKMGR_H

# define STACKMGR_H

# include "pushswap_commons.h"

t_stk	*stkmgr_stack_init(char *name);
int		stkmgr_stacks_init(int size, int *cli_nbs, t_stk *stacks[3]);
t_list	*stkmgr_stack_pop(t_stk *stack);
t_list	**stkmgr_stack_push(int nb, t_stk *stack);

void	stkmgr_stack_free(t_stk *stack);
void	stkmgr_free_ressources(t_stk **stacks, t_list **instrs);
int		stkmgr_stack_is_sorted(t_stk *stack, int rev);
void	stkmgr_get_minimum(int min[2], t_stk *stack);

#endif