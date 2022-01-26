/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_bottom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 22:55:11 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

t_bool	map_validator_wall_bottom(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *)lst_data_back(&map->file.data);
	while (line[i] != '\n' && line[i])
	{
		if (line[i] != TILE_WALL)
			return (map_error(map->file.data.size - 1, E_WALL_BOTTOM, line));
		++i;
	}
	return (TRUE);
}
