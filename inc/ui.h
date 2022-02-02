/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:32:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 21:29:46 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "image.h"
# include "libft.h"

# define UI_HEIGHT 50

typedef struct s_ui
{
	t_image			*clear;
	t_vector		start;
	unsigned int	player_movements;
}	t_ui;

void	ui_clear(void);
void	ui_render(void);
void	ui_destroy(void);
t_bool	ui_init(void);

#endif
