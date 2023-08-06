# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 19:18:21 by jgermany          #+#    #+#              #
#    Updated: 2023/08/06 16:39:38 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := test

TESTS_DIRM := .
SRCS_DIRM := ../srcs
INCL_DIRM := ../includes
FT := ../libs/libft

CC	:= cc
CFLAGS := -Wall -Wextra -Werror
all: CFLAGS += -I$(INCL_DIRM)
LIBFLAGS += -lft -L$(FT)

SRCS := $(TESTS_DIRM)/main.c
SRCS += $(SRCS_DIRM)/stackmgr.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(FT) bonus
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

$(OBJS): $(INCL_DIRM)/ps_commons.h
$(TESTS_DIRM)/main.o: $(INCL_DIRM)/push_swap.h
$(SRCS_DIRM)/stackmgr.o: $(INCL_DIRM)/stackmgr.h

clean:
	make -C $(FT) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(FT) fclean
	rm -f $(NAME)

re: fclean all

.SILENT: clean fclean
.PHONY: all re clean fclean
