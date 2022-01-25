/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1collectible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 21:25:41 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool	map_validator_1collectible(t_ftconfig *config, t_map *map)
{
	t_iter	iter;
	char	*line;
	int		i;

	(void)config;
	iter_init(&iter, &map->raw.data, DESC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		i = 0;
		while (line[i])
		{
			if (line[i] == TILE_COLLECTIBLE)
				return (TRUE);
			++i;
		}
	}
	return (map_error(-1, E_NO_COLLECTIBLE, NULL));
}