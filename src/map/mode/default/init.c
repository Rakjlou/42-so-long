/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:42:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 00:50:34 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_mode_default.h"

void	map_mode_default_init(t_map *map)
{
	map->validate = map_mode_default_validate;
	map->instanciate = map_mode_default_instanciate;
	map->destroy = map_mode_default_destroy;
}
