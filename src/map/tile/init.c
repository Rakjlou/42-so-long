/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:36:35 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 01:37:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile.h"
#include "libft.h"

void	tile_init(t_tile *tile,
	unsigned char type,
	unsigned int x,
	unsigned int y)
{
	ft_bzero(tile, sizeof(t_tile));
	tile->type = type;
	tile->x = x;
	tile->y = y;
	tile_state_factory(tile);
}
