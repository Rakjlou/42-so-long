/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:10:23 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 18:15:55 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	player_init(void)
{
	t_game	*game;

	game = _game();
	game->player.animation = animation_new(
			5,
			20, "sprites/player1.xpm",
			25, "sprites/player2.xpm",
			30, "sprites/player3.xpm",
			35, "sprites/player4.xpm",
			40, "sprites/player5.xpm");
	if (game->player.animation == NULL)
		return (FALSE);
	game->player.render = character_render;
	game->player.update = player_update;
	game->player.hp = 3;
	return (TRUE);
}
