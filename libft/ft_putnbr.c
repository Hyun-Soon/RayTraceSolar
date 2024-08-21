/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongseo <dongseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:26:21 by dongseo           #+#    #+#             */
/*   Updated: 2023/07/22 10:33:52 by dongseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_di(int n, ssize_t *len)
{
	long long	num;
	int			sign;
	char		c;

	if (*len == -1)
		return ;
	num = n;
	sign = 1;
	if (num < 0)
	{
		sign *= -1;
		num *= -1;
	}
	if (sign == -1)
	{
		*len += 1;
		if (write(1, "-", 1) < 0)
			*len = -1;
	}
	if (num > 9)
		ft_putnbr_di(num / 10, len);
	c = num % 10 + '0';
	*len += 1;
	if (write(1, &c, 1) < 0)
		*len = -1;
}

void	ft_putnbr_u(unsigned int u, ssize_t *len)
{
	unsigned int	num;
	char			c;

	if (*len == -1)
		return ;
	num = u;
	if (num > 9)
		ft_putnbr_u(num / 10, len);
	c = num % 10 + '0';
	*len += 1;
	if (write(1, &c, 1) < 0)
		*len = -1;
}

void	ft_putnbr_x(unsigned int x, ssize_t *len, int is_upper)
{
	char	c;
	char	*hex;

	if (*len == -1)
		return ;
	if (is_upper == 1)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (x > 15)
		ft_putnbr_x(x / 16, len, is_upper);
	c = x % 16;
	*len += 1;
	if (write(1, &hex[(int)c], 1) < 0)
		*len = -1;
}

unsigned long long	set_base(int base[], unsigned long long p)
{
	unsigned long long	len;
	unsigned long long	i;

	len = 15;
	i = 15;
	while (len + 1 && p > 0)
	{
		base[len] = p % 16;
		p /= 16;
		len--;
		i--;
	}
	return (i + 1);
}

ssize_t	ft_printf_p(unsigned long long p)
{
	unsigned long long	i;
	int					base[16];
	size_t				result;

	if (p == 0)
	{
		if (write(1, "0x0", 3) < 0)
			return (-1);
		return (3);
	}
	i = set_base(base, p);
	if (write(1, "0x", 2) < 0)
		return (-1);
	result = 2;
	while (i < 16)
	{
		if (write(1, &"0123456789abcdef"[base[i] % 16], 1) < 0)
			return (-1);
		result++;
		i++;
	}
	return (result);
}
