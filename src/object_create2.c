/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:36:23 by hyuim             #+#    #+#             */
/*   Updated: 2024/01/03 18:49:28 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "scene.h"

t_cb	*checkerboard(t_point3 point, t_vec3 normal, t_vec3 dir)
{
	t_cb	*cb;

	cb = (t_cb *)malloc(sizeof(t_cb));
	if (!cb)
		return (NULL);
	cb->point = point;
	cb->normal = vunit(normal);
	cb->dir = vunit(dir);
	return (cb);
}

t_cone	*cone(t_point3 center, t_vec3 normal, double radius, double h)
{
	t_cone	*cone;

	cone = (t_cone *)malloc(sizeof(t_cone));
	if (!cone)
		return (NULL);
	cone->center = center;
	cone->normal = vunit(normal);
	cone->radius = radius;
	cone->height = h;
	return (cone);
}

t_planet	*planet(t_planet info)
{
	t_planet	*planet;

	planet = (t_planet *)malloc(sizeof(t_planet));
	if (!planet)
		return (NULL);
	planet->name = info.name;
	planet->mother = info.mother;
	planet->pos = info.pos;
	planet->radius = info.radius;
	planet->radius2 = info.radius * info.radius;
	planet->orbit_radius = info.orbit_radius;
	planet->period = info.period;
	planet->axis = info.axis;
	planet->light_color = color3(1, 1, 1);
	planet->bright_ratio = 1;
	return (planet);
}
