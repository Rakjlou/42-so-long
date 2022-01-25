/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:50:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 14:48:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterr.h"
#include "ftprintf.h"
#include "libft.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	customprint(t_fterr *error)
{
	(void)error;
	fterr_print_ecode(error);
	ftfprintf(STDERR_FILENO, "%s\n", error->data);
}

static void	register_errors(void)
{
	fterr_register(USAGE, E_USAGE, NULL);
	fterr_register(CONFIG_FILE_OPEN, E_CONFIG_FILE_OPEN, customprint);
	fterr_register(MAP_FILE_OPEN, E_MAP_FILE_OPEN, NULL);
	fterr_register(INVALID_MAP_FILENAME, E_INVALID_MAP_FILENAME, NULL);
	fterr_register(INVALID_MAP_LINE, E_INVALID_MAP_LINE, NULL);
	fterr_register(INVALID_MAP, E_INVALID_MAP, NULL);
	fterr_register(FAILED_MALLOC, E_FAILED_MALLOC, NULL);
}

int	main(void)
{
	register_errors();
	fterr_set_error(USAGE);
	fterr_print();
	fterr_set(CONFIG_FILE_OPEN, "Test const", NULL);
	fterr_print();
	fterr_set(INVALID_MAP, ft_strdup("Test dup"), free);
	fterr_print();
	fterr_set(CONFIG_FILE_OPEN, ft_strdup("Test dup2"), free);
	fterr_print();
	fterr_destroy();
	return (0);
}

/*#include "so_long.h"
#include "libft.h"
#include <unistd.h>*/

/*static void	print_error(t_error error)
{
	ft_putendl_fd(ERROR_MSG, STDERR_FILENO);
	if (error == USAGE)
		ft_putendl_fd("Usage: ./so_long map.ber", STDERR_FILENO);
	else if (error == CONFIG_FILE_OPEN)
		ft_putendl_fd("Couldn't open config file config.txt", STDERR_FILENO);
	else if (error == MAP_FILE_OPEN)
		ft_putendl_fd("Couldn't open file map", STDERR_FILENO);
	else if (error == INVALID_MAP_FILENAME)
		ft_putendl_fd("The map file must be named MAPNAME.ber", STDERR_FILENO);
	else if (error == INVALID_MAP_LINE)
		ft_putendl_fd("The map has an invalid line", STDERR_FILENO);
	else if (error == INVALID_MAP)
		ft_putendl_fd("Invalid map", STDERR_FILENO);
	else if (error == FAILED_MALLOC)
		ft_putendl_fd("Malloc has failed", STDERR_FILENO);
	else
		ft_putendl_fd("Unknown error", STDERR_FILENO);
}*/

/*int	main(int ac, char **av)
{
	t_game	game;

	if (ac < 2 || ac > 2)
		return (print_error(USAGE), 1);
	else if (game_init(&game, av[1]) == FALSE)
		return (print_error(game.error), game_destroy(&game), 1);
	game_destroy(&game);
	return (0);
}*/
