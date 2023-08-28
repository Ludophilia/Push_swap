# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 17:34:56 by jgermany          #+#    #+#              #
#    Updated: 2023/08/28 14:24:06 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := algos

SRCS_DIR := ./srcs
INCL_DIR := ./includes
FT_INCL_DIR := ../../libs/libft/includes

FT := ../../libs/libft

SRCS := $(SRCS_DIR)/main.c
SRCS += $(SRCS_DIR)/bubblesort.c
SRCS += $(SRCS_DIR)/cli.c
SRCS += $(SRCS_DIR)/selectionsort.c
SRCS += $(SRCS_DIR)/insertionsort.c
SRCS += $(SRCS_DIR)/mergesort.c
SRCS += $(SRCS_DIR)/countingsort.c
SRCS += $(SRCS_DIR)/bucketsort.c
SRCS += $(SRCS_DIR)/bucketsort_utils.c

OBJS := $(SRCS:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror
LIBFLAGS := -lft -L$(FT)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(FT) all
	make -C $(FT) bonus
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFLAGS)

%.o: %.c $(INCL_DIR)/algos.h $(INCL_DIR)/bucketsort.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(FT) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(FT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: clean fclean
