/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:10:25 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:23:56 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile.h"
#include "errors.h"

t_tile	*tile_floor_new(
					unsigned int type,
					unsigned int x,
					unsigned int y)
{
	t_tile	*tile;

	tile = ft_calloc(sizeof(t_tile), 1);
	if (tile == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	tile->image = xpm_image_new("sprites/floor.xpm");
	if (tile->image == NULL)
		return (NULL);
	tile->type = type;
	tile->x = x;
	tile->y = y;
	tile->render = tile_render;
	return (as_tile(tile));
}
