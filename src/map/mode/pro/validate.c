/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:42:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 01:06:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_mode_pro.h"

t_bool	map_mode_pro_validate(t_ftconfig *config, t_map *map)
{
	return (map_mode_default_validate(config, map));
}
