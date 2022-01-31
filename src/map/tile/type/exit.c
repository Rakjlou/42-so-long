/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:10:25 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:24:11 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile.h"
#include "errors.h"

static t_bool	tile_exit_allow_stepping(t_tile *t)
{
	(void)t;
	return (TRUE);
}

t_tile	*tile_exit_new(
					unsigned int type,
					unsigned int x,
					unsigned int y)
{
	t_tile_bistate	*tile;

	tile = ft_calloc(sizeof(t_tile_bistate), 1);
	if (tile == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	tile->p.image = xpm_image_new("sprites/exit-locked.xpm");
	if (tile->p.image == NULL)
		return (NULL);
	tile->p.type = type;
	tile->p.x = x;
	tile->p.y = y;
	tile->p.allow_stepping = tile_exit_allow_stepping;
	tile->p.render = tile_render;
	return (as_tile(tile));
}
