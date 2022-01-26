/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 22:55:58 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"
#include "libft.h"
#include "ftprintf.h"

t_bool	map_validator_rectangle(t_map *map)
{
	size_t					map_line_len;
	size_t					len;
	t_iter					iter;
	char					*line;

	if (map->file.data.size <= 1)
		return (map_error(-1, E_ROWS, NULL));
	map_line_len = ft_strlen((char *)lst_data_at(&map->file.data, 0));
	iter_init(&iter, &map->file.data, DESC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		len = ft_strlen(line);
		if (len <= 1)
			return (map_error(iter.pos, E_COLS, line));
		else if (len != map_line_len)
		{
			return (map_error(iter.pos,
					E_LINE_LEN,
					line));
		}
	}
	return (TRUE);
}
