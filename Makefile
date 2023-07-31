# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 19:18:21 by jgermany          #+#    #+#              #
#    Updated: 2023/07/31 19:36:47 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SRCS_DIR := srcs/
INCL_DIR := includes/
FT := libs/libft

CC	:= cc
CFLAGS := -Wall -Wextra -Werror
all: CFLAGS += -I$(INCL_DIR)
LIBFLAGS += -lft -L$(FT)

SRCS := $(SRCS_DIR)/push_swap.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(FT) all
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

$(OBJS): $(INCL_DIR)/push_swap_commons.h
$(SRCS_DIR)/push_swap.o: $(INCL_DIR)/push_swap.h

clean:
	make -C $(FT) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(FT) fclean
	rm -f $(NAME)

re: fclean all

.SILENT: clean fclean
.PHONY: all re clean fclean
