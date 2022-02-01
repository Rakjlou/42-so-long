/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:06:56 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 01:20:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

# include "map.h"

typedef struct s_map_error
{
	size_t	line_number;
	char	*line;
	char	*message;
}	t_map_error;

/* src/map/error.c */
t_map_error	*map_error_new(size_t line_number, char *message, char *line);
t_bool		map_error(size_t line_number, char *message, char *line);

/* src/map/validator */
t_bool		map_validator_filename(t_map *map);
t_bool		map_validator_rectangle(t_map *map);
t_bool		map_validator_wall_top(t_map *map);
t_bool		map_validator_wall_bottom(t_map *map);
t_bool		map_validator_wall_left(t_map *map);
t_bool		map_validator_wall_right(t_map *map);
t_bool		map_validator_walls_surround(t_map *map);
t_bool		map_validator_1collectible(t_map *map);
t_bool		map_validator_1spawn(t_map *map);
t_bool		map_validator_1exit(t_map *map);
t_bool		map_validator_valid_chars_only(t_map *map);
t_bool		map_validator_enemies(t_map *map);

#endif
