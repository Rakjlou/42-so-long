/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mode_default.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:54:06 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 21:07:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MODE_DEFAULT_H
# define MAP_MODE_DEFAULT_H

# include "map.h"

void	map_mode_default_init(t_map *map);
void	map_mode_default_destroy(t_map *map);
t_bool	map_mode_default_validate(t_ftconfig *config, t_map *map);
t_bool	map_mode_default_instanciate(t_map *map);

#endif
