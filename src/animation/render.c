#include "animation.h"
#include "errors.h"
#include "libft.h"
#include "ftprintf.h"
#include <stdarg.h>
#include <stdlib.h>

void	animation_render(t_animation *animation, unsigned int x, unsigned int y)
{
	t_frame	*frame;

	frame = &animation->frame[animation->current];
/*	ftprintf("Printing animation img %u / %u frame (%s) %u / %u\n",
		animation->current, animation->f_count,
		);*/
	xpm_image_render(frame->image, x, y);
	if (++frame->current >= frame->duration)
	{
		frame->current = 0;
		++animation->current;
		if (animation->current >= animation->f_count)
			animation->current = 0;
	}
}