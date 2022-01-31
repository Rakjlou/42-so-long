/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:59:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:30:40 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "libft.h"
#include "ftprintf.h"
#include "map_validation.h"
#include <unistd.h>

static void	error_print(t_fterr *error)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	fterr_default_print(error);
}

static void	error_conf_fileopen(t_fterr *error)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	fterr_print_ecode(error);
	ftfprintf(STDERR_FILENO, "Cannot open config file %s\n", error->data);
}

static void	error_printf(t_fterr *error)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	fterr_print_ecode(error);
	ftfprintf(STDERR_FILENO, error->message, error->data);
	ftfprintf(STDERR_FILENO, "\n");
}

static void	error_invalid_map(t_fterr *error)
{
	t_map_error	*merr;

	ft_putendl_fd("Error", STDERR_FILENO);
	fterr_print_ecode(error);
	if (error->data_free == NULL && error->data != NULL)
		ftfprintf(STDERR_FILENO, "%s: %s\n", error->message, error->data);
	else if (error->data_free != NULL)
	{
		merr = (t_map_error *)error->data;
		if (merr->line_number > 0)
		{
			ftfprintf(STDERR_FILENO,
				"%s: %s\n\tline %3u: %s\n",
				error->message,
				merr->message,
				merr->line_number,
				merr->line);
		}
		else
			ftfprintf(STDERR_FILENO, "%s: %s\n", error->message, merr->message);
	}
	else
		ftfprintf(STDERR_FILENO, error->message);
}

void	errors_register(void)
{
	fterr_register(USAGE, E_USAGE, error_print);
	fterr_register(CONFIG_FILE_OPEN, E_CONFIG_FILE_OPEN, error_conf_fileopen);
	fterr_register(MISS_CONFIG_KEY, E_MISS_CONFIG_KEY, error_printf);
	fterr_register(MISS_CONFIG_VAL, E_MISS_CONFIG_KEY, error_printf);
	fterr_register(MAP_FILE_OPEN, E_MAP_FILE_OPEN, error_print);
	fterr_register(INVALID_MAP_FILENAME, E_INVALID_MAP_FILENAME, error_print);
	fterr_register(INVALID_MAP_LINE, E_INVALID_MAP_LINE, error_print);
	fterr_register(INVALID_MAP, E_INVALID_MAP, error_invalid_map);
	fterr_register(MLX_FAILURE, E_MLX_FAILURE, error_print);
	fterr_register(FAILED_MALLOC, E_FAILED_MALLOC, error_print);
	fterr_register(IMG_LOAD, E_IMG_LOAD, error_printf);
	fterr_register(UNKNOWN, E_DEFAULT, error_print);
}
