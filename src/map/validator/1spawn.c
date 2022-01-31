/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1spawn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 22:55:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map_validation.h"

t_bool	map_validator_1spawn(t_map *map)
{
	t_iter	iter;
	char	*line;
	int		i;
	int		count;

	count = 0;
	iter_init(&iter, &map->file.data, DESC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		i = 0;
		while (line[i])
		{
			if (line[i] == TILE_SPAWN)
			{
				_game()->player.pos.x = (unsigned int)iter.pos;
				_game()->player.pos.y = (unsigned int)i;
				++count;
			}
			++i;
		}
	}
	if (count == 1)
		return (TRUE);
	else if (count > 1)
		return (map_error(-1, E_MULT_SPAWN, NULL));
	return (map_error(-1, E_NO_SPAWN, NULL));
}
