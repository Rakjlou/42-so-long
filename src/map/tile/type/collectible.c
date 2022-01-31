#include "tile.h"
#include "errors.h"

static void	tile_collectible_interact(t_tile *t)
{
	t_tile_bistate	*tile;
	t_xpm_image		*tmp;

	tile = (t_tile_bistate *)t;
	if (tile->state == TRUE)
		return ;
	tile->state = TRUE;
	tmp = t->image;
	t->image = tile->image2;
	tile->image2 = tmp;
}

static void	tile_collectible_destroy(t_tile *t)
{
	t_tile_bistate	*tile;

	tile = (t_tile_bistate *)t;
	xpm_image_destroy(tile->image2);
	tile_default_destroy(t);
}

t_tile	*tile_collectible_new(
					unsigned int type,
					unsigned int x,
					unsigned int y)
{
	t_tile_bistate	*tile;

	tile = ft_calloc(sizeof(t_tile_bistate), 1);
	if (tile == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	tile->p.image = xpm_image_new("sprites/collectible.xpm");
	if (tile->p.image == NULL)
		return (NULL);
	tile->image2 = xpm_image_new("sprites/floor.xpm");
	if (tile->image2 == NULL)
		return (xpm_image_destroy(tile->p.image), NULL);
	tile->p.type = type;
	tile->p.x = x;
	tile->p.y = y;
	tile->p.collides = TRUE;
	tile->p.destroy = tile_collectible_destroy;
	tile->p.on_interact = tile_collectible_interact;
	return (as_tile(tile));
}