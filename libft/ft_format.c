/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:23:13 by dongseo           #+#    #+#             */
/*   Updated: 2023/07/22 10:33:47 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_printf_c(char c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

ssize_t	ft_printf_s(char *s)
{
	ssize_t	len;

	if (s == NULL)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	len = ft_strlen(s);
	if (write(1, s, len) < 0)
		return (-1);
	return (len);
}

ssize_t	ft_printf_di(int d)
{
	ssize_t	len;

	len = 0;
	ft_putnbr_di(d, &len);
	return (len);
}

ssize_t	ft_printf_u(unsigned int u)
{
	ssize_t	len;

	len = 0;
	ft_putnbr_u(u, &len);
	return (len);
}

ssize_t	ft_printf_x(int x, int is_upper)
{
	ssize_t	len;

	len = 0;
	ft_putnbr_x(x, &len, is_upper);
	return (len);
}
