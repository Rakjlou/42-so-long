/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:10:25 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 21:06:49 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile.h"
#include "renderer.h"
#include "ftprintf.h"
#include "mlx.h"

void	xpm_image_render(t_xpm_image *image, int x, int y)
{
	t_renderer	*r;

	r = _renderer();
	mlx_put_image_to_window(
		r->core,
		r->window,
		image->p.mlx_obj,
		y * TILE_PIXEL_SIZE,
		x * TILE_PIXEL_SIZE);
}

void	image_render(t_image *image, int x, int y)
{
	t_renderer	*r;

	r = _renderer();
	mlx_put_image_to_window(r->core, r->window, image->mlx_obj, y, x);
}
