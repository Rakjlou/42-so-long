/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:46:50 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 19:30:03 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errors.h"

t_bool	game_init(t_game *game, const char *mapfile)
{
	(void)mapfile;
	errors_register();
	return (config_init(game, "config.txt")/* && map_init(game, mapfile)*/);
}
