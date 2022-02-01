/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:57:28 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 14:41:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errors.h"
#include "mlx.h"

void	renderer_clear_window(void)
{
	t_renderer	*renderer;

	renderer = _renderer();
	mlx_clear_window(renderer->core, renderer->window);
}

t_bool	renderer_init(void)
{
	t_renderer	*renderer;
	t_map		*map;

	renderer = _renderer();
	map = _map();
	renderer->core = mlx_init();
	if (renderer->core == NULL)
		return (fterr_set_error(MLX_FAILURE), FALSE);
	renderer->window = mlx_new_window(
			renderer->core,
			(int)map->size.y * TILE_PIXEL_SIZE,
			(int)map->size.x * TILE_PIXEL_SIZE,
			GAME_NAME);
	mlx_key_hook(renderer->window, key_hook_callback, NULL);
	mlx_hook(renderer->window, 2, 0, key_hook_callback, NULL);
	mlx_mouse_hook(renderer->window, mouse_hook_callback, NULL);
	mlx_expose_hook(renderer->window, expose_hook_callback, NULL);
	mlx_loop_hook(renderer->core, loop_hook_callback, NULL);
	mlx_hook(renderer->window, 17, 0, close_callback, NULL);
	if (renderer->window == NULL)
		return (fterr_set_error(MLX_FAILURE), FALSE);
	return (TRUE);
}
