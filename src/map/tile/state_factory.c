/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:28:29 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 01:40:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile.h"
#include <stddef.h>

void	tile_state_factory(t_tile *tile)
{
	static void	(*state_init[256])(t_tile_state *) = {0};

	if (state_init[tile->type] == NULL)
		return ;
	state_init[tile->type](&tile->state);
}
