# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:54:46 by nsierra-          #+#    #+#              #
#    Updated: 2022/01/18 15:54:19 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c \

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pedantic -ansi -I libft/ -I inc/
LDFLAGS = -L libft/
LDLIBS = -lft

all: libft $(NAME)

$(NAME): libft/libft.a $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

libft:
	make --no-print-directory -C libft/

clean:
	make --no-print-directory -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make --no-print-directory -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re libft
