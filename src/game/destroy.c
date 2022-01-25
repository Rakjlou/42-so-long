/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:47:56 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/25 19:30:01 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "fterr.h"

void	game_destroy(t_game *game)
{
	(void)game;
	ftconfig_destroy(&game->config);
	fterr_destroy();
}
