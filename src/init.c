/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:41:21 by dongseo           #+#    #+#             */
/*   Updated: 2024/01/04 16:42:30 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map_parse.h"

void	init_image(t_param *par, t_bool flag)
{
	t_img	*tar_img;

	if (flag == AA)
		tar_img = &par->aa_img;
	else
		tar_img = &par->img;
	tar_img->height = HEIGHT;
	tar_img->width = WIDTH;
	tar_img->img = mlx_new_image(par->mlx, tar_img->width, tar_img->height);
	if (!tar_img->img)
		ft_perror("Img create err", 4);
	tar_img->addr = mlx_get_data_addr(tar_img->img, &tar_img->bits_per_pixel,
			&tar_img->line_length, &tar_img->endian);
	if (!tar_img->addr)
		ft_perror("Img create err", 5);
}

void	init(t_param *par, char *file_name)
{
	char	*extension_ptr;

	extension_ptr = ft_strrchr(file_name, '.');
	if (ft_strcmp(extension_ptr, ".rt"))
		ft_perror("not a valid file extension!\n", 255);
	par->fd = open(file_name, O_RDONLY);
	if (par->fd < 0)
		ft_perror("miniRT open err", 6);
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, WIDTH, HEIGHT, "miniRT");
	par->aa_flag = FALSE;
	init_image(par, NAA);
	init_image(par, AA);
	ft_memset(&par->scene, 0, sizeof(t_scene));
	par->scene.canvas.width = WIDTH;
	par->scene.canvas.height = HEIGHT;
	par->scene.canvas.aspect_ratio = (double)WIDTH / (double)HEIGHT;
	scene_parse(par);
	if (par->scene.world)
		olast(par->scene.world)->next = par->scene.object;
	else
		par->scene.world = par->scene.object;
	par->screen = init_screen();
	par->scene.dt = DAY;
}
