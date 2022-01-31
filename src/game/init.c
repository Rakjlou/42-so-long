/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:46:50 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:19:40 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errors.h"
#include "libft.h"
#include "ftprintf.h"

t_bool	game_init(const char *mapfile)
{
	ft_bzero(_game(), sizeof(t_game));
	errors_register();
	return (
		config_init("config.txt")
		&& map_init(mapfile)
		&& renderer_init()
		&& player_init()
		&& map_instanciate()
	);
}
