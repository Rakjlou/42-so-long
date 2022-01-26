/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:11:30 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 22:53:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	map_destroy()
{
	t_map	*map;

	map = _map();
	lst_destroy_nodes(&map->file.data, free);
	free(map->tile);
	ft_bzero(map, sizeof(t_map));
}
