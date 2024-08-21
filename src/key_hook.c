/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:00:34 by dongseo           #+#    #+#             */
/*   Updated: 2024/01/04 16:10:38 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hook.h"

void	move_camera(int keycode, t_param *par)
{
	if (keycode == KEY_E)
		par->scene.camera.orig = vplus(par->scene.camera.orig, \
			vmult(par->scene.camera.up, (double)SPEED));
	else if (keycode == KEY_Q)
		par->scene.camera.orig = vminus(par->scene.camera.orig, \
			vmult(par->scene.camera.up, (double)SPEED));
	else if (keycode == KEY_S)
		par->scene.camera.orig = vminus(par->scene.camera.orig, \
			vmult(par->scene.camera.forward, (double)SPEED));
	else if (keycode == KEY_A)
		par->scene.camera.orig = vminus(par->scene.camera.orig, \
			vmult(par->scene.camera.right, (double)SPEED));
	else if (keycode == KEY_D)
		par->scene.camera.orig = vplus(par->scene.camera.orig, \
			vmult(par->scene.camera.right, (double)SPEED));
	else if (keycode == KEY_W)
		par->scene.camera.orig = vplus(par->scene.camera.orig, \
			vmult(par->scene.camera.forward, (double)SPEED));
	camera(&par->scene.camera, par->scene.canvas.aspect_ratio);
	snapshot(par, &par->img);
}

void	rotate_camera(int keycode, t_param *par)
{
	double	theta;

	theta = M_PI / 18;
	if (keycode == KEY_LEFT)
		par->scene.camera.normal = rotate_y(par->scene.camera.normal, theta);
	else if (keycode == KEY_RIGHT)
		par->scene.camera.normal = rotate_y(par->scene.camera.normal, -theta);
	else if (keycode == KEY_UP)
		rotate_h(&par->scene.camera, theta);
	else if (keycode == KEY_DOWN)
		rotate_h(&par->scene.camera, -theta);
	camera(&par->scene.camera, par->scene.canvas.aspect_ratio);
	snapshot(par, &par->img);
}

void	teleport_camera(int keycode, t_param *par)
{
	if (keycode == KEY_0)
		top_view(par);
	else if (keycode == KEY_1)
		cam_toward(par, "EARTH", "SUN");
	else if (keycode == KEY_2)
		cam_toward(par, "SUN", "MERC");
	else if (keycode == KEY_3)
		cam_toward(par, "SUN", "VENUS");
	else if (keycode == KEY_4)
		cam_toward(par, "SUN", "EARTH");
	else if (keycode == KEY_5)
		cam_toward(par, "SUN", "MARS");
	else if (keycode == KEY_6)
		cam_toward(par, "SUN", "JUPITER");
	else if (keycode == KEY_7)
		cam_toward(par, "SUN", "SATURN");
	else if (keycode == KEY_9)
		cam_toward(par, "EARTH", "MOON");
	else if (keycode == KEY_G)
		god_view(par);
	else if (keycode == KEY_8)
		return ;
	else
		multiverse(par, keycode);
}

int	chmod(t_scene *scene)
{
	if (scene->dt == DAY)
		scene->dt = WEEK;
	else if (scene->dt == WEEK)
		scene->dt = MONTH;
	else if (scene->dt == MONTH)
		scene->dt = YEAR;
	else if (scene->dt == YEAR)
		scene->dt = DAY;
	return (0);
}

int	key_hook(int keycode, t_param *par)
{
	if (keycode == 53)
	{
		mlx_destroy_window(par->mlx, par->win);
		exit(0);
	}
	else if (keycode == KEY_SPACE)
		return (anti_aliasing(par));
	else if (is_move_key(keycode))
		move_camera(keycode, par);
	else if (is_rotate_key(keycode))
		rotate_camera(keycode, par);
	else if (is_teleport_key(keycode))
		teleport_camera(keycode, par);
	else if (is_time_key(keycode))
		time_shift(keycode, par);
	else if (keycode == KEY_F)
		return (chmod(&par->scene));
	par->aa_flag = FALSE;
	return (0);
}
