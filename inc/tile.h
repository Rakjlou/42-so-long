/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:36:46 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 01:36:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILE_H
# define TILE_H

typedef struct s_tile_state
{
	void	*state;
	void	*free;
}	t_tile_state;

typedef struct s_tile
{
	unsigned char	type;
	t_tile_state	state;
	unsigned int	x;
	unsigned int	y;
}	t_tile;

void	tile_state_factory(t_tile *tile);
void	tile_init(t_tile *tile,
			unsigned char type,
			unsigned int x,
			unsigned int y);
#endif
