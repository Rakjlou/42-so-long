/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:10:25 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:11:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_image
{
	void	*mlx_obj;
	char	*buffer;
	int		x;
	int		y;
	int		height;
	int		width;
	int		line_size;
	int		endian;
	int		depth;
}	t_image;

typedef struct s_xpm_image
{
	t_image		p;
	const char	*filename;
}	t_xpm_image;

t_xpm_image	*xpm_image_new(const char *file);
void		xpm_image_destroy(t_xpm_image *image);
void		xpm_image_render(t_xpm_image *image, int x, int y);

#endif
