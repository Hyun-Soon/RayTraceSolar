/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:51:36 by hyuim             #+#    #+#             */
/*   Updated: 2024/01/04 16:05:40 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hook.h"

t_bool	is_teleport_key(int keycode)
{
	if ((keycode >= 18 && keycode <= 29) || keycode == KEY_G \
		|| keycode == KEY_F1 || keycode == KEY_F2 \
		|| keycode == KEY_F3 || keycode == KEY_F4)
		return (TRUE);
	return (FALSE);
}

t_bool	is_time_key(int keycode)
{
	if (keycode == KEY_OPEN || keycode == KEY_CLOSE)
		return (TRUE);
	return (FALSE);
}

t_bool	is_move_key(int keycode)
{
	if (KEY_Q <= keycode && keycode <= KEY_E)
		return (TRUE);
	if (KEY_A <= keycode && keycode <= KEY_D)
		return (TRUE);
	return (FALSE);
}

t_bool	is_rotate_key(int keycode)
{
	if (KEY_LEFT <= keycode && keycode <= KEY_UP)
		return (TRUE);
	return (FALSE);
}
