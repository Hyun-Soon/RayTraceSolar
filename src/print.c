/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusekim <yusekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:25:55 by yusekim           #+#    #+#             */
/*   Updated: 2024/01/02 09:39:31 by yusekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	convert_color3_int(t_color3 pixel_color)
{
	int		color;

	color = 256 * 256 * (int)(255.999 * pixel_color.x) + \
	256 * (int)(255.999 * pixel_color.y) + (int)(255.999 * pixel_color.z);
	return (color);
}

void	snapshot(t_param *par, t_img *tar_img)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color3	pixel_color;

	j = -1;
	while (++j < tar_img->height)
	{
		i = -1;
		while (++i < tar_img->width)
		{
			u = (double)i / (tar_img->width - 1);
			v = (double)j / (tar_img->height - 1);
			par->scene.ray = ray_primary(&par->scene.camera, u, v);
			pixel_color = ray_color(par);
			my_mlx_pixel_put(tar_img, i, j, convert_color3_int(pixel_color));
		}
	}
	mlx_put_image_to_window(par->mlx, par->win, par->img.img, 0, 0);
}
