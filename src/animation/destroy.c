/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 01:18:51 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 01:22:03 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
