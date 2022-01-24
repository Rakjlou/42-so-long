/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/24 23:23:05 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <unistd.h>

static void	print_error(t_error error)
{
	ft_putendl_fd(ERROR_MSG, STDERR_FILENO);
	if (error == USAGE)
		ft_putendl_fd("Usage: ./so_long map.ber", STDERR_FILENO);
	else if (error == CONFIG_FILE_OPEN)
		ft_putendl_fd("Couldn't open config file config.txt", STDERR_FILENO);
	else if (error == FAILED_MALLOC)
		ft_putendl_fd("Malloc has failed", STDERR_FILENO);
	else
		ft_putendl_fd("Unknown error", STDERR_FILENO);
}

int	main(int ac, char **av)
{
	t_game	game;

	(void)ac;
	(void)av;
	if (ac < 2 || ac > 2)
		return (print_error(USAGE), 1);
	else if (game_init(&game) == FALSE)
		return (print_error(game.error), game_destroy(&game), 1);
	game_destroy(&game);
	return (0);
}
