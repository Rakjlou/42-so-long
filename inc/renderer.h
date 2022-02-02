/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:54:24 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 18:40:14 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "libft.h"

typedef void	t_mlx_core;
typedef void	t_mlx_window;

typedef struct s_renderer
{
	t_mlx_core		*core;
	t_mlx_window	*window;
}	t_renderer;

t_renderer	*_renderer(void);

t_bool		renderer_init(void);
void		renderer_destroy(void);
void		renderer_clear_window(void);
void		renderer_print_text(char *text, int color, int x, int y);

#endif
