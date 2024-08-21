/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:28:59 by dongseo           #+#    #+#             */
/*   Updated: 2023/08/03 13:32:16 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_init(char *s_cpy, char c, size_t len, size_t *word_cnt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		if (s_cpy[i] == c)
			s_cpy[i] = 0;
		i++;
	}
	*word_cnt = 0;
	if (s_cpy[0] != 0)
		*word_cnt = *word_cnt + 1;
	j = 1;
	while (j < len)
	{
		if (s_cpy[j - 1] == 0 && s_cpy[j] != 0)
			*word_cnt = *word_cnt + 1;
		j++;
	}
	return (s_cpy);
}

static void	set_index(size_t index[])
{
	index[0] = 1;
	index[1] = 0;
	index[2] = 0;
}

static int	make_result(char **result, char *s_cpy, size_t len)
{
	size_t	index[3];

	set_index(index);
	if (s_cpy[0] != 0)
	{
		result[index[1]++] = ft_strdup(s_cpy);
		if (!result[index[1] - 1])
			return (1);
	}
	while (index[0]++ < len)
	{
		if (s_cpy[index[0] - 2] == 0 && s_cpy[index[0] - 1] != 0)
		{
			result[index[1]++] = ft_strdup(s_cpy + index[0] - 1);
			if (!result[index[1] - 1])
			{
				while (index[2] < index[1] - 1)
					free(result[index[2]++]);
				return (1);
			}
		}
	}
	result[index[1]] = NULL;
	return (0);
}

static int	check(char **result, char *s_cpy, size_t len)
{
	if (!result)
	{
		free(s_cpy);
		return (1);
	}
	if (make_result(result, s_cpy, len))
	{
		free(result);
		free(s_cpy);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	*s_cpy;
	size_t	word_cnt;
	char	**result;

	if (!ft_strlen(s))
	{
		result = (char **)malloc(sizeof(char *));
		if (!result)
			return (0);
		result[0] = NULL;
		return (result);
	}
	s_cpy = ft_strdup(s);
	if (!s_cpy)
		return (NULL);
	len = ft_strlen(s_cpy);
	s_cpy = ft_init(s_cpy, c, len, &word_cnt);
	result = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (check(result, s_cpy, len))
		return (0);
	free(s_cpy);
	return (result);
}
