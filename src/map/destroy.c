/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osboxes <osboxes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:11:30 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/29 19:10:21 by osboxes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static void	free_tiles(t_map *map)
{
	unsigned int	i;
	t_tile			*tile;

	i = 0;
	while (i < map->height * map->width)
	{
		tile = map->tile[i];
		if (tile != NULL && tile->destroy == NULL)
			tile_default_destroy(tile);
		else if (tile != NULL && tile->destroy != NULL)
			tile->destroy(tile);
		free(tile);
		++i;
	}
	free(map->tile);
}

void	map_destroy(void)
{
	t_map	*map;

	map = _map();
	lst_destroy_nodes(&map->file.data, free);
	free_tiles(map);
	ft_bzero(map, sizeof(t_map));
}
