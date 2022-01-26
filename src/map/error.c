/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:31:47 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 00:47:23 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"
#include "libft.h"
#include "errors.h"
#include <stdlib.h>

t_map_error	*map_error_new(size_t line_number, char *message, char *line)
{
	t_map_error	*error;

	error = ft_calloc(sizeof(t_map_error), 1);
	if (error == NULL)
		return (NULL);
	error->line_number = line_number + 1;
	error->line = line;
	error->message = message;
	return (error);
}

t_bool	map_error(size_t line_number, char *message, char *line)
{
	t_map_error	*error;

	error = map_error_new(line_number, message, line);
	if (error == NULL)
		fterr_set_error(FAILED_MALLOC);
	else
		fterr_set(INVALID_MAP, error, free);
	return (FALSE);
}
