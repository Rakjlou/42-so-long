/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:47:56 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 21:11:09 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "fterr.h"
#include <stdlib.h>

static void	enemies_destroy(void)
{
	unsigned int	i;
	t_character		*enemy;

	if (_game()->enemy == NULL)
		return ;
	i = 0;
	while (_game()->enemy[i] != NULL)
	{
		enemy = _game()->enemy[i];
		enemy->destroy(enemy);
		++i;
	}
	free(_game()->enemy);
}

void	game_destroy(void)
{
	t_game	*game;

	map_destroy();
	player_destroy();
	enemies_destroy();
	ui_destroy();
	ftconfig_destroy(_config());
	fterr_destroy();
	renderer_destroy();
	game = _game();
	ft_bzero(game, sizeof(t_game));
}
