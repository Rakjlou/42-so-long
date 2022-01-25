/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:34:24 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 22:36:05 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "readf.h"
#include "errors.h"
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

static t_bool	map_validate_pro(t_ftconfig *config, t_map *map)
{
	(void)config;
	(void)map;
	return (TRUE);
}

static t_bool	map_validate_default(t_ftconfig *config, t_map *map)
{
	return (map_validator_filename(config, map)
		&& map_validator_rectangle(config, map)
		&& map_validator_valid_chars_only(config, map)
		&& map_validator_walls_surround(config, map)
		&& map_validator_1spawn(config, map)
		&& map_validator_1exit(config, map)
		&& map_validator_1collectible(config, map));
}

t_bool	map_init(t_ftconfig *config, t_map *map, const char *filename)
{
	t_readf_status	status;
	int				cmp;

	status = readf(filename, map_readl, map);
	if (status == FTRF_E_FILE_OPEN)
		return (fterr_set(MAP_FILE_OPEN, (void *)filename, NULL), FALSE);
	else if (status == FTRF_E_READL)
		return (FALSE);
	map->raw.filename = filename;
	cmp = ft_strncmp(ftconfig_get_single(config, "map_mode"), "pro", UINT_MAX);
	if (cmp == 0)
		return (map_validate_pro(config, map));
	return (map_validate_default(config, map));
}
