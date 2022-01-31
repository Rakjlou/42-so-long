#include "tile.h"

void	tile_render(t_tile *tile)
{
	xpm_image_render(tile->image, tile->pos.x, tile->pos.y);
}