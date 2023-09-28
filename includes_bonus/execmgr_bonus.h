/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execmgr_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:59:37 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/28 13:04:42 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECMGR_BONUS_H

# define EXECMGR_BONUS_H

# include "gamemgr_bonus.h"
# include "pushswap_commons.h"

int	exc_execute_instrs(t_list **instrs, t_stk **stacks);

#endif