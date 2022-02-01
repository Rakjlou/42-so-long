#include "tile.h"
#include "ftprintf.h"
#include "map.h"

t_tile	*tile_get(unsigned int x, unsigned int y)
{
	t_map	*map;

	map = _map();
	return (map->tile[(x * map->size.y) + y]);
}