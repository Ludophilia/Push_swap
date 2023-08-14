# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 17:34:56 by jgermany          #+#    #+#              #
#    Updated: 2023/08/14 21:21:41 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := algos

SRCS_DIR := ./srcs
INCL_DIR := ./includes
FT_INCL_DIR := ../../../libs/libft/includes

FT := ../../../libs/libft

SRCS := $(SRCS_DIR)/algos.c
OBJS := $(SRCS:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror
# CFLAGS += -I$(INCL_DIR) -I$(FT_INCL_DIR)
LIBFLAGS := -lft -L$(FT)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(FT) all
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

$(SRCS_DIR)/algos.o: $(INCL_DIR)/algos.h

clean:
	make -C $(FT) clean
	rm -f $(OBJS)

fclean:
	make -C $(FT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: clean fclean
