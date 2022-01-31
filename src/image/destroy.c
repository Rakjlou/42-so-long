/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:10:25 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:20:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "renderer.h"
#include "mlx.h"
#include <stdlib.h>

void	xpm_image_destroy(t_xpm_image *image)
{
	mlx_destroy_image(_renderer()->core, image->p.mlx_obj);
	free(image);
}
