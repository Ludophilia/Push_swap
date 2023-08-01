# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 19:18:21 by jgermany          #+#    #+#              #
#    Updated: 2023/08/01 14:13:12 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SRCS_DIRM := srcs/
INCL_DIRM := includes/
FT := libs/libft

CC	:= cc
CFLAGS := -Wall -Wextra -Werror
all: CFLAGS += -I$(INCL_DIRM)
LIBFLAGS += -lft -L$(FT)

SRCS := $(SRCS_DIRM)/push_swap.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(FT) all
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

$(OBJS): $(INCL_DIRM)/ps_commons.h
$(SRCS_DIRM)/push_swap.o: $(INCL_DIRM)/push_swap.h

clean:
	make -C $(FT) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(FT) fclean
	rm -f $(NAME)

re: fclean all

.SILENT: clean fclean
.PHONY: all re clean fclean
