/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:47:56 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/27 01:02:31 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "fterr.h"

void	game_destroy(void)
{
	t_game	*game;

	map_destroy();
	player_destroy();
	ftconfig_destroy(_config());
	fterr_destroy();
	renderer_destroy();
	game = _game();
	ft_bzero(game, sizeof(t_game));
}
