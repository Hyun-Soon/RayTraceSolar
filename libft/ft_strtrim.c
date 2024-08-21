/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:43:29 by dongseo           #+#    #+#             */
/*   Updated: 2023/08/07 16:52:24 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_start(char *s1, char const *set, size_t *len)
{
	size_t	i;
	size_t	j;
	size_t	ft_len;

	ft_len = ft_strlen(s1);
	i = 0;
	while (i < ft_len)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				*len = *len - 1;
				break ;
			}
			j++;
		}
		if (set[j] == 0)
			break ;
		i++;
	}
	return (i);
}

static size_t	find_end(char *s1, char const *set, size_t *len)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				*len = *len - 1;
				break ;
			}
			j++;
		}
		if (set[j] == 0)
			break ;
		i--;
	}
	return (i);
}

static char	*insert_result(char *result, size_t start,
							size_t end, char *s1)
{
	size_t	i;

	i = 0;
	while (start <= end)
	{
		result[i] = s1[start];
		start++;
		i++;
	}
	result[i] = 0;
	free(s1);
	return (result);
}

char	*ft_strtrim(char *s1, char const *set)
{
	char	*result;
	size_t	len;
	size_t	start;
	size_t	end;

	len = ft_strlen(s1);
	start = find_start(s1, set, &len);
	if (start == ft_strlen(s1))
	{
		result = (char *)malloc(1);
		if (!result)
			return (0);
		result[0] = 0;
		return (result);
	}
	end = find_end(s1, set, &len);
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	return (insert_result(result, start, end, s1));
}
