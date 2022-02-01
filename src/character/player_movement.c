#include "so_long.h"

t_bool	player_can_go(unsigned int x, unsigned int y)
{
	t_tile	*tile;
	t_map	*map;

	map = _map();
	if (x <= 0 || x >= map->size.x - 1 || y <= 0 || y >= map->size.y - 1)
		return (FALSE);
	tile = _map()->tile[(x * _map()->size.y) + y];
	if (tile->collides)
		return (FALSE);
	else if (tile->allow_stepping != NULL)
		return (tile->allow_stepping(tile));
	return (TRUE);
}

t_bool	player_can_go_up(void)
{
	return (player_can_go(_player()->pos.x - 1, _player()->pos.y));
}

t_bool	player_can_go_down(void)
{
	return (player_can_go(_player()->pos.x + 1, _player()->pos.y));
}

t_bool	player_can_go_right(void)
{
	return (player_can_go(_player()->pos.x, _player()->pos.y + 1));
}

t_bool	player_can_go_left(void)
{
	return (player_can_go(_player()->pos.x, _player()->pos.y - 1));
}

