/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:29:57 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 00:15:11 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/*
** Config files are read line by line. Empty lines are ignored.
** Each line will be split, and the result will be stored in a list.
*/
static t_bool	config_load_file(t_game *game)
{
	int		fd;
	char	*raw_line;
	char	**config_entry;

	fd = open(CONFIG_FILE, O_RDONLY);
	if (fd <= 0)
		return (game_set_error(game, CONFIG_FILE_OPEN), FALSE);
	while (42)
	{
		raw_line = get_next_line(fd);
		if (raw_line == NULL)
			break ;
		config_entry = ft_split(raw_line, " \t\n\r\v\f");
		free(raw_line);
		if (config_entry == NULL)
			return (gnl_close(fd), game_set_error(game, FAILED_MALLOC), FALSE);
		else if (config_entry[0] == NULL)
			free(config_entry);
		else if (lst_push_back(game->config, config_entry) == 0)
			return (gnl_close(fd), game_set_error(game, FAILED_MALLOC), FALSE);
	}
	gnl_close(fd);
	return (TRUE);
}

static void	config_destroy_entry(void *data)
{
	char	**entry;
	int		i;

	i = 0;
	if (data == NULL)
		return ;
	entry = (char **)data;
	while (entry[i] != NULL)
		free(entry[i++]);
	free(entry);
}

t_bool	config_load(t_game *game)
{
	game->config = lst_new();
	if (game->config == NULL)
		return (game_set_error(game, FAILED_MALLOC), FALSE);
	return (config_load_file(game));
}

void	config_destroy(t_game *game)
{
	if (game->config == NULL)
		return ;
	lst_destroy(&game->config, config_destroy_entry);
}
