/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 01:29:55 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 22:07:05 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ftprintf.h"

void	enemy_v_update(t_character *character)
{
	static int		i = 0;
	t_enemy_v		*enemy;
	t_game			*game;
	t_character		*player;
	unsigned int	x_target;

	enemy = (t_enemy_v *)character;
	game = _game();
	player = &game->player;
	x_target = character->pos.x + enemy->direction;
	if (i++ >= 80)
	{
		if (!character_can_go(x_target,
				character->pos.y))
			character->on_collide(character);
		else if (player->pos.x == x_target && player->pos.y == character->pos.y)
		{
			ftprintf("HERE\n");
			player_hit();
			character->on_collide(character);
		}
		else
			character->pos.x = x_target;
		i = 0;
	}
}

void	enemy_v_on_collide(t_character *character)
{
	t_enemy_v	*enemy;

	enemy = (t_enemy_v *)character;
	enemy->direction *= -1;
	if (enemy->direction > 0)
		character->animation = enemy->animation_down;
	else
		character->animation = enemy->animation_top;
}
