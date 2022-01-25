/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:06:56 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 19:18:50 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

#include "fterr.h"

# define E_USAGE "Usage: ./so_long map.ber"
# define E_CONFIG_FILE_OPEN "Couldn't open config file config.txt"
# define E_MAP_FILE_OPEN "Couldn't open file map"
# define E_INVALID_MAP_FILENAME "The map file must be named MAPNAME.ber"
# define E_INVALID_MAP_LINE "The map has an invalid line"
# define E_INVALID_MAP "Invalid map"
# define E_FAILED_MALLOC "Malloc has failed"
# define E_MISS_CONFIG_KEY "Key %s is missing in config file\n"
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
	MISS_CONFIG_KEY
}	t_error_code;

void	errors_register(void);

#endif
