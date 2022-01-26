/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:34:24 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 01:06:06 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "readf.h"
#include "errors.h"
#include "map_mode_default.h"
#include "map_mode_pro.h"
#include "libft.h"
#include <limits.h>

static t_bool	map_readl(const char *line, void *data)
{
	t_map	*map;
	char	*dup_line;
	size_t	len;

	map = (t_map *)data;
	dup_line = ft_strdup(line);
	if (dup_line == NULL)
		return (fterr_set_error(FAILED_MALLOC), FALSE);
	len = ft_strlen(dup_line);
	if (len > 1)
		dup_line[len - 1] = '\0';
	if (lst_push_back(&map->raw.data, dup_line) == 0)
		return (fterr_set_error(FAILED_MALLOC), FALSE);
	return (TRUE);
}

static void	map_init_mode(t_ftconfig *config, t_map *map)
{
	char	*raw_mode;

	raw_mode = ftconfig_get_single(config, "map_mode");
	if (raw_mode && ft_strncmp(raw_mode, "pro", UINT_MAX) == 0)
	{
		map_mode_pro_init(map);
	}
	else
		map_mode_default_init(map);
}

t_bool	map_init(t_ftconfig *config, t_map *map, const char *filename)
{
	t_readf_status	status;

	map->raw.filename = filename;
	map_init_mode(config, map);
	status = readf(filename, map_readl, map);
	if (status == FTRF_E_FILE_OPEN)
		return (fterr_set(MAP_FILE_OPEN, (void *)filename, NULL), FALSE);
	else if (status == FTRF_E_READL)
		return (FALSE);
	return (map->validate(config, map) && map->instanciate(map));
}
