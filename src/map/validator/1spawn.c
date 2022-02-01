/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1spawn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 14:42:43 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map_validation.h"

static void	update_player_position(unsigned int x, unsigned int y)
{
	_game()->player.pos.x = x;
	_game()->player.pos.y = y;
}

t_bool	map_validator_1spawn(t_map *map)
{
	unsigned int		count;
	unsigned int		i;
	t_iter				iter;
	char				*line;

	count = 0;
	iter_init(&iter, &map->file.data, DESC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		i = 0;
		while (line[i])
		{
			if (line[i] == TILE_SPAWN && ++count)
				update_player_position((unsigned int)iter.pos, i);
			++i;
		}
	}
	if (count == 1)
		return (TRUE);
	else if (count > 1)
		return (map_error(-1, E_MULT_SPAWN, NULL));
	return (map_error(-1, E_NO_SPAWN, NULL));
}
