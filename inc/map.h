/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:36:46 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 23:55:19 by nsierra-         ###   ########.fr       */
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
# define E_BER_EXTENSION_CHEEKY "Oh really you tried that ?"
# define E_WALL_BOTTOM "bottom line must be all walls"
# define E_WALL_TOP "top line must be all walls"
# define E_WALL_LEFT "left column must be all walls"
# define E_WALL_RIGHT "right column must be all walls"
# define E_INVALID_CHAR "line has an invalid char"

# define VALID_TILE_CHARS "10PEC"
# define VALID_EXTRA_TILE_CHARS "10PEC<>v^"
# define NMY_CHARS "<>^v"
# define TILE_WALL '1'
# define TILE_EMPTY '0'
# define TILE_SPAWN 'P'
# define TILE_EXIT 'E'
# define TILE_COLLECTIBLE 'C'
# define TILE_NMY_HL '<'
# define TILE_NMY_HR '>'
# define TILE_NMY_VT '^'
# define TILE_NMY_VD 'v'

typedef struct s_map_file
{
	const char	*name;
	t_lst		data;
}	t_map_file;

typedef struct s_map
{
	t_map_file		file;
	t_tile			**tile;
	t_uvector		size;
	unsigned int	collectibles_count;
}	t_map;

t_map		*_map(void);

/* src/map/ */
t_bool		map_init(const char *filename);
t_bool		map_validate(void);
t_bool		map_instanciate(void);
void		map_destroy(void);

#endif
