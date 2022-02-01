#include "tile.h"
#include "map.h"
#include "ftprintf.h"
#include "errors.h"

static void	tile_enemy_up_on_stepping(t_tile *t)
{
	t_tile_bistate	*tile;
	t_xpm_image		*tmp;

	ftprintf("STEZPPING\n");
	tile = (t_tile_bistate *)t;
	if (tile->state == TRUE)
		return ;
	tile->state = TRUE;
	tmp = t->image;
	t->image = tile->image2;
	tile->image2 = tmp;
	_map()->enemy_ups_count--;
}

static void	tile_enemy_up_destroy(t_tile *t)
{
	t_tile_bistate	*tile;

	tile = (t_tile_bistate *)t;
	xpm_image_destroy(tile->image2);
	tile_default_destroy(t);
}

t_tile	*tile_enemy_up_new(
					unsigned int type,
					unsigned int x,
					unsigned int y)
{
	t_tile_bistate	*tile;

	tile = ft_calloc(sizeof(t_tile_bistate), 1);
	if (tile == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	tile->p.image = xpm_image_new("sprites/enemy_up.xpm");
	if (tile->p.image == NULL)
		return (NULL);
	tile->image2 = xpm_image_new("sprites/floor.xpm");
	if (tile->image2 == NULL)
		return (xpm_image_destroy(tile->p.image), NULL);
	tile->p.type = type;
	tile->p.pos.x = x;
	tile->p.pos.y = y;
	tile->p.destroy = tile_enemy_up_destroy;
	tile->p.on_stepping = tile_enemy_up_on_stepping;
	tile->p.render = tile_render;
	return (as_tile(tile));
}
