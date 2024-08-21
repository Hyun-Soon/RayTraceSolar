/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:17:38 by yusekim           #+#    #+#             */
/*   Updated: 2024/01/02 17:56:26 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

double	sp_discriminant(t_ray *ray, t_sphere *sp, double *a, double *half_b)
{
	t_vec3		oc;
	double		c;

	oc = vminus(ray->orig, sp->center);
	*a = vlength2(ray->dir);
	*half_b = vdot(oc, ray->dir);
	c = vlength2(oc) - sp->radius2;
	return ((*half_b) * (*half_b) - *a * c);
}

t_bool	get_root_sp(t_hit_rec *rec, t_ray *ray, t_sphere *sp)
{
	double	root;
	double	a;
	double	half_b;
	double	discriminant;
	double	sqrtd;

	discriminant = sp_discriminant(ray, sp, &a, &half_b);
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || root > rec->tmax)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	return (TRUE);
}

t_bool	hit_sp(t_object *sp_obj, t_ray *ray, t_hit_rec *rec)
{
	t_sphere	*sp;

	sp = sp_obj->element;
	if (!get_root_sp(rec, ray, sp))
		return (FALSE);
	rec->normal = get_bump(sp, &sp_obj->bump, rec);
	set_face_normal(ray, rec);
	rec->albedo = get_albedo(sp, &sp_obj->texture, rec, sp_obj->albedo);
	return (TRUE);
}
