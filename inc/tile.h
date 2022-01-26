/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:36:46 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/27 00:26:43 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILE_H
# define TILE_H

# include "libft.h"

typedef struct s_tile
{
	int	sprite;
}	t_tile;

typedef struct s_tile_chest
{
	t_tile	parent;
	t_bool	opened;
}	t_tile_chest;

t_tile	*tile_factory(unsigned int type);
t_tile	*as_tile(void *child);

#endif
