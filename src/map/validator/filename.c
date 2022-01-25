/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 21:48:48 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include "ftprintf.h"

t_bool	map_validator_filename(t_ftconfig *config, t_map *map)
{
	if (ftconfig_get_boolean(config, "enforce_ber_extension") == FALSE)
		return (TRUE);
	else if (!ft_ends_with((char *)map->raw.filename, ".ber"))
		return (map_error(-1, E_BER_EXTENSION, NULL));
	return (TRUE);
}
