/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:49:44 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 23:32:45 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errors.h"

static t_bool	config_has_mandatory_keys(t_ftconfig *config)
{
	int			i;
	static char	*mandatory_keys[1] = {
		"strict",
	};

	i = 0;
	while (i < 1)
	{
		if (ftconfig_get(config, mandatory_keys[i]) == NULL)
			return (fterr_set(MISS_CONFIG_KEY, mandatory_keys[i], NULL), FALSE);
		if (ftconfig_get_single(config, mandatory_keys[i]) == NULL)
			return (fterr_set(MISS_CONFIG_VAL, mandatory_keys[i], NULL), FALSE);
		++i;
	}
	return (TRUE);
}

t_bool	config_init(const char *mapfile)
{
	t_ftconfig_status	status;
	t_game				*game;

	game = _game();
	status = ftconfig_init(&game->config, mapfile);
	if (status == FTCONF_SUCCESS)
		return (config_has_mandatory_keys(&game->config));
	else if (status == FTCONF_E_FILE_OPEN)
		fterr_set(CONFIG_FILE_OPEN, (void *)mapfile, NULL);
	else if (status == FTCONF_E_FAILED_MALLOC)
		fterr_set_error(FAILED_MALLOC);
	return (FALSE);
}
