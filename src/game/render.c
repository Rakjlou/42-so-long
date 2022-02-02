/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:45:50 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 21:13:58 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ftprintf.h"

static t_bool	is_character_on_tile(unsigned int x, unsigned int y)
{
	unsigned int	i;
	t_character		*enemy;

	if (_player()->pos.y == y && _player()->pos.x == x)
		return (TRUE);
	i = 0;
	if (_game()->enemy == NULL)
		return (FALSE);
	while (_game()->enemy[i] != NULL)
	{
		enemy = _game()->enemy[i];
		if (enemy->pos.x == x && enemy->pos.y == y)
			return (TRUE);
		++i;
	}
	return (FALSE);
}

static void	game_render_map(void)
{
	unsigned int	x;
	unsigned int	y;
	t_map			*map;
	t_tile			*tile;

	x = 0;
	map = _map();
	while (x < map->size.x)
	{
		y = 0;
		while (y < map->size.y)
		{
			if (is_character_on_tile(x, y))
			{
				++y;
				continue ;
			}
			tile = map->tile[(x * map->size.y) + y];
			tile->render(tile);
			++y;
		}
		++x;
	}
}

static void	game_render_characters(void)
{
	t_game			*game;
	t_character		*player;
	t_character		*enemy;
	unsigned int	i;

	game = _game();
	player = &game->player;
	player->render(player);
	if (_game()->enemy == NULL)
		return ;
	i = 0;
	while (_game()->enemy[i] != NULL)
	{
		enemy = _game()->enemy[i];
		enemy->update(enemy);
		enemy->render(enemy);
		++i;
	}
}

int	game_render(void)
{
	game_render_map();
	game_render_characters();
	ui_render();
	return (1);
}
