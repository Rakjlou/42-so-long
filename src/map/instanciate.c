/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instanciate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:42:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/27 00:40:36 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "errors.h"
#include "ftprintf.h"
#include "so_long.h"

static void	map_set_length_height(t_map *map)
{
	map->length = ft_strlen((char *)lst_data_at(&map->file.data, 0));
	map->height = map->file.data.size;
}

static t_bool	map_tiles_init(t_map *map)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	index;
	t_iter			iter;
	char			*line;

	x = 0;
	iter_init(&iter, &map->file.data, ASC);
	while (iter_next(&iter))
	{
		y = 0;
		line = (char *)iter.data;
		while (y < map->length)
		{
			index = (x * map->length) + y;
			map->tile[index] = tile_factory(line[y]);
			if (map->tile[index] == NULL)
				return (fterr_set_error(FAILED_MALLOC), FALSE);
			++y;
		}
		++x;
	}
	return (TRUE);
}

static t_bool	map_init_tiles_tab(t_map *map)
{
	map->tile = ft_calloc(sizeof(t_tile *), map->height * map->length);
	if (map->tile == NULL)
		return (fterr_set_error(FAILED_MALLOC), FALSE);
	return (TRUE);
}

t_bool	map_instanciate(void)
{
	t_map	*map;

	map = _map();
	map_set_length_height(map);
	return (map_init_tiles_tab(map) && map_tiles_init(map));
}
