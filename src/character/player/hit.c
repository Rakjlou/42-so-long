/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:51:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 22:36:21 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "ftprintf.h"

void	player_hit(void)
{
	t_game		*game;
	t_character	*player;

	game = _game();
	player = &game->player;
	if (player->hp > 0 && player->is_hit == 0)
		--player->hp;
	if (player->hp == 0)
	{
		game->end = TRUE;
		game->end_msg = "You died...";
	}
	player->is_hit = 1;
}
