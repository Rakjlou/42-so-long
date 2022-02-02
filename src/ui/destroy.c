/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:38:08 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 21:28:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ui_destroy(void)
{
	t_game	*game;
	t_ui	*ui;

	game = _game();
	ui = &game->ui;
	if (ui->clear != NULL)
		image_destroy(ui->clear);
}
