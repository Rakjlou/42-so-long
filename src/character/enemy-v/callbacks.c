/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 01:29:55 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 01:30:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_v_update(t_character *character)
{
	static int	i = 0;
	t_enemy_v	*enemy;

	enemy = (t_enemy_v *)character;
	if (i >= 80)
	{
		if (!player_can_go(character->pos.x + enemy->direction,
				character->pos.y))
			character->on_collide(character);
		else
			character->pos.x += enemy->direction;
		i = 0;
	}
	else
		++i;
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
