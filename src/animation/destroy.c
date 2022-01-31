#include "animation.h"
#include <stdlib.h>

void	animation_destroy(t_animation *animation)
{
	unsigned int	i;

	i = 0;
	while (i < animation->f_count)
	{
		if (animation->frame[i].image != NULL)
			xpm_image_destroy(animation->frame[i].image);
		++i;
	}
	free(animation->frame);
	free(animation);
}
