/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:03:26 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 22:01:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ftprintf.h"

void	ui_clear(void)
{
	t_game	*game;
	t_ui	*ui;

	game = _game();
	ui = &game->ui;
	image_render(ui->clear, ui->start.x, ui->start.y);
}

void	ui_render(void)
{
	unsigned char	i;
	unsigned char	collectibles;
	char			buffer[1024];
	t_game			*game;
	t_ui			*ui;

	ui_clear();
	game = _game();
	ui = &game->ui;
	ftsprintf(buffer, 1024, "%-13s %u", "Movements", ui->player_movements);
	renderer_print_text(buffer, 0xFFFFFFFF, 0, ui->start.x + 15);
	ftsprintf(buffer, 1024, "%-13s %u/3", "HP", game->player.hp);
	renderer_print_text(buffer, 0xFFFFFFFF, 0, ui->start.x + 30);
	ftsprintf(buffer, 1024, "%-13s ", "Collectibles");
	collectibles = _map()->collectibles_count;
	i = ft_strlen(buffer);
	while (collectibles--)
		buffer[i++] = '*';
	buffer[i] = '\0';
	renderer_print_text(buffer, 0xFFFFFFFF, 0, ui->start.x + 45);
}
