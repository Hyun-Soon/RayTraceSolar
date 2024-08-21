/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_bonus_objs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:48:53 by yusekim           #+#    #+#             */
/*   Updated: 2024/01/04 16:55:46 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "scene.h"
#include "map_parse.h"

void	get_maps(t_param *par, t_img *img, char *filepath)
{
	char	*temp;

	temp = ft_strchr(filepath, '\n');
	if (temp)
		*temp = '\0';
	if (ft_strcmp(filepath, "none") != 0)
	{
		img->img = mlx_xpm_file_to_image(par->mlx, \
		filepath, &img->width, &img->height);
		if (!img->img)
			ft_perror("Img create err", 123);
		img->addr = mlx_get_data_addr(img->img, \
		&img->bits_per_pixel, &img->line_length, &img->endian);
		if (!img->addr)
			ft_perror("Img create err", 9);
	}
}

void	parse_light_bulb(char **line, t_param *par)
{
	double		radius;
	t_point3	point;
	t_color3	color;
	int			split_cnt;
	t_object	*sp_obj;

	split_cnt = get_split_cnt(line);
	if (split_cnt != 5 && split_cnt != 7)
		ft_perror("Wrong input err", 10);
	point = get_tuple(line[1]);
	radius = get_uvalue(line[2]) / 2;
	color = get_color(line[4]);
	sp_obj = object(LB, sphere(point, radius), color);
	if (split_cnt == 6)
	{
		get_maps(par, &sp_obj->texture, line[5]);
		get_maps(par, &sp_obj->bump, line[6]);
	}
	oadd(&par->scene.world, sp_obj);
	oadd(&par->scene.light, object(LIGHT_POINT, \
	light_point(point, get_uvalue(line[3]), color), color3(0, 0, 0)));
}

void	parse_cb(char **line, t_param *par)
{
	t_point3	point;
	t_vec3		normal;
	t_vec3		direction;
	t_color3	color;

	if (get_split_cnt(line) != 5)
		ft_perror("Wrong input err", 11);
	point = get_tuple(line[1]);
	normal = get_normal(line[2]);
	direction = get_tuple(line[3]);
	if (vdot(direction, normal) != 0)
		ft_perror("Wrong input err", 12);
	color = get_color(line[4]);
	oadd(&par->scene.object, object(CB, \
	checkerboard(point, normal, direction), color));
}

void	parse_cone(char **line, t_param *par)
{
	double		radius;
	double		height;
	t_point3	point;
	t_color3	color;
	t_vec3		normal;

	if (get_split_cnt(line) != 6)
		ft_perror("Wrong input err", 13);
	point = get_tuple(line[1]);
	normal = get_normal(line[2]);
	radius = get_uvalue(line[3]);
	height = get_uvalue(line[4]);
	color = get_color(line[5]);
	oadd(&par->scene.object, object(CN, \
	cone(point, normal, radius, height), color));
	oadd(&par->scene.object, object(DK, \
	disk(vplus(point, vmult(normal, height)), normal, radius), color));
}
