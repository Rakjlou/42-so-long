/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 01:18:51 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 21:58:57 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errors.h"
#include "libft.h"
#include <stdlib.h>

void	character_destroy(t_character *character)
{
	if (character->animation != NULL)
		animation_destroy(character->animation);
	if (character->hit_animation != NULL)
		animation_destroy(character->hit_animation);
	free(character);
}

void	player_destroy(void)
{
	t_character	*player;

	player = _player();
	if (player->animation != NULL)
		animation_destroy(player->animation);
	if (player->hit_animation != NULL)
		animation_destroy(player->hit_animation);
}
