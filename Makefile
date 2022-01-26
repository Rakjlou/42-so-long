# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:54:46 by nsierra-          #+#    #+#              #
#    Updated: 2022/01/26 15:36:17 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/main.c \
 	src/errors/register.c \
 	src/config/config.c \
 	src/game/init.c \
 	src/game/destroy.c \
 	src/game/render.c \
 	src/map/init.c \
 	src/map/error.c \
 	src/map/destroy.c \
 	src/map/get.c \
 	src/map/tile/init.c \
 	src/map/tile/state_factory.c \
	src/map/mode/default/init.c \
	src/map/mode/default/validate.c \
	src/map/mode/default/instanciate.c \
	src/map/mode/default/destroy.c \
	src/map/mode/pro/init.c \
	src/map/mode/pro/validate.c \
	src/map/mode/pro/instanciate.c \
	src/map/mode/pro/destroy.c \
	src/map/validator/1collectible.c \
	src/map/validator/1exit.c \
	src/map/validator/1spawn.c \
	src/map/validator/filename.c \
	src/map/validator/rectangle.c \
	src/map/validator/wall_bottom.c \
	src/map/validator/wall_left.c \
	src/map/validator/wall_right.c \
	src/map/validator/walls_surround.c \
	src/map/validator/wall_top.c \
	src/map/validator/valid_chars_only.c \

OBJ = $(SRC:.c=.o)

CC = gcc

LIBFT_DIR = libft
MLX_DIR = minilibx-linux

CFLAGS = -Wall -Wextra -Werror -pedantic -ansi -g3 \
			-I . \
			-I inc/ \
			-I $(LIBFT_DIR) \
			-I $(MLX_DIR)\

LDFLAGS = -L $(LIBFT_DIR) -lft \
			-L $(MLX_DIR) -lmlx \
			-L /usr/lib -lXext -lX11 -lm -lz \

LDLIBS = -lft

all: libft mlx $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

libft:
	make --no-print-directory -C $(LIBFT_DIR)

mlx:
	make --no-print-directory -C $(MLX_DIR)

clean:
	make --no-print-directory -C $(LIBFT_DIR) clean
	make --no-print-directory -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make --no-print-directory -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

test: all
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes \
	./so_long map/simple.ber

.PHONY: clean fclean re libft mlx
