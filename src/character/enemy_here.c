/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_here.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:16:53 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 22:19:56 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	enemy_here(unsigned int x, unsigned int y)
{
	unsigned int	i;
	t_character		**enemies;
	t_character		*enemy;

	i = 0;
	enemies = _game()->enemy;
	if (enemies == NULL)
		return (FALSE);
	while (enemies[i] != NULL)
	{
		enemy = enemies[i];
		if (enemy->pos.x == x && enemy->pos.y == y)
			return (TRUE);
		++i;
	}
	return (FALSE);
}
