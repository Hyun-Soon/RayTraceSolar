/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:00:58 by dongseo           #+#    #+#             */
/*   Updated: 2024/01/04 16:12:00 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HOOK_H
# define KEY_HOOK_H
# include "structures.h"
# include "utils.h"
# include "print.h"
# include "scene.h"
# include "trace.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14
# define KEY_G 5
# define KEY_SPACE 49
# define KEY_CTRL 256
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_F1 122
# define KEY_F2 120
# define KEY_F3 99
# define KEY_F4 118
# define KEY_0 29
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 26
# define KEY_8 28
# define KEY_9 25
# define KEY_F 3
# define KEY_OPEN 33
# define KEY_CLOSE 30

void		move_camera(int keycode, t_param *par);
int			key_hook(int keycode, t_param *par);
t_bool		is_teleport_key(int keycode);
t_bool		is_time_key(int keycode);
t_bool		is_move_key(int keycode);
t_bool		is_rotate_key(int keycode);
void		update_planet(t_param *par, int direction);
void		time_shift(int keycode, t_param *par);
void		cam_toward(t_param *par, char *org_name, char *dst_name);
void		top_view(t_param *par);
void		god_view(t_param *par);
t_planet	*find_mother(t_object *universe, char *name);
t_planet	*find_planet(t_object *obj_list, char *name);
void		multiverse(t_param *par, int keycode);

#endif
