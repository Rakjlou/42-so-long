#include "image.h"
#include "renderer.h"
#include "errors.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

t_xpm_image	*xpm_image_new(const char *file)
{
	t_xpm_image	*image;

	image = ft_calloc(sizeof(t_xpm_image), 1);
	if (image == NULL)
		return (fterr_set_error(FAILED_MALLOC), NULL);
	image->p.height = 42;
	image->p.mlx_obj = mlx_xpm_file_to_image(
		_renderer()->core,
		(char *)file,
		&image->p.height,
		&image->p.width);
	if (image->p.mlx_obj == NULL)
		return (free(image), fterr_set(IMG_LOAD, (char *)file, NULL), NULL);
	image->p.buffer = mlx_get_data_addr(
		image->p.mlx_obj,
		&image->p.depth,
		&image->p.line_size,
		&image->p.endian);
	return (image);
}