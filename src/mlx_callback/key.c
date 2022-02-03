/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:13:54 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/03 23:19:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ftprintf.h"

int	key_hook_callback(int keycode)
{
	t_game		*game;
	t_input		*input;

	game = _game();
	input = &game->input;
	if (keycode == KEYCODE_UP)
		input->up = TRUE;
	else if (keycode == KEYCODE_DOWN)
		input->down = TRUE;
	else if (keycode == KEYCODE_RIGHT)
		input->right = TRUE;
	else if (keycode == KEYCODE_LEFT)
		input->left = TRUE;
	else if (keycode == KEYCODE_SPACE)
		input->attack = TRUE;
	else if (keycode == KEYCODE_ESC)
		input->close = TRUE;
	return (1);
}
