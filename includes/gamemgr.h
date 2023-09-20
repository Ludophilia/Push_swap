/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamemgr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:51:34 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/20 13:30:49 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEMGR_H

# define GAMEMGR_H

# include "pushswap_commons.h"
# include "stackmgr.h"

int		game_rev_rotate(t_stk *stack0, t_stk *stack1, t_list **instr_head);
int		game_rotate(t_stk *stack0, t_stk *stack1, t_list **instr_head);
int		game_push(t_stk *from_stack, t_stk *to_stack, t_list **instr_head);
int		game_swap(t_stk *stack0, t_stk *stack1, t_list **instr_head);

void	game_print_instrs(t_list *start);
int		game_choose_instr(char *type, t_stk *stk0, t_stk *stk1, t_list **head);
int		game_opti_instrs(t_list **instrs);

int		game_store_instr(char *type, char *stk_name, t_list **head);
int		game_cmp_inst(char *ins1, char *ins2, size_t len, char *strs[2]);
int		game_smp_inst(char *new, t_list *nodes[2], char *strs[2]);
t_list	*game_lstseclast(t_list *lst);

#endif
