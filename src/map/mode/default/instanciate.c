/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instanciate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:42:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 01:39:23 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "errors.h"
#include "ftprintf.h"

static void	map_set_length_height(t_map *map)
{
	map->length = ft_strlen((char *)lst_data_at(&map->raw.data, 0));
	map->height = map->raw.data.size;
}

static t_bool	map_tiles_init(t_map *map)
{
	unsigned int	x;
	unsigned int	y;
	t_iter			iter;
	t_tile			*tile;
	char			*line;

	map->tile = ft_calloc(sizeof(t_tile), map->height * map->length);
	if (map->tile == NULL)
		return (fterr_set_error(FAILED_MALLOC), FALSE);
	x = 0;
	iter_init(&iter, &map->raw.data, ASC);
	while (iter_next(&iter))
	{
		y = 0;
		line = (char *)iter.data;
		while (y < map->length)
		{
			tile = map_tile_get(map, x, y);
			tile_init(tile, line[y], x, y);
			++y;
		}
		++x;
	}
	return (TRUE);
}

t_bool	map_mode_default_instanciate(t_map *map)
{
	map_set_length_height(map);
	return (map_tiles_init(map));
}
