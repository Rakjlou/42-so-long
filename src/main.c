/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/03 22:06:18 by nsierra-         ###   ########.fr       */
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
	mlx_loop(_renderer()->core);
	return (0);
}
