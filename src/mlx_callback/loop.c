/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:13:54 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:24:58 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_hook_callback(void)
{
	t_character	*player;

	if (_game()->input.close)
		close_callback();
	player = _player();
	player->update(player);
	game_render();
	return (1);
}
