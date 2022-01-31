/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osboxes <osboxes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:57:28 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 08:00:53 by osboxes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "map.h"
#include "errors.h"
#include "ftprintf.h"
#include "mlx.h"

t_bool	renderer_init(void)
{
	t_renderer	*renderer;
	t_map		*map;
	char		*window_name;

	window_name = "so_long nsierra-";
	renderer = _renderer();
	map = _map();
	renderer->core = mlx_init();
	if (renderer->core == NULL)
		return (fterr_set_error(MLX_FAILURE), FALSE);
	ftprintf("W %d H %d\n", (int)map->width * TILE_PIXEL_SIZE, (int)map->height * TILE_PIXEL_SIZE);
	renderer->window = mlx_new_window(
		renderer->core,
		(int)map->width * TILE_PIXEL_SIZE,
		(int)map->height * TILE_PIXEL_SIZE,
		window_name);
	if (renderer->window == NULL)
		return (fterr_set_error(MLX_FAILURE), FALSE);
	return (TRUE);
}
