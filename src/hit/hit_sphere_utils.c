/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:43:31 by dongseo           #+#    #+#             */
/*   Updated: 2024/01/02 17:45:42 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

t_color3	convert(int color)
{
	double	r;
	double	g;
	double	b;

	r = ((color / 65536) % 256) / 255.0;
	g = ((color / 256) % 256) / 255.0;
	b = ((color % 256)) / 255.0;
	return (color3(r, g, b));
}

char	*get_dst(t_vec3 cp, t_vec3 cp_xz, t_img *img)
{
	int		coord_x;
	int		coord_y;
	double	x_theta;
	double	y_theta;
	char	*dst;

	x_theta = acos(vdot(cp_xz, vec3(1, 0, 0)));
	if (cp.z > 0)
		x_theta = 2 * M_PI - x_theta;
	y_theta = acos(vdot(cp, vec3(0, 1, 0)));
	x_theta = x_theta * 180 / M_PI;
	y_theta = y_theta * 180 / M_PI;
	coord_x = (int)((double)img->width / 360.0 * x_theta);
	coord_y = (int)((double)img->height / 180.0 * y_theta);
	dst = img->addr + (coord_y * img->line_length + coord_x * \
	(img->bits_per_pixel / 8));
	return (dst);
}

t_color3	get_albedo(t_sphere *sp, t_img *img, t_hit_rec *rec, \
						t_color3 albedo)
{
	t_vec3	cp;
	t_vec3	cp_xz;
	char	*dst;
	int		color;

	if (!img->addr)
		return (albedo);
	cp = vunit(vminus(rec->p, sp->center));
	cp_xz = vunit(vec3(cp.x, 0, cp.z));
	dst = get_dst(cp, cp_xz, img);
	color = *(unsigned int *)dst;
	return (convert(color));
}

void	get_uv(t_vec3 cp, t_vec3 *uv)
{
	t_vec3	y_axis;

	y_axis = vec3(0.0, 1.0, 0.0);
	uv[0] = vunit(vcross(y_axis, cp));
	uv[1] = vunit(vcross(cp, uv[0]));
}

t_vec3	get_bump(t_sphere *sp, t_img *img, t_hit_rec *rec)
{
	t_vec3	uv[2];
	t_vec3	ret;
	t_vec3	cp;
	t_vec3	p_normal;

	if (!img->addr)
		return (vdivide(vminus(rec->p, sp->center), sp->radius));
	p_normal = get_albedo(sp, img, rec, color3(0, 0, 0));
	p_normal = vmult(vminus(p_normal, vec3(0.5, 0.5, 0.5)), 2.0);
	p_normal.y *= -1.0;
	cp = vunit(vminus(rec->p, sp->center));
	if (cp.x == 0 && cp.y == 1 && cp.z == 0)
		return (rotate_x(p_normal, -M_PI / 2.0));
	get_uv(cp, uv);
	ret = vunit(vplus(vplus(vplus(vmult(cp, 3.0), \
	vmult(cp, p_normal.z)), vmult(uv[0], p_normal.x)), \
	vmult(uv[1], p_normal.y)));
	return (ret);
}
