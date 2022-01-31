#include "image.h"
#include "renderer.h"
#include "mlx.h"
#include <stdlib.h>

void	xpm_image_destroy(t_xpm_image *image)
{
	mlx_destroy_image(_renderer()->core, image->p.mlx_obj);
	free(image);
}
