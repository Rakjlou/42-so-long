/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instanciate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osboxes <osboxes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:42:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 08:01:56 by osboxes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "errors.h"
#include "ftprintf.h"
#include "so_long.h"

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
		while (y < map->width)
		{
			index = (x * map->width) + y;
			map->tile[index] = tile_factory(line[y], x, y);
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
	map->tile = ft_calloc(sizeof(t_tile *), map->height * map->width);
	if (map->tile == NULL)
		return (fterr_set_error(FAILED_MALLOC), FALSE);
	return (TRUE);
}

t_bool	map_instanciate(void)
{
	t_map	*map;

	map = _map();
	return (map_init_tiles_tab(map) && map_tiles_init(map));
}
