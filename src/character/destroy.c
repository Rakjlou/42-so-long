#include "so_long.h"
#include "errors.h"
#include "libft.h"
#include <stdlib.h>

void	character_destroy(t_character *character)
{
	xpm_image_destroy(character->image);
	free(character);
}

void	player_destroy(void)
{
	t_character	*player;

	player = _player();
	xpm_image_destroy(player->image);
}
