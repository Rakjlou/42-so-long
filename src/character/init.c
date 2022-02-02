/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 01:18:51 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 22:07:42 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "animation.h"
#include "errors.h"
#include "libft.h"
#include "ftprintf.h"
#include <stdlib.h>

void	character_render(t_character *chara)
{
	if (chara->is_hit == 0)
		animation_render(chara->animation, chara->pos.x, chara->pos.y);
	else
	{
		animation_render(chara->hit_animation, chara->pos.x, chara->pos.y);
		if (chara->is_hit >= 150)
			chara->is_hit = 0;
		else
			++chara->is_hit;
	}
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
