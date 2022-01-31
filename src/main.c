/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:17:14 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errors.h"
#include "image.h"
#include "libft.h"
#include "ftprintf.h"
#include "mlx.h"

int	main(int ac, const char **av)
{
	if (ac < 2 || ac > 2)
	{
		ft_putendl_fd("Usage: ./so_long MAPNAME.ber", 2);
		return (1);
	}
	if (!game_init(av[1]))
		return (fterr_print(), game_destroy(), 2);
	mlx_key_hook(_renderer()->window, key_hook_callback, NULL);
	mlx_hook(_renderer()->window, 2, 0, key_hook_callback, NULL);
	mlx_mouse_hook(_renderer()->window, mouse_hook_callback, NULL);
	mlx_expose_hook(_renderer()->window, expose_hook_callback, NULL);
	mlx_loop_hook(_renderer()->core, loop_hook_callback, NULL);
	mlx_hook(_renderer()->window, 17, 0, close_callback, NULL);
	mlx_loop(_renderer()->core);
	return (0);
}
