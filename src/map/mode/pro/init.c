/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:42:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 01:06:30 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_mode_pro.h"

void	map_mode_pro_init(t_map *map)
{
	map->validate = map_mode_pro_validate;
	map->instanciate = map_mode_pro_instanciate;
	map->destroy = map_mode_pro_destroy;
}
