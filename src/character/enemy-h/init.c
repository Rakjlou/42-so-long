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

static t_bool	set_up_animations(t_enemy_h *enemy)
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

static t_bool	set_down_animations(t_enemy_h *enemy)
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

static void	set_attributes(
	t_enemy_h *enemy,
	unsigned char type,
	unsigned int x,
	unsigned int y)
{
	if (type == TILE_NMY_VT)
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
	enemy->p.destroy = enemy_h_destroy;
	enemy->p.update = enemy_h_update;
	enemy->p.on_collide = enemy_h_on_collide;
	enemy->p.pos.x = x;
	enemy->p.pos.y = y;
}

t_enemy_h	*enemy_h_new(
	unsigned char type,
	unsigned int x,
	unsigned int y)
{
	t_enemy_h	*enemy;

	enemy = ft_calloc(sizeof(t_enemy_h), 1);
	if (enemy == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	else if (set_up_animations(enemy) == FALSE
		|| set_down_animations(enemy) == FALSE)
		return (enemy_h_destroy((t_character *)enemy), NULL);
	set_attributes(enemy, type, x, y);
	return (enemy);
}
