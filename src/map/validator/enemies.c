/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 14:43:14 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"
#include "so_long.h"
#include "errors.h"
#include "ftprintf.h"

static t_bool	init_enemy_array(int count)
{
	t_game		*game;

	if (count == 0)
		return (TRUE);
	game = _game();
	game->enemy = ft_calloc(sizeof(t_character *), count + 1);
	if (game->enemy == NULL)
		return (fterr_set_error(FAILED_MALLOC), FALSE);
	return (TRUE);
}

t_bool	map_validator_enemies(t_map *map)
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
			if (ft_cvalid(line[i], NMY_CHARS))
				++count;
			++i;
		}
	}
	return (init_enemy_array(count));
}
