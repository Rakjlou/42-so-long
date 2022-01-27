/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/27 02:59:34 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errors.h"
#include "renderer.h"
#include "libft.h"
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

int	main(int ac, const char **av)
{
	int	a;
	int	b;
	t_renderer	*r;
	void		*img;
	void		*img2;

	if (ac < 2 || ac > 2)
	{
		ft_putendl_fd("Usage: ./so_long MAPNAME.ber", 2);
		return (1);
	}
	if (!game_init(av[1]))
		return (fterr_print(), game_destroy(), 2);
	r = _renderer();
	img = mlx_xpm_file_to_image(r->core, "sprites/grass.xpm", &a, &b);
	img2 = mlx_xpm_file_to_image(r->core, "sprites/wall.xpm", &a, &b);
	if (img == NULL)
	{
		ft_putendl_fd("FDFLJFJD", 2);
		return (3);
	}
	mlx_put_image_to_window(r->core, r->window, img, 0, 0);
	mlx_put_image_to_window(r->core, r->window, img2, 0, 0);
	mlx_loop(_renderer()->core);
	mlx_destroy_image(r->core, img);
	game_destroy();
	return (0);
}
