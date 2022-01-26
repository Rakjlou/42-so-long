/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 22:40:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errors.h"
#include "libft.h"
#include "ftprintf.h"

/*static void	shell_renderer(t_game *game)
{
	unsigned int	x;
	unsigned int	y;
	t_tile			*tile;

	x = 0;
	ftprintf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	while (x < game->map.height)
	{
		y = 0;
		while (y < game->map.length)
		{
			tile = map_tile_get(&game->map, x, y);
			ftprintf("%c ", tile->type);
			++y;
		}
		ftprintf("\n");
		++x;
	}
}*/

int	main(int ac, const char **av)
{
	if (ac < 2 || ac > 2)
	{
		ft_putendl_fd("Usage: ./so_long MAPNAME.ber", 2);
		return (1);
	}
	if (!game_init(av[1]))
		return (fterr_print(), game_destroy(), 2);
	game_destroy();
	return (0);
}
