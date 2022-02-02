/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 01:18:51 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 01:30:32 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "character.h"
#include "so_long.h"
#include "errors.h"
#include "libft.h"
#include <stdlib.h>

static t_character	*enemy_factory(
	unsigned char type,
	unsigned int x,
	unsigned int y)
{
	if (type == TILE_NMY_VT || type == TILE_NMY_VD)
		return ((t_character *)enemy_v_new(type, x, y));
	return (NULL);
}

t_bool	enemy_add(unsigned char type, unsigned int x, unsigned int y)
{
	unsigned int	i;
	t_game			*game;

	i = 0;
	game = _game();
	while (game->enemy[i] != NULL)
		++i;
	game->enemy[i] = enemy_factory(type, x, y);
	if (game->enemy[i] == NULL)
		return (FALSE);
	return (TRUE);
}
