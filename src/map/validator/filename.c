/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:07:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/02 00:05:14 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"
#include "libft.h"
#include "ftprintf.h"
#include "so_long.h"

t_bool	map_validator_filename(t_map *map)
{
	char	*slash;

	if (ftconfig_get_boolean(_config(), "strict") == FALSE)
		return (TRUE);
	else if (!ft_ends_with((char *)map->file.name, ".ber"))
		return (map_error(-1, E_BER_EXTENSION, NULL));
	slash = ft_strrchr(map->file.name, '/');
	if (slash == NULL || ft_strlen(slash + 1) == 4)
		return (map_error(-1, E_BER_EXTENSION_CHEEKY, NULL));
	return (ft_strlen(slash + 1) > 3);
}
