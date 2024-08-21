/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:57:44 by yusekim           #+#    #+#             */
/*   Updated: 2024/01/03 13:54:16 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

void		camera(t_camera *cam, double aspect_ratio);
t_sphere	*sphere(t_point3 center, double radius);
t_object	*object(t_object_type type, void *element, t_color3 albedo);
t_light		*light_point(t_point3 l_origin, double b_ratio, t_color3 l_color);
t_plane		*plane(t_point3 point, t_vec3 normal);
t_cylinder	*cylinder(t_point3 center, t_vec3 n, double h, double r);
t_cone		*cone(t_point3 pos, t_vec3 n, double r, double h);
t_disk		*disk(t_point3 center, t_vec3 normal, double radius);
t_cb		*checkerboard(t_point3 point, t_vec3 normal, t_vec3 dir);
t_planet	*planet(t_planet info);

#endif
