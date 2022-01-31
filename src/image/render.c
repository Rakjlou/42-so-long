/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:10:25 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:20:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "renderer.h"
#include "ftprintf.h"
#include "mlx.h"

void	xpm_image_render(t_xpm_image *image, int x, int y)
{
	t_renderer	*r;
	int			img_size;

	r = _renderer();
	img_size = image->p.width;
	mlx_put_image_to_window(
		r->core,
		r->window,
		image->p.mlx_obj,
		y * img_size,
		x * img_size);
}
