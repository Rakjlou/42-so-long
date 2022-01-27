/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:11:30 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/27 01:01:23 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static void	free_tiles(t_map *map)
{
	unsigned int	i;

	i = 0;
	while (i < map->height * map->length)
		free(map->tile[i++]);
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
