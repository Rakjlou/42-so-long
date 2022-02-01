/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:42:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 14:35:19 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"
#include "so_long.h"

static t_bool	validate_strict(void)
{
	t_map	*map;

	map = _map();
	return (map_validator_filename(map)
		&& map_validator_rectangle(map)
		&& map_validator_valid_chars_only(map)
		&& map_validator_walls_surround(map)
		&& map_validator_1spawn(map)
		&& map_validator_1exit(map)
		&& map_validator_1collectible(map));
}

static t_bool	validate_non_strict(void)
{
	t_map	*map;

	map = _map();
	return (map_validator_rectangle(map)
		&& map_validator_valid_chars_only(map)
		&& map_validator_1spawn(map)
		&& map_validator_1exit(map)
		&& map_validator_1collectible(map)
		&& map_validator_enemies(map));
}

/*
** TODO: Trim le fichier map (lignes vides au debut et fin)
*/
t_bool	map_validate(void)
{
	if (ftconfig_get_boolean(_config(), "strict"))
		return (validate_strict());
	return (validate_non_strict());
}
