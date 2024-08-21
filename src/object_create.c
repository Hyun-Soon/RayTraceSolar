/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:50:23 by yusekim           #+#    #+#             */
/*   Updated: 2024/01/04 13:22:57 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "scene.h"

t_object	*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	new->texture.img = NULL;
	new->bump.img = NULL;
	new->texture.addr = NULL;
	new->bump.addr = NULL;
	return (new);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp)
		return (NULL);
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

t_plane	*plane(t_point3 point, t_vec3 normal)
{
	t_plane	*pl;

	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!pl)
		return (NULL);
	pl->point = point;
	pl->normal = vunit(normal);
	return (pl);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 normal, double h, double r)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cy)
		return (NULL);
	cy->center = center;
	cy->normal = normal;
	cy->height = h;
	cy->radius = r;
	cy->radius2 = r * r;
	return (cy);
}

t_disk	*disk(t_point3 center, t_vec3 normal, double radius)
{
	t_disk	*disk;

	disk = (t_disk *)malloc(sizeof(t_disk));
	if (!disk)
		return (NULL);
	disk->center = center;
	disk->normal = vunit(normal);
	disk->radius = radius;
	return (disk);
}
