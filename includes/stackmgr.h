/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmgr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:00:02 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/06 16:55:58 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKMGR_H

# define STACKMGR_H

# include "ps_commons.h"

int		init_stack(t_stk *stack);
t_list	*pop_stack(t_stk *stack);
t_list	**push_stack(int nb, t_stk *stack);
void	free_stack(t_stk *stack);

// Remove
void	traverse_stack(t_stk *stack);
int		pop_and_clean_stack(t_stk *stack);

#endif