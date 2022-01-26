/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:38:21 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 01:40:50 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_tile	*map_tile_get(t_map *map, unsigned int x, unsigned int y)
{
	unsigned int	index;

	index = (x * map->length) + y;
	if (index > map->height * map->length)
		return (NULL);
	return (map->tile + index);
}
