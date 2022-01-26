/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars_only.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/27 00:27:48 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"
#include "so_long.h"

t_bool	map_validator_valid_chars_only(t_map *map)
{
	t_iter	iter;
	char	*line;
	int		i;

	if (ftconfig_get_boolean(_config(), "extra_tiles") == FALSE)
		return (TRUE);
	iter_init(&iter, &map->file.data, DESC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		i = 0;
		while (line[i])
		{
			if (!ft_cvalid(line[i], VALID_TILE_CHARS))
				return (map_error(iter.pos, E_INVALID_CHAR, line));
			++i;
		}
	}
	return (TRUE);
}
