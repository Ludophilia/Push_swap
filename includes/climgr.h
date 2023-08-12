/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climgr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:36:06 by jgermany          #+#    #+#             */
/*   Updated: 2023/08/12 13:01:34 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIMGR_H

# define CLIMGR_H

# include "pusw_commons.h"
# include "stackmgr.h"

int		cli_check_if_full_digits(char **args);
int		*cli_integerize_args(int argc, char **argv);
int		cli_project_init(int argc, char **argv, t_stk *stacks[3]);

#endif
