/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:54:24 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/27 01:04:47 by nsierra-         ###   ########.fr       */
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

t_renderer	*_renderer();

t_bool		renderer_init(void);
void		renderer_destroy(void);

#endif
