#ifndef ANIMATION_H
# define ANIMATION_H

# include "image.h"

typedef struct s_frame
{
	unsigned int	current;
	unsigned int	duration;
	t_xpm_image		*image;
}	t_frame;

typedef struct s_animation
{
	unsigned int	current;
	unsigned int	f_count;
	t_frame			*frame;
}	t_animation;

t_animation	*animation_new(unsigned int f_count, ...);
void		animation_render(
				t_animation *animation,
				unsigned int x,
				unsigned int y);
void		animation_destroy(t_animation *animation);

#endif