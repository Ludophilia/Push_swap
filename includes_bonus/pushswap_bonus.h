/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:50:17 by jegerman          #+#    #+#             */
/*   Updated: 2025/03/15 17:26:27 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H

# define PUSHSWAP_BONUS_H

# include "pushswap.h"

typedef int	(*t_hdl)(t_stk *, t_stk *, t_psw *);

int	imgr_load_instrs(t_psw *game);
int	imgr_is_instr(char *inst_name, size_t inst_len, char *inst_refs, ...);
int	stkmgr_exec_instrs(t_psw *game);

#endif
