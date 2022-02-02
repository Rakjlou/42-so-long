/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 01:18:51 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 18:37:04 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "animation.h"
#include "errors.h"
#include "libft.h"
#include "ftprintf.h"
#include <stdlib.h>

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
