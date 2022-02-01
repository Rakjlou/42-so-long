/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 01:28:14 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 14:44:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errors.h"

static t_bool	set_up_animations(t_enemy_v *enemy)
{
	enemy->animation_top = animation_new(7,
			25, "sprites/enemy-up1.xpm",
			25, "sprites/enemy-up2.xpm",
			25, "sprites/enemy-up3.xpm",
			25, "sprites/enemy-up4.xpm",
			25, "sprites/enemy-up5.xpm",
			25, "sprites/enemy-up6.xpm",
			25, "sprites/enemy-up7.xpm");
	return (enemy->animation_top != NULL);
}

static t_bool	set_down_animations(t_enemy_v *enemy)
{
	enemy->animation_down = animation_new(7,
			25, "sprites/enemy-down1.xpm",
			25, "sprites/enemy-down2.xpm",
			25, "sprites/enemy-down3.xpm",
			25, "sprites/enemy-down4.xpm",
			25, "sprites/enemy-down5.xpm",
			25, "sprites/enemy-down6.xpm",
			25, "sprites/enemy-down7.xpm");
	return (enemy->animation_top != NULL);
}

t_enemy_v	*enemy_v_new(
	unsigned char type,
	unsigned int x,
	unsigned int y)
{
	t_enemy_v	*enemy;

	enemy = ft_calloc(sizeof(t_enemy_v), 1);
	if (enemy == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	else if (set_up_animations(enemy) == FALSE
		|| set_down_animations(enemy) == FALSE)
		return (enemy_v_destroy((t_character *)enemy), NULL);
	if (type == TILE_ENEMY_VT)
	{
		enemy->direction = -1;
		enemy->p.animation = enemy->animation_top;
	}
	else
	{
		enemy->direction = 1;
		enemy->p.animation = enemy->animation_down;
	}
	enemy->p.render = character_render;
	enemy->p.destroy = enemy_v_destroy;
	enemy->p.update = enemy_v_update;
	enemy->p.on_collide = enemy_v_on_collide;
	enemy->p.pos.x = x;
	enemy->p.pos.y = y;
	return (enemy);
}
