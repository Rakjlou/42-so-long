#include "so_long.h"
#include "ftprintf.h"

static void	game_render_map_shell(t_map *map)
{
	t_iter			iter;
	char			*line;

	iter_init(&iter, &map->file.data, ASC);
	while (iter_next(&iter))
	{
		line = (char *)iter.data;
		ftprintf("%s\n", line);
	}
}

static void	game_render_map(void)
{
	unsigned int	x;
	unsigned int	y;
	t_map			*map;
	t_tile			*tile;


	x = 0;
	map = _map();
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			tile = map->tile[(x * map->width) + y];
			xpm_image_render(tile->image, x, y);
			++y;
		}
		++x;
	}
}

int		game_render(void)
{
	(void)game_render_map_shell;
	game_render_map();
	/*game_render_map_shell(_map());*/
	return (1);
}