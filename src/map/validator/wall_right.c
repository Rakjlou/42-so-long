/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 22:03:01 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool	map_validator_wall_right(t_ftconfig *config, t_map *map)
{
	t_iter	iter;
	char	*line;
	size_t	len;

	(void)config;
	iter_init(&iter, &map->raw.data, DESC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		len = ft_strlen(line);
		if (line[len - 1] != TILE_WALL)
			return (map_error(iter.pos, E_WALL_RIGHT, line));
	}
	return (TRUE);
}
