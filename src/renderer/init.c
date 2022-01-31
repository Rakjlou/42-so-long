/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:57:28 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:25:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "map.h"
#include "errors.h"
#include "mlx.h"

t_bool	renderer_init(void)
{
	t_renderer	*renderer;
	t_map		*map;
	char		*window_name;

	window_name = "so_paint";
	renderer = _renderer();
	map = _map();
	renderer->core = mlx_init();
	if (renderer->core == NULL)
		return (fterr_set_error(MLX_FAILURE), FALSE);
	renderer->window = mlx_new_window(
			renderer->core,
			(int)map->width * TILE_PIXEL_SIZE,
			(int)map->height * TILE_PIXEL_SIZE,
			window_name);
	if (renderer->window == NULL)
		return (fterr_set_error(MLX_FAILURE), FALSE);
	return (TRUE);
}
