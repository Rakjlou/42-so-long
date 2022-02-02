/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:37:56 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 20:51:14 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	ui_init(void)
{
	t_game	*game;
	t_ui	*ui;

	game = _game();
	ui = &game->ui;
	ui->clear = image_new(UI_HEIGHT, game->map.size.y * TILE_PIXEL_SIZE);
	if (ui->clear == NULL)
		return (FALSE);
	ui->start.x = game->map.size.x * TILE_PIXEL_SIZE + 1;
	ui->start.y = 0;
	return (TRUE);
}
