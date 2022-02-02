/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 01:29:09 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 01:29:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	enemy_v_destroy(t_character *character)
{
	t_enemy_v	*enemy;

	enemy = (t_enemy_v *)character;
	animation_destroy(enemy->animation_top);
	animation_destroy(enemy->animation_down);
	character->animation = NULL;
	free(enemy);
}
