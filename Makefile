# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 19:18:21 by jgermany          #+#    #+#              #
#    Updated: 2025/03/14 15:27:28 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAME_BON := checker

FT := libs/libft

SRCS_DIRM := srcs
INCL_DIRM := includes
SRCS_DIRB := srcs_bonus
INCL_DIRB := includes_bonus

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
LIBFLAGS := -lft -L$(FT)

all: CFLAGS += -I$(INCL_DIRM)
bonus: CFLAGS += -I$(INCL_DIRM) -I$(INCL_DIRB)

SRCS := $(SRCS_DIRM)/main.c
SRCS += $(SRCS_DIRM)/climgr.c
SRCS += $(SRCS_DIRM)/climgr_utils.c
SRCS += $(SRCS_DIRM)/stackmgr.c
SRCS += $(SRCS_DIRM)/gamemgr.c
SRCS += $(SRCS_DIRM)/instrmgr.c
SRCS += $(SRCS_DIRM)/sorter_common.c
SRCS += $(SRCS_DIRM)/sorter_three.c
SRCS += $(SRCS_DIRM)/sorter_five.c
SRCS += $(SRCS_DIRM)/sorter_hundred.c
SRCS += $(SRCS_DIRM)/sorter_thousand.c
SRCS += $(SRCS_DIRM)/sorter_utils.c

SRCS_BON := $(SRCS_DIRB)/main_bonus.c
SRCS_BON += $(SRCS_DIRM)/climgr.c
SRCS_BON += $(SRCS_DIRM)/climgr_utils.c
SRCS_BON += $(SRCS_DIRM)/stackmgr.c
SRCS_BON += $(SRCS_DIRB)/stackmgr_bonus.c
SRCS_BON += $(SRCS_DIRM)/gamemgr.c
SRCS_BON += $(SRCS_DIRM)/instrmgr.c
SRCS_BON += $(SRCS_DIRB)/instrmgr_bonus.c
SRCS_BON += $(SRCS_DIRM)/sorter_utils.c

OBJS := $(SRCS:.c=.o)
OBJS_BON := $(SRCS_BON:.c=.o)

all :$(NAME)

bonus :$(NAME_BON)

$(NAME_BON) :$(OBJS_BON)
	make -C $(FT) all
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

$(NAME) :$(OBJS)
	make -C $(FT) all
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

%.o :$(INCL_DIRM)/pushswap.h

%_bonus.o :$(INCL_DIRM)/pushswap.h $(INCL_DIRB)/pushswap_bonus.h

clean:
	make -C $(FT) clean
	rm -f $(OBJS) $(OBJS_BON)

fclean: clean
	make -C $(FT) fclean
	rm -f $(NAME) $(NAME_BON)

re :fclean all

.SILENT :clean fclean
.PHONY :all re clean fclean
