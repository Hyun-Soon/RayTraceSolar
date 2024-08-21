/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:06:59 by dongseo           #+#    #+#             */
/*   Updated: 2023/08/07 13:49:13 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;
	size_t	len;

	if (c >= 256)
		c %= 256;
	len = ft_strlen(s);
	res = NULL;
	i = 0;
	while (i <= len)
	{
		if (s[i] == c)
			res = ((char *)s + i);
		i++;
	}
	return (res);
}
