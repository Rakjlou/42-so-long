/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 01:18:51 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/01 18:14:11 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include "libft.h"
# include "image.h"
# include "animation.h"

typedef struct s_character
{
	t_uvector		pos;
	t_animation		*animation;
	unsigned int	hp;
	void			(*render)(struct s_character *);
	void			(*update)(struct s_character *);
	void			(*destroy)(struct s_character *);
	void			(*on_collide)(struct s_character *);
	void			(*hit)(struct s_character *, struct s_character *);
}	t_character;

typedef struct s_enemy_v
{
	t_character	p;
	int			direction;
	t_animation	*animation_top;
	t_animation	*animation_down;
}	t_enemy_v;

t_character	*character_new(unsigned int x,
				unsigned int y,
				const char *sprite_file);
void		character_destroy(t_character *character);
void		character_render(t_character *character);

t_bool		enemy_add(unsigned char type, unsigned int x, unsigned int y);

t_enemy_v	*enemy_v_new(
				unsigned char type,
				unsigned int x,
				unsigned int y);
void		enemy_v_update(t_character *character);
void		enemy_v_on_collide(t_character *character);
void		enemy_v_destroy(t_character *character);

t_character	*_player(void);
t_bool		player_init(void);
void		player_update(t_character *player);
void		player_destroy(void);
t_bool		character_can_go(unsigned int x, unsigned int y);
t_bool		player_can_go_up(void);
t_bool		player_can_go_down(void);
t_bool		player_can_go_right(void);
t_bool		player_can_go_left(void);

#endif
