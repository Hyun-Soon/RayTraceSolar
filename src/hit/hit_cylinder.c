/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:16:24 by yusekim           #+#    #+#             */
/*   Updated: 2024/01/02 16:52:42 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

t_vec3	get_cy_rec_normal(t_cylinder *cy, t_hit_rec *rec, double h)
{
	return (vdivide(vminus(rec->p, \
	vplus(cy->center, vmult(cy->normal, h))), cy->radius));
}

double	cy_discriminant(t_ray *ray, t_cylinder *cy, double *a, double *h_b)
{
	t_vec3	sub_a;
	t_vec3	sub_b;
	double	c;

	sub_a = vminus(ray->dir, vmult(cy->normal, vdot(ray->dir, cy->normal)));
	sub_b = vplus(vminus(vminus(ray->orig, cy->center), \
	vmult(cy->normal, vdot(ray->orig, cy->normal))), \
	vmult(cy->normal, vdot(cy->center, cy->normal)));
	*a = vdot(sub_a, sub_a);
	*h_b = vdot(sub_a, sub_b);
	c = vdot(sub_b, sub_b) - cy->radius2;
	return ((*h_b) * (*h_b) - *a * c);
}

t_bool	hit_cy(t_cylinder *cy, t_ray *ray, t_hit_rec *rec, t_color3 albedo)
{
	double		h;
	double		a;
	double		half_b;
	double		discriminant;
	double		root;

	discriminant = cy_discriminant(ray, cy, &a, &half_b);
	if (discriminant < 0)
		return (FALSE);
	root = (-half_b - sqrt(discriminant)) / a;
	rec->p = ray_at(ray, root);
	h = vdot(vminus(rec->p, cy->center), cy->normal);
	if (root < rec->tmin || rec->tmax < root || (cy->height / 2 < fabs(h)))
	{
		root = (-half_b + sqrt(discriminant)) / a;
		rec->p = ray_at(ray, root);
		h = vdot(vminus(rec->p, cy->center), cy->normal);
		if (root < rec->tmin || rec->tmax < root || (cy->height / 2 < fabs(h)))
			return (FALSE);
	}
	rec->t = root;
	rec->normal = get_cy_rec_normal(cy, rec, h);
	rec->albedo = albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool	hit_disk(t_object *dk_obj, t_ray *ray, t_hit_rec *rec)
{
	double	t;
	t_disk	*dk;

	dk = dk_obj->element;
	t = vdot(vminus(dk->center, ray->orig), dk->normal) / \
	vdot(dk->normal, ray->dir);
	if (t < rec->tmin || rec->tmax < t)
		return (FALSE);
	if (vlength(vminus(ray_at(ray, t), dk->center)) > dk->radius)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(ray, t);
	rec->normal = dk->normal;
	set_face_normal(ray, rec);
	rec->albedo = dk_obj->albedo;
	return (TRUE);
}
