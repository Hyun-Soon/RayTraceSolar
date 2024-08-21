/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:01:57 by dongseo           #+#    #+#             */
/*   Updated: 2023/08/23 11:27:48 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

ssize_t	st_len(const char *st)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (st[i])
	{
		if (st[i] == '%')
		{
			i += 2;
			continue ;
		}
		len++;
		i++;
	}
	return (len);
}

ssize_t	check_format(char format, va_list *ap)
{
	if (format == 'c')
		return (ft_printf_c(va_arg(*ap, int)));
	else if (format == 's')
		return (ft_printf_s(va_arg(*ap, char *)));
	else if (format == 'p')
		return (ft_printf_p(va_arg(*ap, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_printf_di(va_arg(*ap, int)));
	else if (format == 'u')
		return (ft_printf_u(va_arg(*ap, unsigned int)));
	else if (format == 'x')
		return (ft_printf_x(va_arg(*ap, int), 0));
	else if (format == 'X')
		return (ft_printf_x(va_arg(*ap, int), 1));
	else
	{
		if (write(1, &format, 1) < 0)
			return (-1);
		return (1);
	}
}

int	ft_printf(const char *st, ...)
{
	va_list	ap;
	size_t	i;
	ssize_t	len;
	ssize_t	check;

	len = st_len(st);
	i = 0;
	va_start(ap, st);
	check = 0;
	while (st[i])
	{
		if (check == -1)
			return (-1);
		if (st[i] != '%')
			check = write(1, &st[i], 1);
		else
		{
			check = check_format(st[i + 1], &ap);
			len += check;
			i += 2;
			continue ;
		}
		i++;
	}
	return (len);
}
