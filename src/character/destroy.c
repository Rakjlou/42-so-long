#include "so_long.h"
#include "errors.h"
#include "libft.h"
#include <stdlib.h>

void	character_destroy(t_character *character)
{
	animation_destroy(character->animation);
	free(character);
}

void	player_destroy(void)
{
	t_character	*player;

	player = _player();
	animation_destroy(player->animation);
}
