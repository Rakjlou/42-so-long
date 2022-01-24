/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:25:14 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/24 23:27:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

void	mlx_start(t_game *game)
{
	t_mlx	*mlx;

	mlx = &game->mlx;
	mlx->core = mlx_init();
	mlx->window = mlx_new_window(mlx->core, 1920, 1080, "so_long nsierra-");
}

void	mlx_destroy(t_game *game)
{
	t_mlx	*mlx;

	mlx = &game->mlx;
	if (mlx->core == NULL)
		return ;
	mlx_destroy_window(mlx->core, mlx->window);
	mlx_destroy_display(mlx->core);
	free(mlx->core);
}
