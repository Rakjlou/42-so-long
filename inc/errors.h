/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:06:56 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 23:26:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "fterr.h"

# define E_USAGE "Usage: ./so_long map.ber"
# define E_CONFIG_FILE_OPEN "Couldn't open config file config.txt"
# define E_MAP_FILE_OPEN "Couldn't open file map"
# define E_INVALID_MAP_FILENAME "The map file must be named MAPNAME.ber"
# define E_INVALID_MAP_LINE "The map has an invalid line"
# define E_INVALID_MAP "Invalid map"
# define E_IMG_LOAD "MLX couldn't load image %s"
# define E_MLX_FAILURE "MiniLibX failed"
# define E_FAILED_MALLOC "Malloc has failed"
# define E_MISS_CONFIG_KEY "Key %s is missing in config file"
# define E_MISS_CONFIG_VAL "Key %s has no value in config file"
# define E_MAP_EMPTY_OR_DIR "Map is empty or is a directory"
# define E_DEFAULT "Unknown error"

typedef enum e_error_code
{
	USAGE,
	CONFIG_FILE_OPEN,
	MAP_FILE_OPEN,
	INVALID_MAP_FILENAME,
	INVALID_MAP_LINE,
	INVALID_MAP,
	FAILED_MALLOC,
	MISS_CONFIG_KEY,
	MISS_CONFIG_VAL,
	MLX_FAILURE,
	IMG_LOAD,
	MAP_EMPTY_OR_DIR,
	UNKNOWN
}	t_error_code;

void	errors_register(void);

#endif
