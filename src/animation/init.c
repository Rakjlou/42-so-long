#include "animation.h"
#include "errors.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

t_animation	*animation_new(unsigned int f_count, ...)
{
	t_animation		*animation;
	va_list			args;
	unsigned int	i;
	char			*file;

	animation = ft_calloc(sizeof(t_animation), 1);
	if (animation == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	animation->frame = ft_calloc(sizeof(t_frame), f_count);
	if (animation->frame == NULL)
		return (free(animation), fterr_set_error(FAILED_MALLOC), NULL);
	i = 0;
	animation->f_count = f_count;
	va_start(args, f_count);
	while (i < f_count)
	{
		animation->frame[i].duration = va_arg(args, unsigned int);
		file = va_arg(args, char *);
		animation->frame[i].image = xpm_image_new(file);
		if (animation->frame[i].image == NULL)
			return (animation_destroy(animation), NULL);
		++i;
	}
	va_end(args);
	return (animation);
}
