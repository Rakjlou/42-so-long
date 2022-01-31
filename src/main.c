/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osboxes <osboxes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/29 19:05:20 by osboxes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errors.h"
#include "image.h"
#include "libft.h"
#include "ftprintf.h"
#include "mlx.h"

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

int key_hook_callback(int keycode)
{
	ftprintf("KEY HOOK %d\n", keycode);
	return (1);
}

int mouse_hook_callback(int button, int x, int y)
{
	ftprintf("MOUSE HOOK button: %d x: %d y: %d\n", button, x, y);
	return (1);
}

int expose_hook_callback()
{
	ftprintf("EXPOSE HOOK\n");
	return (1);
}

int loop_hook_callback()
{
	game_render();
	return (1);
}

int close_callback()
{
	ftprintf("CLOSE HOOK\n");
	game_destroy();
	exit(0);
	return (1);
}

int	main(int ac, const char **av)
{


	if (ac < 2 || ac > 2)
	{
		ft_putendl_fd("Usage: ./so_long MAPNAME.ber", 2);
		return (1);
	}
	if (!game_init(av[1]))
		return (fterr_print(), game_destroy(), 2);
	mlx_key_hook(_renderer()->window, key_hook_callback, NULL);
	mlx_mouse_hook(_renderer()->window, mouse_hook_callback, NULL);
	mlx_expose_hook(_renderer()->window, expose_hook_callback, NULL);
	mlx_loop_hook(_renderer()->core, loop_hook_callback, NULL);
	mlx_hook(_renderer()->window, 17, 0, close_callback, NULL);
	mlx_loop(_renderer()->core);
	return (0);
}
