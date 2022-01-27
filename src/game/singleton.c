/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:34:35 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/27 00:56:46 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

t_game	*_game(void)
{
	static t_bool	first = TRUE;
	static t_game	game;

	if (first == TRUE)
	{
		ft_bzero(&game, sizeof(t_game));
		first = FALSE;
	}
	return (&game);
}

t_map	*_map(void)
{
	t_game	*game;

	game = _game();
	return (&game->map);
}

t_ftconfig	*_config(void)
{
	t_game	*game;

	game = _game();
	return (&game->config);
}

t_renderer	*_renderer(void)
{
	t_game	*game;

	game = _game();
	return (&game->renderer);
}
