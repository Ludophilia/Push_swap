/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:35:02 by jegerman          #+#    #+#             */
/*   Updated: 2025/02/11 17:44:54 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include "../libs/libft/includes/libft.h"
# include <limits.h>
# include <stdint.h>

# define STRAIGHT 0
# define REVERSE  1

typedef struct s_stk
{
	char	*name;
	t_list	**head;
	int		size;
}	t_stk;

long	cli_atol(char *str);
int		cli_is_nb_in_nbs(int nb, int *nbs, int size);
int		cli_set_subt_nbs(int **subt_nbs, int *ijk, int *nbs, int size);
void	cli_free_strs(char **strs);
int		cli_strslen(char **strs);
int		cli_project_init(int argc, char **argv, t_stk *stks[3], t_list**instrs);

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

t_stk	*stkmgr_stack_init(char *name);
int		stkmgr_stacks_init(int size, int *cli_nbs, t_stk *stacks[3]);
t_list	*stkmgr_stack_pop(t_stk *stack);
t_list	**stkmgr_stack_push(int nb, t_stk *stack);

void	stkmgr_stack_free(t_stk *stack);
void	stkmgr_free_ressources(t_stk **stacks, t_list **instrs);
int		stkmgr_stack_is_sorted(t_stk *stack, int rev);
void	stkmgr_get_minimum(int min[2], t_stk *stack);
int		stkmgr_is_min(int nb, t_stk *stack);

int		sort_get_pos_stk(int target, t_stk *stack);
int		sort_rotate_stk(int target[2], t_stk *stack, t_list **instrs);
int		sort_reset_stk(t_stk *stack, t_list **instrs);

int		sort_2nbs(t_stk *stack, t_list **instrs);
int		sort_upto_3nbs(t_stk *stack, t_list **instrs);
int		sort_upto_5nbs(t_stk **stacks, t_list **instrs);

int		sort100_presort(t_stk **stacks, int divider, t_list **instrs);
int		sort_upto_100nbs(t_stk **stacks, int divider, t_list **instrs);
int		sort_over_100nbs(t_stk **stacks, int divider, t_list **instrs);

int		sort_choose_algorithm(t_stk **stacks, t_list **instrs);

#endif