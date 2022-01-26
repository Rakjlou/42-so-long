/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_bottom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 00:56:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

t_bool	map_validator_wall_bottom(t_ftconfig *config, t_map *map)
{
	char	*line;
	int		i;

	(void)config;
	i = 0;
	line = (char *)lst_data_back(&map->raw.data);
	while (line[i] != '\n' && line[i])
	{
		if (line[i] != TILE_WALL)
			return (map_error(map->raw.data.size - 1, E_WALL_BOTTOM, line));
		++i;
	}
	return (TRUE);
}
