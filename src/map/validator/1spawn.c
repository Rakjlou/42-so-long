/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1spawn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 00:56:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

t_bool	map_validator_1spawn(t_ftconfig *config, t_map *map)
{
	t_iter	iter;
	char	*line;
	int		i;
	int		count;

	(void)config;
	count = 0;
	iter_init(&iter, &map->raw.data, DESC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		i = 0;
		while (line[i])
		{
			if (line[i] == TILE_SPAWN)
				++count;
			++i;
		}
	}
	if (count == 1)
		return (TRUE);
	else if (count > 1)
		return (map_error(-1, E_MULT_SPAWN, NULL));
	return (map_error(-1, E_NO_SPAWN, NULL));
}
