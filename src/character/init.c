#include "so_long.h"
#include "animation.h"
#include "errors.h"
#include "libft.h"
#include "ftprintf.h"
#include <stdlib.h>

static void	player_update(t_character *player)
{
	t_game	*game;
	t_input	*input;

	game = _game();
	input = &game->input;
	if (input->up && !input->down)
		player->pos.x = ft_uimax(0, player->pos.x - 1);
	else if (input->right && !input->left)
		player->pos.y = ft_umin(game->map.size.y - 1, player->pos.y + 1);
	else if (input->down && !input->up)
		player->pos.x = ft_umin(game->map.size.x - 1, player->pos.x + 1);
	else if (input->left && !input->right)
		player->pos.y = ft_uimax(0, player->pos.y - 1);
	ft_bzero(input, sizeof(t_input));
}

static void	character_render(t_character *character)
{
	animation_render(character->animation, character->pos.x, character->pos.y);
}

t_character	*character_new(unsigned int x, unsigned y, const char *sprite_file)
{
	t_character	*character;

	(void)sprite_file;
	character = ft_calloc(sizeof(t_character), 1);
	if (character == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	character->pos.x = x;
	character->pos.y = y;
	character->render = character_render;
	return (character);
}

t_bool	player_init(void)
{
	t_game	*game;

	game = _game();
	game->player.animation = animation_new(
		5,
		20, "sprites/player1.xpm",
		25, "sprites/player2.xpm",
		30, "sprites/player3.xpm",
		35, "sprites/player4.xpm",
		40, "sprites/player5.xpm");
	if (game->player.animation == NULL)
		return (FALSE);
	game->player.render = character_render;
	game->player.update = player_update;
	return (TRUE);
}
