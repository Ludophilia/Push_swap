/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:50:17 by jegerman          #+#    #+#             */
/*   Updated: 2025/03/13 18:52:51 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS

# define PUSHSWAP_BONUS

# include "pushswap.h"

typedef int (*t_hdl)(t_stk *, t_stk *, t_psw *);

int	imgr_load_instrs(t_psw *game);
int	imgr_chk_instr(char *inst_name, size_t inst_len, char *inst_refs,
	...);
int	stkmgr_exec_instrs(t_psw *game);

#endif
