/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:46:50 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 21:16:24 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errors.h"
#include "libft.h"
#include "ftprintf.h"

t_bool	game_init(t_game *game, const char *mapfile)
{
	(void)mapfile;
	ft_bzero(game, sizeof(t_game));
	errors_register();
	return (config_init(game, "config.txt")
		&& map_init(&game->config, &game->map, mapfile));
}
