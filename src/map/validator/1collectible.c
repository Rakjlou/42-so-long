/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1collectible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 19:01:34 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"
#include "so_long.h"

t_bool	map_validator_1collectible(t_map *map)
{
	t_iter			iter;
	char			*line;
	int				i;
	unsigned int	count;

	count = 0;
	iter_init(&iter, &map->file.data, DESC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		i = 0;
		while (line[i])
		{
			if (line[i] == TILE_COLLECTIBLE)
				++count;
			++i;
		}
	}
	if (count > 0)
	{
		_map()->collectibles_count = count;
		_game()->collectibles_total = count;
		return (TRUE);
	}
	return (map_error(-1, E_NO_COLLECTIBLE, NULL));
}
