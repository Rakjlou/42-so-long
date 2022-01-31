/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:10:25 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:23:03 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	image->filename = file;
	image->p.mlx_obj = mlx_xpm_file_to_image(
			_renderer()->core,
			(char *)file,
			&image->p.size.x,
			&image->p.size.y);
	if (image->p.mlx_obj == NULL)
		return (free(image), fterr_set(IMG_LOAD, (char *)file, NULL), NULL);
	image->p.buffer = mlx_get_data_addr(
			image->p.mlx_obj,
			&image->p.depth,
			&image->p.line_size,
			&image->p.endian);
	return (image);
}
