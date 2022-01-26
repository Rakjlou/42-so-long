/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:07:33 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/27 00:39:41 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile.h"
#include "errors.h"
#include "libft.h"

static void	tile_default_hydrate(t_tile *tile)
{
	tile->sprite = 42;
}

static t_tile	*tile_default_factory(void)
{
	t_tile		*tile;

	tile = ft_calloc(sizeof(t_tile), 1);
	if (tile == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	tile_default_hydrate(tile);
	return (tile);
}

static t_tile	*tile_chest_factory(void)
{
	t_tile_chest	*tile;

	tile = ft_calloc(sizeof(t_tile_chest), 1);
	if (tile == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	tile_default_hydrate(as_tile(tile));
	tile->opened = FALSE;
	return (as_tile(tile));
}

static void	init_custom_tiles(t_tile *(*factory[256])(void))
{
	factory['C'] = tile_chest_factory;
}

t_tile	*tile_factory(unsigned int type)
{
	static t_tile	*(*factory[256])(void) = {0};

	init_custom_tiles(factory);
	if (factory[type] != NULL)
		return (factory[type]());
	return (tile_default_factory());
}
