/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 22:23:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ftconfig.h"
# include "map.h"

typedef struct s_game
{
	t_ftconfig	config;
	t_map		map;
}	t_game;

/* game/ */
t_bool	game_init(t_game *game, const char *mapfile);
void	game_destroy(t_game *game);

/* config/ */
t_bool	config_init(t_game *game, const char *mapfile);

#endif
