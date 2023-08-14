# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 17:34:56 by jgermany          #+#    #+#              #
#    Updated: 2023/08/02 18:39:55 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := memmove

SRCS := memmove.c
OBJS := $(SRCS:.c=.o)
FT := ../../libs/libft

CC := cc
CFLAGS := -Wall -Wextra -Werror -I.
LIBFLAGS := -lft -L$(FT)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(FT) all
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

memmove.o: memmove.h

clean:
	make -C $(FT) clean
	rm -f $(OBJS)

fclean:
	make -C $(FT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: clean fclean
