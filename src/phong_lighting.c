/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:55:47 by yusekim           #+#    #+#             */
/*   Updated: 2024/01/04 11:39:47 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vminus(v, vmult(n, vdot(v, n) * 2)));
}

t_bool	in_shadow(t_scene *scene, t_light *light, t_vec3 *light_dir)
{
	t_hit_rec	rec;
	double		light_len;
	t_ray		light_ray;

	*light_dir = vminus(light->origin, scene->rec.p);
	if (vdot(*light_dir, scene->rec.normal) < 0.0)
		scene->rec.normal = vmult(scene->rec.normal, -1.0);
	light_len = vlength(*light_dir);
	light_ray = ray(vplus(scene->rec.p, \
	vmult(scene->rec.normal, EPSILON)), *light_dir);
	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(scene->object, &light_ray, &rec))
		return (TRUE);
	*light_dir = (vunit(*light_dir));
	return (FALSE);
}

t_color3	get_specular(t_scene *scene, t_light *light, t_vec3 light_dir)
{
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		spec;
	t_color3	specular;

	view_dir = vunit(vmult(scene->ray.dir, -1));
	reflect_dir = reflect(vmult(light_dir, -1), scene->rec.normal);
	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), 64);
	specular = vmult(vmult(light->light_color, 0.5), spec);
	return (specular);
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_color3	diffuse;
	t_vec3		light_dir;
	double		kd;
	t_color3	specular;

	if (in_shadow(scene, light, &light_dir))
		return (vec3(0, 0, 0));
	kd = fmax(vdot(scene->rec.normal, light_dir), 0.0);
	diffuse = vmult(light->light_color, kd);
	specular = get_specular(scene, light, light_dir);
	return (vmult(vplus(diffuse, specular), light->bright_ratio * LUMEN));
}

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = vplus(light_color, \
			point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = vplus(light_color, scene->ambient);
	return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}
