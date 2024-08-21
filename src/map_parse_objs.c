/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_objs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:48:53 by yusekim           #+#    #+#             */
/*   Updated: 2024/01/03 13:58:40 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "scene.h"
#include "map_parse.h"

double	get_uvalue(char *line)
{
	double	diameter;

	diameter = atodb(line);
	if (diameter <= 0)
		ft_perror("Wrong input err", 14);
	return (diameter);
}

void	parse_sphere(char **line, t_param *par)
{
	double		radius;
	t_point3	point;
	t_color3	color;
	int			split_cnt;
	t_object	*sp_obj;

	split_cnt = get_split_cnt(line);
	if (split_cnt != 4 && split_cnt != 6)
		ft_perror("Wrong input err", 15);
	point = get_tuple(line[1]);
	radius = get_uvalue(line[2]) / 2;
	color = get_color(line[3]);
	sp_obj = object(SP, sphere(point, radius), color);
	if (split_cnt == 6)
	{
		get_maps(par, &sp_obj->texture, line[4]);
		get_maps(par, &sp_obj->bump, line[5]);
	}
	oadd(&par->scene.object, sp_obj);
}

void	parse_disk(char **line, t_param *par)
{
	double		radius;
	t_point3	point;
	t_color3	color;
	t_vec3		normal;

	if (get_split_cnt(line) != 5)
		ft_perror("Wrong input err", 16);
	point = get_tuple(line[1]);
	normal = get_normal(line[2]);
	radius = get_uvalue(line[3]) / 2;
	color = get_color(line[4]);
	oadd(&par->scene.object, object(DK, disk(point, normal, radius), color));
}

void	parse_cylinder(char **line, t_param *par)
{
	double		radius;
	double		height;
	t_point3	point;
	t_color3	color;
	t_vec3		normal;

	if (get_split_cnt(line) != 6)
		ft_perror("Wrong input err", 17);
	point = get_tuple(line[1]);
	normal = get_normal(line[2]);
	radius = get_uvalue(line[3]) / 2;
	height = get_uvalue(line[4]);
	color = get_color(line[5]);
	oadd(&par->scene.object, object(CY, \
	cylinder(point, normal, height, radius), color));
	point = vplus(point, vmult(normal, height / 2));
	oadd(&par->scene.object, object(DK, disk(point, normal, radius), color));
	point = vplus(point, vmult(normal, -height));
	oadd(&par->scene.object, object(DK, disk(point, normal, radius), color));
}

void	parse_plane(char **line, t_param *par)
{
	t_point3	point;
	t_color3	color;
	t_vec3		normal;

	if (get_split_cnt(line) != 4)
		ft_perror("Wrong input err", 18);
	point = get_tuple(line[1]);
	normal = get_normal(line[2]);
	color = get_color(line[3]);
	oadd(&par->scene.object, object(PL, plane(point, normal), color));
}
