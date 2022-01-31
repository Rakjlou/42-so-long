/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:13:54 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/31 14:24:51 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ftprintf.h"
#include <unistd.h>

int	close_callback(void)
{
	ftprintf("CLOSE HOOK\n");
	game_destroy();
	exit(0);
	return (1);
}
