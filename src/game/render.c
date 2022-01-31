/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:45:50 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:20:42 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ftprintf.h"

static void	game_render_map(void)
{
	unsigned int	x;
	unsigned int	y;
	t_map			*map;
	t_tile			*tile;

	x = 0;
	map = _map();
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			tile = map->tile[(x * map->width) + y];
			xpm_image_render(tile->image, x, y);
			++y;
		}
		++x;
	}
}

int	game_render(void)
{
	game_render_map();
	return (1);
}
