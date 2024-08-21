/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:03:09 by dongseo           #+#    #+#             */
/*   Updated: 2023/08/22 13:33:19 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*temp;
	size_t	i;

	if (n == 0 || !s1)
		return (NULL);
	temp = (char *)malloc(n + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}
