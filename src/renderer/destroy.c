/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:57:28 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/27 01:09:53 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

void	renderer_destroy(void)
{
	t_renderer	*renderer;

	renderer = _renderer();
	if (renderer->core == NULL)
		return ;
	if (renderer->window != NULL)
		mlx_destroy_window(renderer->core, renderer->window);
	mlx_destroy_display(renderer->core);
	free(renderer->core);
	ft_bzero(renderer, sizeof(t_renderer));
}
