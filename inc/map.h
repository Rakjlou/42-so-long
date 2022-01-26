/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:36:46 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 01:39:14 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "ftconfig.h"
# include "tile.h"

# define E_ROWS "not enough rows"
# define E_COLS "not enough columns"
# define E_LINE_LEN "line does not match required length"
# define E_NO_COLLECTIBLE "no collectible found"
# define E_NO_EXIT "no exit found"
# define E_MULT_EXIT "too much exits found"
# define E_NO_SPAWN "no spawn found"
# define E_MULT_SPAWN "too much spawns found"
# define E_BER_EXTENSION "map file name must end with .ber"
# define E_WALL_BOTTOM "bottom line must be all walls"
# define E_WALL_TOP "top line must be all walls"
# define E_WALL_LEFT "left column must be all walls"
# define E_WALL_RIGHT "right column must be all walls"
# define E_INVALID_CHAR "line has an invalid char"

# define VALID_TILE_CHARS "10PEC"
# define TILE_WALL '1'
# define TILE_EMPTY '0'
# define TILE_SPAWN 'P'
# define TILE_EXIT 'E'
# define TILE_COLLECTIBLE 'C'

typedef struct s_map_raw
{
	const char	*filename;
	t_lst		data;
}	t_map_raw;

typedef struct s_map
{
	t_map_raw		raw;
	t_tile			*tile;
	unsigned int	length;
	unsigned int	height;
	t_bool			(*validate)(t_ftconfig *, struct s_map *);
	t_bool			(*instanciate)(struct s_map *);
	void			(*destroy)(struct s_map *);
}	t_map;

/* src/map/ */
t_bool		map_init(t_ftconfig *config, t_map *map, const char *filename);
t_bool		map_instanciate(t_map *map);
void		map_destroy(t_map *map);

t_tile		*map_tile_get(t_map *map, unsigned int x, unsigned int y);

#endif
