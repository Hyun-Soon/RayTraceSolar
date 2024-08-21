/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:04:54 by hyuim             #+#    #+#             */
/*   Updated: 2024/01/04 17:14:53 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hook.h"

void	cam_toward(t_param *par, char *org_name, char *dst_name)
{
	t_planet	*org_planet;
	t_planet	*dst_planet;
	t_point3	org;
	t_point3	dst;
	double		distance;

	org_planet = find_planet(par->scene.world, org_name);
	dst_planet = find_planet(par->scene.world, dst_name);
	if (!org_planet || !dst_planet)
		return ;
	org = get_absolute_center(org_planet);
	dst = get_absolute_center(dst_planet);
	distance = vlength(vminus(dst, org)) \
		-(org_planet->radius + dst_planet->radius);
	par->scene.camera.normal = vunit(vminus(dst, org));
	par->scene.camera.orig = vminus(dst, \
		vmult(par->scene.camera.normal, dst_planet->radius * 3.0));
	camera(&par->scene.camera, par->scene.canvas.aspect_ratio);
	snapshot(par, &par->img);
}

void	top_view(t_param *par)
{
	par->scene.camera.normal = par->scene.init_view.dir;
	par->scene.camera.orig = par->scene.init_view.orig;
	camera(&par->scene.camera, par->scene.canvas.aspect_ratio);
	snapshot(par, &par->img);
}

void	god_view(t_param *par)
{
	par->scene.camera.normal = vunit(vec3(0, -1, 0.2));
	par->scene.camera.orig = vec3(0, 500000, 0);
	camera(&par->scene.camera, par->scene.canvas.aspect_ratio);
	snapshot(par, &par->img);
}

void	multiverse(t_param *par, int keycode)
{
	par->scene.camera.normal = vec3(-1, 0, 0);
	if (keycode == KEY_F1)
		par->scene.camera.orig = vec3(420000, -320000, 200000);
	else if (keycode == KEY_F2)
		par->scene.camera.orig = vec3(-320000, -200000, 280000);
	else if (keycode == KEY_F3)
		par->scene.camera.orig = vec3(400000, -200000, -120000);
	else if (keycode == KEY_F4)
		par->scene.camera.orig = vec3(-440000, -200000, -200000);
	camera(&par->scene.camera, par->scene.canvas.aspect_ratio);
	snapshot(par, &par->img);
}
