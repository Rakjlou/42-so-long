/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:10:25 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 21:05:43 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "libft.h"

typedef struct s_image
{
	void		*mlx_obj;
	char		*buffer;
	t_vector	size;
	int			line_size;
	int			endian;
	int			depth;
}	t_image;

typedef struct s_xpm_image
{
	t_image		p;
	const char	*filename;
}	t_xpm_image;

t_image		*image_new(int height, int width);
void		image_destroy(t_image *image);
void		image_render(t_image *image, int x, int y);

t_xpm_image	*xpm_image_new(const char *file);
void		xpm_image_destroy(t_xpm_image *image);
void		xpm_image_render(t_xpm_image *image, int x, int y);

#endif
