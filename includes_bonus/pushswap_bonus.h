/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:50:17 by jegerman          #+#    #+#             */
/*   Updated: 2025/03/07 18:18:03 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS

# define PUSHSWAP_BONUS

# include "pushswap.h"

int	instmgr_get_instrs(t_list **instrs);

int	exc_execute_instrs(t_list **instrs, t_stk **stacks);

#endif