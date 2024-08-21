/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:52:37 by hyuim             #+#    #+#             */
/*   Updated: 2024/01/02 17:48:09 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

void	set_ab(double *a, double *h_b, t_cone *cn, t_ray *ray)
{
	double	sub_a;
	double	sub_b;
	double	r2;
	t_vec3	oc;

	r2 = cn->radius * cn->radius;
	oc = vminus(ray->orig, cn->center);
	sub_a = cn->height * cn->height * vlength2(vcross(cn->normal, ray->dir));
	*a = sub_a - (r2 * pow(vdot(cn->normal, ray->dir), 2));
	sub_b = (cn->height * cn->height * vdot(vcross(cn->normal, ray->dir), \
	vcross(cn->normal, oc)));
	*h_b = sub_b - (r2 * vdot(cn->normal, ray->dir) * vdot(oc, cn->normal));
}

double	cn_discriminant(t_ray *ray, t_cone *cn, double *a, double *h_b)
{
	t_vec3	oc;
	double	c;
	double	r2;

	r2 = cn->radius * cn->radius;
	oc = vminus(ray->orig, cn->center);
	set_ab(a, h_b, cn, ray);
	c = (cn->height * cn->height * vlength2(vcross(cn->normal, oc))) - \
	(r2 * pow(vdot(oc, cn->normal), 2));
	return ((*h_b) * (*h_b) - *a * c);
}

t_bool	get_root_cn(t_hit_rec *rec, t_ray *ray, t_cone *cn, double sqrtd)
{
	double	root;
	double	h2;
	double	a;
	double	half_b;

	set_ab(&a, &half_b, cn, ray);
	root = (-half_b - sqrtd) / a;
	h2 = vdot(vminus(ray_at(ray, root), cn->center), cn->normal);
	if (root < rec->tmin || rec->tmax < root || (h2 > cn->height) || h2 < 0)
	{
		root = (-half_b + sqrtd) / a;
		h2 = vdot(vminus(ray_at(ray, root), cn->center), cn->normal);
		if (root < rec->tmin || root > rec->tmax || (h2 > cn->height) || h2 < 0)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	return (TRUE);
}

t_bool	hit_cone(t_object *cn_obj, t_ray *ray, t_hit_rec *rec)
{
	double	a;
	double	half_b;
	double	sqrtd;
	double	discriminant;
	t_cone	*cn;

	cn = cn_obj->element;
	discriminant = cn_discriminant(ray, cn, &a, &half_b);
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	if (!get_root_cn(rec, ray, cn, sqrtd))
		return (FALSE);
	rec->normal = vunit(vminus(rec->p, vplus(cn->center, \
	vmult(cn->normal, (vdot(vminus(rec->p, cn->center), cn->normal) \
	+ (((cn->radius * cn->radius) * vdot(vminus(rec->p, cn->center), \
	cn->normal)) / (cn->height * cn->height)))))));
	set_face_normal(ray, rec);
	rec->albedo = cn_obj->albedo;
	return (TRUE);
}
