/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:13:54 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 18:30:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ftprintf.h"

static void	shell_render(void)
{
	static unsigned int	movements = 0;
	unsigned int		player_movements;

	player_movements = _game()->player_movements;
	if (movements != player_movements)
	{
		ftprintf("Movements count: %u\n", player_movements);
		movements = player_movements;
	}
}

int	loop_hook_callback(void)
{
	t_character	*player;

	if (_game()->input.close)
		close_callback();
	player = _player();
	player->update(player);
	game_render();
	shell_render();
	return (1);
}
