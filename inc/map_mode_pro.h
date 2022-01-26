/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mode_pro.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:54:06 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 21:08:51 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MODE_PRO_H
# define MAP_MODE_PRO_H

# include "map_mode_default.h"

void	map_mode_pro_init(t_map *map);
void	map_mode_pro_destroy(t_map *map);
t_bool	map_mode_pro_validate(t_ftconfig *config, t_map *map);
t_bool	map_mode_pro_instanciate(t_map *map);

#endif
