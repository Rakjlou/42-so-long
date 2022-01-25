/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:13:13 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/24 23:16:57 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <limits.h>

char	**config_get(t_game *game, const char *entry_name)
{
	t_iter	iter;
	char	**entry;

	if (game->config == NULL)
		return (NULL);
	iter_init(&iter, game->config, ASC);
	while (iter_next(&iter))
	{
		entry = (char **)iter.data;
		if (ft_strncmp(entry[0], entry_name, UINT_MAX) == 0)
			return (entry);
	}
	return (NULL);
}

char	*config_gets(t_game *game, const char *entry_name)
{
	char	**entry;

	entry = config_get(game, entry_name);
	if (entry == NULL)
		return (NULL);
	return (entry[1]);
}

t_bool	config_getb(t_game *game, const char *entry_name)
{
	char	**entry;

	entry = config_get(game, entry_name);
	if (entry == NULL || entry[1] == NULL)
		return (FALSE);
	else if (ft_strncmp(entry[1], "1", UINT_MAX) == 0)
		return (TRUE);
	return (FALSE);
}
