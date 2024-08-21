/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuim <hyuim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:58:41 by yusekim           #+#    #+#             */
/*   Updated: 2024/01/03 13:58:38 by hyuim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map_parse.h"

int	check_valid_double(const char *str)
{
	int	point;
	int	idx;

	idx = 0;
	point = 0;
	while (*(str + idx) && *(str + idx) != '\n')
	{
		if (*(str + idx) == '.')
			point++;
		else if (*(str + idx) == '-')
			;
		else if (*(str + idx) < '0' || *(str + idx) > '9')
			return (-1);
		idx++;
	}
	if (point > 1 || (*str == '.' && *(str + 1) == 0))
		return (-1);
	return (1);
}

double	get_db(const char *str, int idx)
{
	int		point_flag;
	double	integer;
	double	rational;

	point_flag = 0;
	integer = 0;
	rational = 0;
	while (*(str + idx) && *(str + idx) != '\n')
	{
		if (*(str + idx) == '.')
			point_flag = 1;
		else if (*(str + idx) == '-' || *(str + idx) == '+')
			ft_perror("Wrong input err", 28);
		else if (point_flag == 0)
			integer = integer * 10 + (*(str + idx) - '0');
		else
			rational = rational * 0.1 + ((*(str + idx) - '0') * 0.1);
		idx++;
	}
	return (integer + rational);
}

double	atodb(char *str)
{
	int		sign;
	int		idx;
	double	ret;

	if (check_valid_double(str) == -1)
		ft_perror("Wrong input err", 29);
	idx = 0;
	sign = 1;
	if (*(str) == '-' || *(str) == '+')
	{
		if (*(str) == '-')
			sign = -1;
		idx++;
	}
	ret = get_db(str, idx);
	ret *= sign;
	return (ret);
}

int	get_split_cnt(char **split)
{
	int	line_cnt;

	line_cnt = -1;
	while (split[++line_cnt])
		;
	return (line_cnt);
}

void	split_free(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
