/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:24:18 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/24 21:59:27 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>

void	game_init(t_game *game)
{
	t_mlx	*mlx;

	mlx = &game->mlx;
	mlx->core = mlx_init();
	mlx->window = mlx_new_window(mlx->core, 1920, 1080, "Hello world!");
}

void	game_destroy(t_game *game)
{
	t_mlx	*mlx;

	mlx = &game->mlx;
	mlx_destroy_window(mlx->core, mlx->window);
	mlx_destroy_display(mlx->core);
	free(mlx->core);
}
