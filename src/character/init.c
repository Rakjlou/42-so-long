#include "so_long.h"
#include "errors.h"
#include "libft.h"
#include <stdlib.h>

static void	player_update(t_character *character)
{
	t_game	*game;
	t_input	*input;

	game = _game();
	input = &game->input;
	if (input->up && !input->down)
		game->player.x = (unsigned int)ft_max(0, (int)(character->x - 1));
	else if (input->right && !input->left)
		game->player.y = (unsigned int)ft_min((int)game->map.width, (int)(character->y + 1));
	else if (input->down && !input->up)
		game->player.x = (unsigned int)ft_min((int)game->map.height, (int)(character->x + 1));
	else if (input->left && !input->right)
		game->player.y = (unsigned int)ft_max(0, (int)(character->y - 1));
	ft_bzero(input, sizeof(t_input));
}

static void	character_render(t_character *character)
{
	xpm_image_render(character->image, character->x, character->y);
}

t_character	*character_new(unsigned int x, unsigned y, const char *sprite_file)
{
	t_character	*character;

	character = ft_calloc(sizeof(t_character), 1);
	if (character == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	character->image = xpm_image_new(sprite_file);
	if (character->image == NULL)
		return (free(character), NULL);
	character->x = x;
	character->y = y;
	character->render = character_render;
	return (character);
}

t_bool	player_init(void)
{
	t_game	*game;

	game = _game();
	game->player.image = xpm_image_new("sprites/player1.xpm");
	if (game->player.image == NULL)
		return (FALSE);
	game->player.render = character_render;
	game->player.update = player_update;
	return (TRUE);
}
