/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:59:52 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 19:17:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "libft.h"
#include "ftprintf.h"
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

static void	error_conf_missky(t_fterr *error)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	fterr_print_ecode(error);
	ftfprintf(STDERR_FILENO, error->message, error->data);
}

void	errors_register(void)
{
	fterr_register(USAGE, E_USAGE, error_print);
	fterr_register(CONFIG_FILE_OPEN, E_CONFIG_FILE_OPEN, error_conf_fileopen);
	fterr_register(MISS_CONFIG_KEY, E_MISS_CONFIG_KEY, error_conf_missky);
	fterr_register(MAP_FILE_OPEN, E_MAP_FILE_OPEN, error_print);
	fterr_register(INVALID_MAP_FILENAME, E_INVALID_MAP_FILENAME, error_print);
	fterr_register(INVALID_MAP_LINE, E_INVALID_MAP_LINE, error_print);
	fterr_register(INVALID_MAP, E_INVALID_MAP, error_print);
	fterr_register(FAILED_MALLOC, E_FAILED_MALLOC, error_print);
}
