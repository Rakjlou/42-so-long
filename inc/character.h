#ifndef CHARACTER_H
# define CHARACTER_H

# include "libft.h"
# include "image.h"

typedef struct s_character
{
	t_uvector	pos;
	t_xpm_image	*image;
	void		(*render)(struct s_character *);
	void		(*update)(struct s_character *);
}	t_character;

t_character	*_player(void);
t_character	*character_new(unsigned int x, unsigned y, const char *sprite_file);
t_bool		player_init(void);
void		character_destroy(t_character *character);
void		player_destroy(void);

# endif
