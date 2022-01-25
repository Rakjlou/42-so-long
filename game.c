/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:24:18 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 00:56:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

void	game_set_error(t_game *game, unsigned int error)
{
	game->error = error;
}

t_bool	game_init(t_game *game, char *map_filename)
{
	game->mlx.core = NULL;
	game->mlx.window = NULL;
	game->map.filename = NULL;
	game->map.raw = NULL;
	game->config = NULL;
	if (!config_load(game) || !map_load(game, map_filename))
		return (FALSE);
	if (config_getb(game, "init_mlx") == TRUE)
		mlx_start(game);
	return (TRUE);
}

void	game_destroy(t_game *game)
{
	if (config_getb(game, "init_mlx") == TRUE)
		mlx_destroy(game);
	config_destroy(game);
	map_destroy(game);
}
