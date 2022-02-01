#include "animation.h"
#include "errors.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

void	animation_render(t_animation *animation, unsigned int x, unsigned int y)
{
	t_frame	*frame;

	frame = &animation->frame[animation->current];
	xpm_image_render(frame->image, x, y);
	if (animation->f_count <= 1 && frame->duration <= 1)
		return ;
	if (++frame->current >= frame->duration)
	{
		frame->current = 0;
		++animation->current;
		if (animation->current >= animation->f_count)
			animation->current = 0;
	}
}