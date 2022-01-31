#include "tile.h"
#include "errors.h"

t_tile	*tile_wall_new(
					unsigned int type,
					unsigned int x,
					unsigned int y)
{
	t_tile	*tile;

	tile = ft_calloc(sizeof(t_tile), 1);
	if (tile == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	tile->image = xpm_image_new("sprites/wall.xpm");
	if (tile->image == NULL)
		return (NULL);
	tile->type = type;
	tile->x = x;
	tile->y = y;
	tile->collides = TRUE;
	return (tile);
}