/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/24 23:28:04 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ftlst.h"

# define CONFIG_FILE "config.txt"

# define ERROR_MSG "Error"

typedef enum e_error
{
	USAGE,
	CONFIG_FILE_OPEN,
	FAILED_MALLOC
}	t_error;

typedef struct s_mlx
{
	void	*core;
	void	*window;
}	t_mlx;

typedef struct s_game
{
	t_mlx	mlx;
	t_lst	*config;
	t_error	error;
}	t_game;

/* game.c */
t_bool	game_init(t_game *game);
void	game_destroy(t_game *game);
void	game_set_error(t_game *game, t_error error);

/* config.c */
t_bool	config_load(t_game *game);
void	config_destroy(t_game *game);

/* config_get.c */
char	**config_get(t_game *game, const char *entry_name);
char	*config_gets(t_game *game, const char *entry_name);
t_bool	config_getb(t_game *game, const char *entry_name);

/* mlx.c */
void	mlx_start(t_game *game);
void	mlx_destroy(t_game *game);

#endif
