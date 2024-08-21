/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planet_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:45:24 by hyuim             #+#    #+#             */
/*   Updated: 2024/01/04 17:14:42 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hook.h"

t_planet	*find_mother(t_object *universe, char *name)
{
	t_object	*obj;
	t_planet	*planet;

	obj = universe;
	while (obj)
	{
		planet = (t_planet *)obj->element;
		if (ft_strcmp(planet->name, name) == 0)
			return (planet);
		obj = obj->next;
	}
	return (NULL);
}

t_planet	*find_planet(t_object *obj_list, char *name)
{
	t_object	*temp;

	temp = obj_list;
	while (temp)
	{
		if ((temp->type == STAR || temp->type == PLANET) \
			&& ft_strcmp(((t_planet *)temp->element)->name, name) == 0)
			return ((t_planet *)temp->element);
		temp = temp->next;
	}
	return (NULL);
}

void	update_planet(t_param *par, int direction)
{
	t_object	*current;
	t_planet	*planet;
	t_point3	position;

	current = par->scene.object;
	while (current)
	{
		planet = (t_planet *)current->element;
		position = planet->pos;
		if (current->type == PLANET)
			planet->pos = rotate_y(position, direction * \
			par->scene.dt * 2 * M_PI / planet->period);
		current = current->next;
	}
}

void	time_shift(int keycode, t_param *par)
{
	int	direction;

	direction = 1;
	if (keycode == KEY_OPEN)
	{
		par->scene.time -= par->scene.dt;
		direction = -1;
	}
	else if (keycode == KEY_CLOSE)
		par->scene.time += par->scene.dt;
	update_planet(par, direction);
	snapshot(par, &par->img);
}
