/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:11:30 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 21:22:50 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>

void	map_destroy(t_map *map)
{
	lst_destroy_nodes(&map->raw.data, free);
	free(map->tile);
	if (map->destroy != NULL)
		map->destroy(map);
	ft_bzero(map, sizeof(t_map));
}
