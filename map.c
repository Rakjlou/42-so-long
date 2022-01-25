/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:32:57 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 01:30:49 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

static t_bool	verif_simple_map_line(char *line)
{
	static int	last_len = -1;
	int			len;
	int			i;

	i = 0;
	len = (int)ft_strlen(line);
	if (len <= 1 || (last_len > -1 && last_len != len))
		return (FALSE);
	else if (line[0] != TILE_WALL || line[len - 2] != TILE_WALL)
		return (FALSE);
	last_len = len;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (!ft_cvalid(line[i], SIMPLE_AUTHORIZED_CHARS))
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static t_bool	verif_simple_map_integrity(t_game *game, char *line)
{
	t_iter			iter;
	t_map_integrity	map;

	if (game->map.raw->size <= 1)
		return (FALSE);
	ft_bzero(&map, sizeof(t_map_integrity));
	iter_init(&iter, game->map.raw, ASC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		while (*line)
		{
			if ((*line == TILE_SPAWN && map.start == TRUE)
				|| (*line == TILE_EXIT && map.exit == TRUE))
				return (FALSE);
			else if (*line == TILE_SPAWN)
				map.start = TRUE;
			else if (*line == TILE_EXIT)
				map.exit = TRUE;
			else if (*line == TILE_COLLECTIBLE)
				map.collectible = TRUE;
			++line;
		}
	}
	return (map.collectible);
}

static t_bool	map_load_file(t_game *game, int fd)
{
	char	*line;

	game->map.raw = lst_new();
	if (game->map.raw == NULL)
		return (game_set_error(game, FAILED_MALLOC), FALSE);
	game_set_error(game, INVALID_MAP_LINE);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else if (lst_push_back(game->map.raw, line) == 0)
		{
			game_set_error(game, FAILED_MALLOC);
			return (free(line), gnl_close(fd), FALSE);
		}
		else if (game->map.mode == SIMPLE && !verif_simple_map_line(line))
			return (gnl_close(fd), FALSE);
	}
	gnl_close(fd);
	if (!verif_simple_map_integrity(game, NULL))
		return (game_set_error(game, INVALID_MAP), FALSE);
	return (TRUE);
}

t_bool	map_load(t_game *game, char *map_filename)
{
	int		fd;
	char	*map_mode;

	if (config_getb(game, "enforce_ber_extension")
		&& !ft_ends_with(map_filename, ".ber"))
		return (game_set_error(game, INVALID_MAP_FILENAME), FALSE);
	fd = open(map_filename, O_RDONLY);
	game->map.filename = map_filename;
	if (fd <= 0)
		return (game_set_error(game, MAP_FILE_OPEN), FALSE);
	game->map.mode = SIMPLE;
	map_mode = config_gets(game, "map_mode");
	if (map_mode != NULL && ft_strncmp(map_mode, "pro", UINT_MAX) == 0)
		game->map.mode = PRO;
	return (map_load_file(game, fd));
}

void	map_destroy(t_game *game)
{
	if (game->map.raw == NULL)
		return ;
	lst_destroy(&game->map.raw, free);
}
