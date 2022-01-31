/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osboxes <osboxes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:07:33 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 07:46:31 by osboxes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile.h"
#include "errors.h"
#include "libft.h"

static t_tile	*tile_default_factory(
					unsigned int type,
					unsigned int x,
					unsigned int y)
{
	t_tile		*tile;

	tile = ft_calloc(sizeof(t_tile), 1);
	if (tile == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	tile->type = type;
	tile->x = x;
	tile->y = y;
	return (tile);
}

static void	init_custom_tiles(
	t_tile *(*factory[256])(unsigned int, unsigned int, unsigned int))
{
	factory['0'] = tile_floor_new;
	factory['P'] = tile_floor_new;
	factory['1'] = tile_wall_new;
	factory['E'] = tile_exit_new;
	factory['C'] = tile_collectible_new;
}

void	tile_default_destroy(t_tile *tile)
{
	xpm_image_destroy(tile->image);
}

t_tile	*tile_factory(unsigned int type, unsigned int x, unsigned int y)
{
	static t_tile	*(*factory[256])(
		unsigned int, unsigned int, unsigned int) = {0};

	init_custom_tiles(factory);
	if (factory[type] != NULL)
		return (factory[type](type, x, y));
	return (tile_default_factory(type, x, y));
}
