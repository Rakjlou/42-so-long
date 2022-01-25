/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:47:56 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 22:16:25 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "fterr.h"

void	game_destroy(t_game *game)
{
	(void)game;
	map_free(&game->map);
	ftconfig_destroy(&game->config);
	fterr_destroy();
}
