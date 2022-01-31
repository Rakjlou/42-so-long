/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:34:24 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:30:56 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "readf.h"
#include "errors.h"
#include "libft.h"
#include <limits.h>

static void	map_set_length_height(t_map *map)
{
	map->width = ft_strlen((char *)lst_data_at(&map->file.data, 0));
	map->height = map->file.data.size;
}

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
	if (lst_push_back(&map->file.data, dup_line) == 0)
		return (fterr_set_error(FAILED_MALLOC), FALSE);
	return (TRUE);
}

t_bool	map_init(const char *filename)
{
	t_readf_status	status;
	t_map			*map;

	map = _map();
	map->file.name = filename;
	status = readf(filename, map_readl, map);
	if (status == FTRF_E_FILE_OPEN)
		return (fterr_set(MAP_FILE_OPEN, (void *)filename, NULL), FALSE);
	else if (status == FTRF_E_READL)
		return (FALSE);
	map_set_length_height(map);
	return (map_validate());
}
