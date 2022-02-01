#include "character.h"
#include "so_long.h"
#include "errors.h"
#include "libft.h"
#include <stdlib.h>

static void	enemy_v_update(t_character *character)
{
	static int	i = 0;
	t_enemy_v	*enemy;

	enemy = (t_enemy_v *)character;
	if (i >= 80)
	{
		if (!player_can_go(character->pos.x + enemy->direction, character->pos.y))
			character->on_collide(character);
		else
			character->pos.x += enemy->direction;
		i = 0;
	}
	else
		++i;
}

static void	enemy_v_on_collide(t_character *character)
{
	t_enemy_v	*enemy;

	enemy = (t_enemy_v *)character;
	enemy->direction *= -1;
	if (enemy->direction > 0)
		character->animation = enemy->animation_down;
	else
		character->animation = enemy->animation_top;
}

static void	enemy_v_destroy(t_character *character)
{
	t_enemy_v	*enemy;

	enemy = (t_enemy_v *)character;
	animation_destroy(enemy->animation_top);
	animation_destroy(enemy->animation_down);
	character->animation = NULL;
	free(enemy);
}

static t_bool		set_up_animations(t_enemy_v *enemy)
{
	enemy->animation_top = animation_new(7,
		25, "sprites/enemy-up1.xpm",
		25, "sprites/enemy-up2.xpm",
		25, "sprites/enemy-up3.xpm",
		25, "sprites/enemy-up4.xpm",
		25, "sprites/enemy-up5.xpm",
		25, "sprites/enemy-up6.xpm",
		25, "sprites/enemy-up7.xpm"
	);
	return (enemy->animation_top != NULL);
}

static t_bool		set_down_animations(t_enemy_v *enemy)
{
	enemy->animation_down = animation_new(7,
		25, "sprites/enemy-down1.xpm",
		25, "sprites/enemy-down2.xpm",
		25, "sprites/enemy-down3.xpm",
		25, "sprites/enemy-down4.xpm",
		25, "sprites/enemy-down5.xpm",
		25, "sprites/enemy-down6.xpm",
		25, "sprites/enemy-down7.xpm"
	);
	return (enemy->animation_top != NULL);
}

static t_enemy_v	*enemy_v_new(unsigned char type, unsigned int x, unsigned int y)
{
	t_enemy_v	*enemy;

	enemy = ft_calloc(sizeof(t_enemy_v), 1);
	if (enemy == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	else if (set_up_animations(enemy) == FALSE || set_down_animations(enemy) == FALSE)
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

static t_character	*enemy_factory(unsigned char type, unsigned int x, unsigned int y)
{
	if (type == TILE_ENEMY_VT)
		return ((t_character *)enemy_v_new(type, x, y));
	return (NULL);
}

t_bool	enemy_add(unsigned char type, unsigned int x, unsigned int y)
{
	unsigned int	i;

	i = 0;
	while (_game()->enemy[i] != NULL)
		++i;
	_game()->enemy[i] = enemy_factory(type, x, y);
	if (_game()->enemy[i] == NULL)
		return (FALSE);
	return (TRUE);
}