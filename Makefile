# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:54:46 by nsierra-          #+#    #+#              #
#    Updated: 2022/01/31 14:17:57 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/main.c \
 	src/errors/register.c \
 	src/config/config.c \
 	src/renderer/init.c \
 	src/renderer/destroy.c \
 	src/mlx_callback/close.c \
 	src/mlx_callback/expose.c \
 	src/mlx_callback/key.c \
 	src/mlx_callback/loop.c \
 	src/mlx_callback/mouse.c \
 	src/game/init.c \
 	src/game/destroy.c \
 	src/game/singleton.c \
 	src/game/render.c \
 	src/image/init.c \
 	src/image/destroy.c \
 	src/image/render.c \
 	src/map/init.c \
 	src/map/error.c \
 	src/map/destroy.c \
 	src/map/instanciate.c \
 	src/map/validate.c \
 	src/map/tile/factory.c \
 	src/map/tile/as_tile.c \
 	src/map/tile/type/collectible.c \
 	src/map/tile/type/exit.c \
 	src/map/tile/type/floor.c \
 	src/map/tile/type/wall.c \
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
	./so_long map/bigger.ber

.PHONY: clean fclean re libft mlx
