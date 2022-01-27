/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:57:28 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/27 01:08:02 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "errors.h"
#include "mlx.h"

t_bool	renderer_init(void)
{
	t_renderer	*renderer;
	char		*window_name;

	window_name = "so_long nsierra-";
	renderer = _renderer();
	renderer->core = mlx_init();
	if (renderer->core == NULL)
		return (fterr_set_error(MLX_FAILURE), FALSE);
	renderer->window = mlx_new_window(renderer->core, 1920, 1080, window_name);
	if (renderer->window == NULL)
		return (fterr_set_error(MLX_FAILURE), FALSE);
	return (TRUE);
}
