/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instanciate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:42:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 14:34:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "errors.h"
#include "ftprintf.h"
#include "so_long.h"
#include "libft.h"

static t_bool	map_tiles_init(t_map *map)
{
	unsigned int	x;
	unsigned int	y;
	t_iter			iter;
	char			*line;

	x = 0;
	iter_init(&iter, &map->file.data, ASC);
	while (iter_next(&iter))
	{
		y = 0;
		line = (char *)iter.data;
		while (y < map->size.y)
		{
			map->tile[(x * map->size.y) + y] = tile_factory(line[y], x, y);
			if (map->tile[(x * map->size.y) + y] == NULL)
				return (fterr_set_error(FAILED_MALLOC), FALSE);
			else if (ft_cvalid(line[y], NMY_CHARS) && !enemy_add(line[y], x, y))
				return (FALSE);
			++y;
		}
		++x;
	}
	return (TRUE);
}

static t_bool	map_init_tiles_tab(t_map *map)
{
	map->tile = ft_calloc(sizeof(t_tile *), map->size.x * map->size.y);
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
