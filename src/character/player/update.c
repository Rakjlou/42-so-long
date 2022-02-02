/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:52:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 20:36:57 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_movement(t_game *game, t_character *player, t_input *input)
{
	if (input->up && !input->down && player_can_go_up())
		player->pos.x = ft_uimax(0, player->pos.x - 1);
	else if (input->right && !input->left && player_can_go_right())
		player->pos.y = ft_umin(game->map.size.y - 1, player->pos.y + 1);
	else if (input->down && !input->up && player_can_go_down())
		player->pos.x = ft_umin(game->map.size.x - 1, player->pos.x + 1);
	else if (input->left && !input->right && player_can_go_left())
		player->pos.y = ft_uimax(0, player->pos.y - 1);
}

void	player_update(t_character *player)
{
	t_game	*game;
	t_input	*input;
	t_tile	*leaving;
	t_tile	*entering;

	game = _game();
	leaving = tile_get(player->pos.x, player->pos.y);
	input = &game->input;
	player_movement(game, player, input);
	entering = tile_get(player->pos.x, player->pos.y);
	if (leaving->pos.x != entering->pos.x || leaving->pos.y != entering->pos.y)
	{
		++game->ui.player_movements;
		if (leaving->on_leaving != NULL)
			leaving->on_leaving(leaving);
		if (entering->on_stepping)
			entering->on_stepping(entering);
	}
	ft_bzero(input, sizeof(t_input));
}
