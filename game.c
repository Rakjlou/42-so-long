/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:24:18 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/24 22:56:30 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

void	game_set_error(t_game *game, unsigned int error)
{
	game->error = error;
}

t_bool	game_init(t_game *game)
{
	game->mlx.core = NULL;
	game->mlx.window = NULL;
	game->config = NULL;
	if (!config_load(game))
		return (FALSE);
	mlx_start(game);
	return (TRUE);
}

void	game_destroy(t_game *game)
{
	config_destroy(game);
	mlx_destroy(game);
}
