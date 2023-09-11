# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 19:18:21 by jgermany          #+#    #+#              #
#    Updated: 2023/09/11 19:13:08 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 							:= push_swap

SRCS_DIRM 						:= srcs
INCL_DIRM 						:= includes
FT 								:= libs/libft

CC								:= cc
CFLAGS 							:= -Wall -Wextra -Werror
all: CFLAGS 					+= -I$(INCL_DIRM)
LIBFLAGS 						:= -lft -L$(FT)

SRCS 							:= $(SRCS_DIRM)/main.c
SRCS 							+= $(SRCS_DIRM)/gamemgr.c
SRCS 							+= $(SRCS_DIRM)/gamemgr_utils.c
SRCS 							+= $(SRCS_DIRM)/stackmgr.c
SRCS 							+= $(SRCS_DIRM)/stackmgr_utils.c
SRCS 							+= $(SRCS_DIRM)/climgr.c
SRCS 							+= $(SRCS_DIRM)/climgr_utils.c
SRCS 							+= $(SRCS_DIRM)/sorter_three.c
SRCS 							+= $(SRCS_DIRM)/sorter_five.c

OBJS 							:= $(SRCS:.c=.o)

all								:$(NAME)

$(NAME)							:$(OBJS)
								make -C $(FT) all
								make -C $(FT) bonus
								$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

%.o								:$(INCL_DIRM)/pushswap_commons.h
$(SRCS_DIRM)/climgr_utils.o		:$(INCL_DIRM)/climgr.h
$(SRCS_DIRM)/climgr.o			:$(INCL_DIRM)/climgr.h
$(SRCS_DIRM)/gamemgr_utils.o	:$(INCL_DIRM)/gamemgr.h
$(SRCS_DIRM)/gamemgr.o			:$(INCL_DIRM)/gamemgr.h
$(SRCS_DIRM)/main.o				:$(INCL_DIRM)/main.h
$(SRCS_DIRM)/stackmgr_utils.o	:$(INCL_DIRM)/stackmgr.h
$(SRCS_DIRM)/stackmgr.o			:$(INCL_DIRM)/stackmgr.h
$(SRCS_DIRM)/sorter_three.o		:$(INCL_DIRM)/sorter.h
$(SRCS_DIRM)/sorter_five.o		:$(INCL_DIRM)/sorter.h

clean							:
								make -C $(FT) clean
								rm -f $(OBJS)

fclean							:clean
								make -C $(FT) fclean
								rm -f $(NAME)

re								:fclean all

.SILENT							:clean fclean
.PHONY							:all re clean fclean
