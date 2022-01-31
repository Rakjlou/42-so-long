/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osboxes <osboxes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:36:46 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 07:46:04 by osboxes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILE_H
# define TILE_H

# include "libft.h"
# include "image.h"

typedef struct s_tile
{
	unsigned int	type;
	unsigned int	x;
	unsigned int	y;
	t_xpm_image		*image;
	t_bool			collides;
	t_bool			(*allow_stepping)(struct s_tile *);
	void			(*on_stepping)(struct s_tile *);
	void			(*on_leaving)(struct s_tile *);
	void			(*on_interact)(struct s_tile *);
	void			(*destroy)(struct s_tile *);
}	t_tile;

typedef struct s_tile_bistate
{
	t_tile		p;
	t_bool		state;
	t_xpm_image	*image2;
}	t_tile_bistate;

t_tile	*tile_factory(unsigned int type, unsigned int x, unsigned int y);
t_tile	*as_tile(void *child);
void	tile_default_destroy(t_tile *tile);

t_tile	*tile_collectible_new(
			unsigned int type,
			unsigned int x,
			unsigned int y);
t_tile	*tile_exit_new(
			unsigned int type,
			unsigned int x,
			unsigned int y);
t_tile	*tile_floor_new(
			unsigned int type,
			unsigned int x,
			unsigned int y);
t_tile	*tile_wall_new(
			unsigned int type,
			unsigned int x,
			unsigned int y);

#endif
