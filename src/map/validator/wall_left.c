/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 22:55:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

t_bool	map_validator_wall_left(t_map *map)
{
	t_iter	iter;
	char	*line;

	iter_init(&iter, &map->file.data, DESC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		if (line[0] != TILE_WALL)
			return (map_error(iter.pos, E_WALL_LEFT, line));
	}
	return (TRUE);
}
