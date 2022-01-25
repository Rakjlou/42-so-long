/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_surround.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 21:55:32 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool	map_validator_walls_surround(t_ftconfig *config, t_map *map)
{
	return (map_validator_wall_top(config, map)
		&& map_validator_wall_bottom(config, map)
		&& map_validator_wall_left(config, map)
		&& map_validator_wall_right(config, map));
}
