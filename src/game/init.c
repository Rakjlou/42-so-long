/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:46:50 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/26 22:49:37 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errors.h"
#include "libft.h"
#include "ftprintf.h"

t_bool	game_init(const char *mapfile)
{
	errors_register();
	return (config_init("config.txt") && map_init(mapfile));
}
