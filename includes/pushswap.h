/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:35:02 by jegerman          #+#    #+#             */
/*   Updated: 2025/02/23 17:40:17 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include "../libs/libft/includes/libft.h"
# include <limits.h>
# include <stdint.h>

typedef enum e_code
{
	DIR_REVERSE,
	DIR_STRAIGHT = (1 << 0),
	ID_STK_A = (1 << 8),
	ID_STK_B = (1 << 9)
}	t_code;

typedef struct s_stk
{
	int		id;
	char	*name;
	t_list	*head;
	int		size;
}	t_stk;

typedef struct s_psw
{
	t_stk	*stack_a;
	t_stk	*stack_b;
	t_list	*instrs;
	t_stk	_stack_a;
	t_stk	_stack_b;
}	t_psw;

typedef struct s_pnbr
{
	long	nb;
	int		pos;
}	t_pnbr;

typedef struct s_ctr
{
	long	i;
	long	j;
	long	k;
}	t_ctr;

typedef struct s_extr
{
	long	min;
	long	max;
}	t_extr;

long	cli_atol(char *str);
int		cli_init_ranked_nbs(int **ranked, long *nbs, int size);
void	cli_free_strs(char **strs);
int		cli_strslen(char **strs);
int		cli_project_init(int argc, char **argv, t_psw *game);

int		stkmgr_stacks_init(int *ranked, int size, t_psw *game);
t_list	*stkmgr_stack_pop(t_stk *stack);
void	stkmgr_free_ressources(t_psw *game);
int		stkmgr_stack_is_sorted(t_stk *stack, int order);
// int		stkmgr_is_min(int nb, t_stk *stack);

int		game_rev_rotate(t_stk *stack0, t_stk *stack1, t_psw *game);
int		game_rotate(t_stk *stack0, t_stk *stack1, t_psw *game);
int		game_push(t_stk *from_stack, t_stk *to_stack, t_psw *game);
int		game_swap(t_stk *stack0, t_stk *stack1, t_psw *game);

// int		insmgr_opti_instrs(t_list **instrs);
int		insmgr_choose_instr(char *type, t_stk *stack0, t_stk *stack1,
		t_psw *game);
int		insmgr_store_instr(char *type, char *name, t_psw *game);

int		sort_get_nbpos(t_pnbr *target, t_stk *stack);
int		sort_rotate_stk(t_pnbr *target, t_stk *stack, t_psw *game);
int		sort_reset_stk(t_stk *stack, t_psw *game);

int		sort_2nbs(t_stk *stack, t_psw *game);
int		sort_upto_3nbs(t_stk *stack_a, t_psw *game);
int		sort_upto_5nbs(t_stk* stack_a, t_stk* stack_b, t_psw *game);

// int		sort100_presort(t_psw *game, int divider);
// int		sort_upto_100nbs(t_psw *game, int divider);
// int		sort_over_100nbs(t_psw *game, int divider);

int		sort_choose_algorithm(t_psw *game);

#endif