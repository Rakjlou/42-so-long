/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 01:18:51 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 14:30:32 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "animation.h"
#include "errors.h"
#include "libft.h"
#include "ftprintf.h"
#include <stdlib.h>

static void	player_update(t_character *player)
{
	t_game	*game;
	t_input	*input;
	t_tile	*leaving;
	t_tile	*entering;

	game = _game();
	leaving = tile_get(player->pos.x, player->pos.y);
	input = &game->input;
	if (input->up && !input->down && player_can_go_up())
		player->pos.x = ft_uimax(0, player->pos.x - 1);
	else if (input->right && !input->left && player_can_go_right())
		player->pos.y = ft_umin(game->map.size.y - 1, player->pos.y + 1);
	else if (input->down && !input->up && player_can_go_down())
		player->pos.x = ft_umin(game->map.size.x - 1, player->pos.x + 1);
	else if (input->left && !input->right && player_can_go_left())
		player->pos.y = ft_uimax(0, player->pos.y - 1);
	entering = tile_get(player->pos.x, player->pos.y);
	if (leaving->pos.x != entering->pos.x || leaving->pos.y != entering->pos.y)
	{
		if (leaving->on_leaving != NULL)
			leaving->on_leaving(leaving);
		if (entering->on_stepping)
			entering->on_stepping(entering);
	}
	ft_bzero(input, sizeof(t_input));
}

void	character_render(t_character *character)
{
	animation_render(character->animation, character->pos.x, character->pos.y);
}

t_character	*character_new(
	unsigned int x,
	unsigned int y,
	const char *sprite_file)
{
	t_character	*character;

	(void)sprite_file;
	character = ft_calloc(sizeof(t_character), 1);
	if (character == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	character->pos.x = x;
	character->pos.y = y;
	character->render = character_render;
	return (character);
}

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
	return (TRUE);
}
