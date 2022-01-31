/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:11:30 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:30:50 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static void	free_tiles(t_map *map)
{
	unsigned int	i;
	t_tile			*tile;

	i = 0;
	while (i < map->size.x * map->size.y)
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
