/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_planet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:04:09 by hyuim             #+#    #+#             */
/*   Updated: 2024/01/04 13:23:10 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

t_vec3	get_absolute_center(t_planet *planet)
{
	t_planet	*mother;
	t_point3	center;

	mother = planet->mother;
	center = planet->pos;
	while (mother)
	{
		center = vplus(center, mother->pos);
		mother = mother->mother;
	}
	return (center);
}

t_bool	hit_planet(t_object *pn_obj, t_ray *ray, t_hit_rec *rec)
{
	t_planet	*pn;
	t_sphere	sp;

	pn = pn_obj->element;
	sp.center = get_absolute_center(pn);
	sp.radius = pn->radius;
	sp.radius2 = pn->radius2;
	if (!get_root_sp(rec, ray, &sp))
		return (FALSE);
	rec->normal = get_bump(&sp, &pn_obj->bump, rec);
	set_face_normal(ray, rec);
	rec->albedo = get_albedo(&sp, &pn_obj->texture, rec, pn_obj->albedo);
	return (TRUE);
}
