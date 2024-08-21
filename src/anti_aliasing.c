/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:23:59 by yusekim           #+#    #+#             */
/*   Updated: 2024/01/03 13:58:45 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "print.h"

int	anti_aliasing(t_param *par)
{
	static int	flag;
	t_img		*tar_img;

	if (flag)
		tar_img = &par->img;
	else
		tar_img = &par->aa_img;
	if (par->aa_flag == TRUE)
		mlx_put_image_to_window(par->mlx, par->win, tar_img->img, 0, 0);
	else
	{
		par->aa_flag = TRUE;
		printf("Anti-Aliasing...\n");
		do_anti_aliasing(par, &par->aa_img);
	}
	flag = flag * -1 + 1;
	printf("flag: %d\n", flag);
	return (0);
}

void	divide_ray(t_param *par, t_img *tar_img, t_color3 **screen)
{
	double		u;
	double		v;
	int			i;
	int			j;

	j = -1;
	while (++j < tar_img->height * 2)
	{
		i = -1;
		while (++i < tar_img->width * 2)
		{
			u = ((double)i / (tar_img->width - 1)) / 2.0;
			v = ((double)j / (tar_img->height - 1)) / 2.0;
			par->scene.ray = ray_primary(&par->scene.camera, u, v);
			screen[j][i] = ray_color(par);
		}
	}
}

t_color3	**init_screen(void)
{
	t_color3	**screen;
	int			i;

	screen = malloc(sizeof(t_color3 *) * 2 * HEIGHT);
	if (!screen)
		ft_perror("screen malloc error", 2);
	i = -1;
	while (++i < 2 * HEIGHT)
	{
		screen[i] = malloc(sizeof(t_color3) * 2 * WIDTH);
		if (!screen[i])
			ft_perror("screen malloc error", 3);
	}
	return (screen);
}

void	do_anti_aliasing(t_param *par, t_img *tar_img)
{
	t_color3	**screen;
	t_color3	pixel_color;
	int			i;
	int			j;

	screen = par->screen;
	divide_ray(par, tar_img, screen);
	j = 0;
	while (j < tar_img->height * 2)
	{
		i = 0;
		while (i < tar_img->width * 2)
		{
			pixel_color = vmult(vplus(vplus(vplus(screen[j][i], \
			screen[j][i + 1]), screen[j + 1][i]), screen[j + 1][i + 1]), 0.25);
			my_mlx_pixel_put(tar_img, i / 2, j / 2, \
			convert_color3_int(pixel_color));
			i += 2;
		}
		j += 2;
	}
	mlx_put_image_to_window(par->mlx, par->win, tar_img->img, 0, 0);
}
