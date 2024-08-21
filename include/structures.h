/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:00:03 by yusekim           #+#    #+#             */
/*   Updated: 2024/01/04 17:38:33 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;
typedef struct s_ray		t_ray;
typedef struct s_ray		t_view;
typedef struct s_camera		t_camera;
typedef struct s_canvas		t_canvas;
typedef struct s_object		t_object;
typedef struct s_sphere		t_sphere;
typedef struct s_light		t_light;
typedef struct s_hit_record	t_hit_rec;
typedef struct s_scene		t_scene;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_disk		t_disk;
typedef struct s_cone		t_cone;
typedef struct s_cb			t_cb;
typedef struct s_param		t_param;
typedef struct s_img		t_img;
typedef int					t_bool;
typedef int					t_object_type;
typedef struct s_planet		t_planet;

# define FALSE 0
# define TRUE 1
# define SP 0
# define PL 1
# define CY 2
# define DK 3
# define CN 4
# define CB 5
# define LB 6
# define STAR 7
# define PLANET 8
# define LIGHT_POINT 1
# define EPSILON 1e-6
# define LUMEN 3
# define WIDTH 600
# define HEIGHT 400
# define NAA 0
# define AA 1
# define DAY 1
# define WEEK 7
# define MONTH 30
# define YEAR 365
# define SPEED 30

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

struct s_camera
{
	t_point3	orig;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horizontal;
	t_vec3		vertical;
	double		focal_len;
	t_point3	l_top;
	t_vec3		normal;
	double		fov;
	t_vec3		forward;
	t_vec3		up;
	t_vec3		right;
};

struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
};

struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	albedo;
};

struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*object;
	t_object		*light;
	t_color3		ambient;
	double			amb_ratio;
	t_ray			ray;
	t_hit_rec		rec;
	double			time;
	double			dt;
	t_view			init_view;
};

struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_object
{
	t_object_type	type;
	void			*element;
	t_color3		albedo;
	t_img			texture;
	t_img			bump;
	void			*next;
};

struct s_param
{
	void		*mlx;
	t_img		img;
	t_img		aa_img;
	t_bool		aa_flag;
	void		*win;
	int			fd;
	t_scene		scene;
	t_color3	**screen;
};

struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
};

struct s_plane
{
	t_point3	point;
	t_vec3		normal;
};

struct s_cylinder
{
	t_point3	center;
	t_vec3		normal;
	double		height;
	double		radius;
	double		radius2;
};

struct s_disk
{
	t_point3	center;
	t_vec3		normal;
	double		radius;
};

struct s_cone
{
	t_point3	center;
	t_vec3		normal;
	double		radius;
	double		height;
};

struct s_cb
{
	t_point3	point;
	t_vec3		normal;
	t_vec3		dir;
};

struct s_planet
{
	char		*name;
	t_planet	*mother;
	t_point3	pos;
	double		radius;
	double		radius2;
	double		orbit_radius;
	double		period;
	t_vec3		axis;
	t_color3	light_color;
	double		bright_ratio;
};

#endif
