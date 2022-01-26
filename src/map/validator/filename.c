/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/27 00:48:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"
#include "libft.h"
#include "ftprintf.h"
#include "so_long.h"

/*
** TODO: Check fichiers qui s'appelleraient uniquement .ber
** Gérer aussi ./.ber ou ./map/.ber
*/
t_bool	map_validator_filename(t_map *map)
{
	if (ftconfig_get_boolean(_config(), "strict") == FALSE)
		return (TRUE);
	else if (!ft_ends_with((char *)map->file.name, ".ber"))
		return (map_error(-1, E_BER_EXTENSION, NULL));
	return (TRUE);
}
