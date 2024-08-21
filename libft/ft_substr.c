/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:11:59 by dongseo           #+#    #+#             */
/*   Updated: 2023/03/27 17:24:23 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*temp;
	unsigned int	i;

	i = 0;
	if (ft_strlen(s) <= start)
	{
		temp = (char *)malloc(1);
		if (!temp)
			return (NULL);
		temp[0] = 0;
		return (temp);
	}
	if (ft_strlen(s) - start < len)
		temp = (char *)malloc(ft_strlen(s) - start + 1);
	else
		temp = (char *)malloc(len + 1);
	if (!temp)
		return (0);
	while (s[start + i] && i < len)
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}
