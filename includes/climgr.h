/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climgr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:36:06 by jgermany          #+#    #+#             */
/*   Updated: 2023/09/05 18:46:02 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIMGR_H

# define CLIMGR_H

# include "pushswap_commons.h"
# include "stackmgr.h"

long	cli_atol(char *str);
int		cli_is_nb_in_nbs(int nb, int *nbs, int size);
int		cli_set_subt_nbs(int **subt_nbs, int *ijk, int *nbs, int size);

int		cli_project_init(int argc, char **argv, t_stk *stks[3], t_list**instrs);

#endif
