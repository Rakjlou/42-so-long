/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 22:33:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ftconfig.h"
# include "map.h"
# include "renderer.h"
# include "character.h"
# include "ui.h"

# define GAME_NAME "so_paint"

# ifdef __linux__
#  define KEYCODE_UP 65362
#  define KEYCODE_RIGHT 65363
#  define KEYCODE_DOWN 65364
#  define KEYCODE_LEFT 65361
#  define KEYCODE_SPACE 32
#  define KEYCODE_ESC 65307
# elif _APPLE_
#  define KEYCODE_UP 65362
#  define KEYCODE_RIGHT 65363
#  define KEYCODE_DOWN 65364
#  define KEYCODE_LEFT 65361
#  define KEYCODE_SPACE 32
#  define KEYCODE_ESC 65307
# else

const char	g_error_platform_not_supported[0];

# endif

typedef struct s_input
{
	t_bool	right;
	t_bool	left;
	t_bool	up;
	t_bool	down;
	t_bool	attack;
	t_bool	close;
}	t_input;

typedef struct s_game
{
	t_bool			end;
	char			*end_msg;
	t_ftconfig		config;
	t_map			map;
	t_renderer		renderer;
	t_character		player;
	t_input			input;
	t_ui			ui;
	t_character		**enemy;
}	t_game;

/* Singleton Access */
t_game		*_game(void);
t_ftconfig	*_config(void);

t_bool		game_init(const char *mapfile);
void		game_destroy(void);
int			game_render(void);

t_bool		config_init(const char *config);

int			close_callback(void);
int			loop_hook_callback(void);
int			expose_hook_callback(void);
int			mouse_hook_callback(int button, int x, int y);
int			key_hook_callback(int keycode);

#endif
