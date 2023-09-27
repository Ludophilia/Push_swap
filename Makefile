# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 19:18:21 by jgermany          #+#    #+#              #
#    Updated: 2023/09/27 14:42:45 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 							:= push_swap
NAME_BON 						:= checker

FT 								:= libs/libft

SRCS_DIRM 						:= srcs
INCL_DIRM 						:= includes
SRCS_DIRB 						:= srcs_bonus
INCL_DIRB 						:= includes_bonus

CC								:= cc
CFLAGS 							:= -Wall -Wextra -Werror
LIBFLAGS 						:= -lft -L$(FT)
all: CFLAGS 					+= -I$(INCL_DIRM)
bonus: CFLAGS 					+= -I$(INCL_DIRB) -I$(INCL_DIRM)

SRCS 							:= $(SRCS_DIRM)/main.c
SRCS 							+= $(SRCS_DIRM)/gamemgr.c
SRCS 							+= $(SRCS_DIRM)/instrmgr.c
SRCS 							+= $(SRCS_DIRM)/instrmgr_utils.c
SRCS 							+= $(SRCS_DIRM)/stackmgr.c
SRCS 							+= $(SRCS_DIRM)/stackmgr_utils.c
SRCS 							+= $(SRCS_DIRM)/climgr.c
SRCS 							+= $(SRCS_DIRM)/climgr_utils.c
SRCS 							+= $(SRCS_DIRM)/sorter_common.c
SRCS 							+= $(SRCS_DIRM)/sorter_three.c
SRCS 							+= $(SRCS_DIRM)/sorter_five.c
SRCS 							+= $(SRCS_DIRM)/sorter_hundred.c
SRCS 							+= $(SRCS_DIRM)/sorter_thousand.c

SRCS_BON 						:= $(SRCS_DIRB)/main_bonus.c
SRCS_BON 						+= $(SRCS_DIRB)/instrmgr_bonus.c
SRCS_BON						+= $(SRCS_DIRM)/climgr.c
SRCS_BON 						+= $(SRCS_DIRM)/climgr_utils.c
SRCS_BON						+= $(SRCS_DIRM)/stackmgr.c
SRCS_BON 						+= $(SRCS_DIRM)/stackmgr_utils.c


OBJS 							:= $(SRCS:.c=.o)
OBJS_BON 						:= $(SRCS_BON:.c=.o)

all								:$(NAME)

bonus							:$(NAME_BON)

$(NAME_BON)						:$(OBJS_BON)
								make -C $(FT) all bonus
								$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

$(NAME)							:$(OBJS)
								make -C $(FT) all bonus
								$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

%.o								:$(INCL_DIRM)/pushswap_commons.h

$(SRCS_DIRM)/main.o				:$(INCL_DIRM)/main.h

$(SRCS_DIRM)/climgr.o			:$(INCL_DIRM)/climgr.h
$(SRCS_DIRM)/climgr_utils.o		:$(INCL_DIRM)/climgr.h
$(SRCS_DIRM)/gamemgr.o			:$(INCL_DIRM)/gamemgr.h
$(SRCS_DIRM)/instrmgr.o			:$(INCL_DIRM)/gamemgr.h
$(SRCS_DIRM)/instrmgr_utils.o	:$(INCL_DIRM)/gamemgr.h
$(SRCS_DIRM)/stackmgr.o			:$(INCL_DIRM)/stackmgr.h
$(SRCS_DIRM)/stackmgr_utils.o	:$(INCL_DIRM)/stackmgr.h
$(SRCS_DIRM)/sorter_common.o	:$(INCL_DIRM)/sorter.h
$(SRCS_DIRM)/sorter_three.o		:$(INCL_DIRM)/sorter.h
$(SRCS_DIRM)/sorter_five.o		:$(INCL_DIRM)/sorter.h
$(SRCS_DIRM)/sorter_hundred.o	:$(INCL_DIRM)/sorter.h
$(SRCS_DIRM)/sorter_thousand.o	:$(INCL_DIRM)/sorter.h

$(SRCS_DIRB)/main_bonus.o		:$(INCL_DIRB)/main_bonus.h

$(SRCS_DIRB)/instrmgr_bonus.o	:$(INCL_DIRB)/instrmgr_bonus.h

clean							:
								make -C $(FT) clean
								rm -f $(OBJS) $(OBJS_BON)

fclean							:clean
								make -C $(FT) fclean
								rm -f $(NAME) $(NAME_BON)

re								:fclean all

.SILENT							:clean fclean
.PHONY							:all re clean fclean
