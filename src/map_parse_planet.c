/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_planet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:59:17 by hyuim             #+#    #+#             */
/*   Updated: 2024/01/04 16:43:19 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hook.h"
#include "map_parse.h"

void	parse_star(char **line, t_param *par)
{
	t_planet	info;
	t_color3	color;
	t_scene		*scene;
	t_object	*star;

	scene = &par->scene;
	if (get_split_cnt(line) != 5 && get_split_cnt(line) != 7)
		ft_perror("Wrong input err", 16);
	info.name = ft_strdup(line[1]);
	info.mother = NULL;
	info.axis = get_normal(line[2]);
	info.radius = get_uvalue(line[3]);
	info.period = 0;
	info.orbit_radius = 0;
	info.pos = point3(0, 30000, 0);
	color = get_color(line[4]);
	star = object(STAR, planet(info), color);
	if (get_split_cnt(line) == 7)
	{
		get_maps(par, &star->texture, line[5]);
		get_maps(par, &star->bump, line[6]);
	}
	oadd(&scene->world, star);
	oadd(&scene->light, object(LIGHT_POINT, \
	light_point(info.pos, 0.5, color3(1, 1, 1)), color3(0, 0, 0)));
}

void	set_mother(t_planet *info, t_scene *scene, char *mother_name)
{
	info->mother = find_mother(scene->world, mother_name);
	if (!info->mother)
		info->mother = find_mother(scene->object, mother_name);
}

void	parse_planet(char **line, t_param *par)
{
	t_planet	info;
	t_color3	color;
	t_object	*pn_obj;

	if (get_split_cnt(line) != 8 && get_split_cnt(line) != 10)
		ft_perror("Wrong input err", 8);
	info.name = ft_strdup(line[1]);
	set_mother(&info, &par->scene, line[2]);
	info.axis = get_normal(line[3]);
	info.radius = get_uvalue(line[4]);
	info.radius2 = info.radius * info.radius;
	info.orbit_radius = get_uvalue(line[5]);
	info.period = get_uvalue(line[6]);
	if (info.period == 0)
		exit(33);
	info.pos = point3(info.orbit_radius, 0, 0);
	color = get_color(line[7]);
	pn_obj = object(PLANET, planet(info), color);
	if (get_split_cnt(line) == 10)
	{
		get_maps(par, &pn_obj->texture, line[8]);
		get_maps(par, &pn_obj->bump, line[9]);
	}
	oadd(&par->scene.object, pn_obj);
}
