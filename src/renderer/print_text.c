/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:19:42 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 18:22:17 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "mlx.h"

void	renderer_print_text(char *text, int color, int x, int y)
{
	t_renderer	*r;

	r = _renderer();
	mlx_string_put(r->core, r->window, x, y, color, text);
}
