/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:59:37 by dongseo           #+#    #+#             */
/*   Updated: 2023/08/07 13:47:57 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int *sign, long long n, size_t *len)
{
	if (n < 0)
	{
		*sign *= -1;
		n *= -1;
		*len = *len + 1;
	}
	while (n > 9)
	{
		*len = *len + 1;
		n /= 10;
	}
	return (*len);
}

char	*ft_itoa(int n)
{
	size_t		len;
	char		*result;
	int			sign;
	long long	num;

	sign = 1;
	len = 1;
	num = n;
	len = count_len(&sign, num, &len);
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	result[0] = '0';
	if (sign == -1)
	{
		result[0] = '-';
		num *= -1;
	}
	result[len--] = 0;
	while (num > 0)
	{
		result[len--] = num % 10 + '0';
		num /= 10;
	}
	return (result);
}
