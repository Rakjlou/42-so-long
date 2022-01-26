/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:42:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 00:05:20 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

t_bool	map_mode_default_validate(t_ftconfig *config, t_map *map)
{
	return (map_validator_filename(config, map)
		&& map_validator_rectangle(config, map)
		&& map_validator_valid_chars_only(config, map)
		&& map_validator_walls_surround(config, map)
		&& map_validator_1spawn(config, map)
		&& map_validator_1exit(config, map)
		&& map_validator_1collectible(config, map));
}
