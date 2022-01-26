/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:26:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 22:48:27 by nsierra-         ###   ########.fr       */
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

/* Singleton Access */
t_game		*_game(void);
t_map		*_map(void);
t_ftconfig	*_config(void);

t_bool	game_init(const char *mapfile);
void	game_destroy(void);

/* config/ */
t_bool	config_init(const char *config);

#endif
