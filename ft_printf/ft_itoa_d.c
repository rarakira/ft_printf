/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:53:01 by lbaela            #+#    #+#             */
/*   Updated: 2021/06/08 11:57:24 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	translate_nums(char *num, long int n, unsigned int len)
{
	if (n < -9223372036854775807)
	{
		ft_memcpy(num, "9223372036854775808", len);
		return ;
	}
	if (n == 0)
		num[--len] = '0';
	while (n)
	{
		num[--len] = (n % 10) + '0';
		n = (n - (n % 10)) / 10;
	}
}

char	*ft_itoa_d(long int n, char	*sign)
{
	char				*num;
	unsigned int		len;
	unsigned long int	mod;
	long int			sn;

	mod = 10;
	len = 1;
	sn = n;
	if (sn < 0)
	{
		*sign = '-';
		sn = -1 * sn;
	}
	while (sn % mod != (unsigned long int) sn)
	{
		mod *= 10;
		len++;
	}
	num = ft_calloc(len + 1, sizeof(char));
	if (num)
		translate_nums(num, sn, len);
	return (num);
}

char	convert_to_hex(int n, char format)
{
	if (n < 10)
		return (n + '0');
	else
	{
		n -= 10;
		if (format == 'X')
			return ('A' + n);
		return ('a' + n);
	}
}

static void	translate_hex(char *num, long long int n, unsigned int len,
char format)
{
	long long int		rem;
	long long int		res;

	rem = n;
	res = n;
	if (n == 0)
		num[--len] = '0';
	while (res)
	{
		if (res >= 16)
		{
			rem = res % 16;
			res = (res / 16);
			num[--len] = convert_to_hex(rem, format);
		}
		else
		{
			num[--len] = convert_to_hex(res, format);
			res = 0;
		}
	}
}

char	*ft_itoa_x(long int n, char	*sign, char format)
{
	char			*num;
	unsigned int	len;
	long long int	res;

	if (n < 0)
	{
		*sign = '-';
		n *= -1;
	}
	res = n;
	len = 1;
	while (res >= 16 && len++)
		res = res / 16;
	res = n;
	if (*sign == '-')
	{
		len = 8;
		res = 4294967295 - n + 1;
	}
	num = ft_calloc(len + 1, sizeof(char));
	if (num)
		translate_hex(num, res, len, format);
	return (num);
}

static void	translate_u_nums(char *num, unsigned long int n, unsigned int len)
{
	if (n == 0)
		num[--len] = '0';
	while (n)
	{
		num[--len] = (n % 10) + '0';
		n = (n - (n % 10)) / 10;
	}
}

char	*ft_itoa_u(unsigned long int n)
{
	char				*num;
	unsigned int		len;
	unsigned long int	mod;

	mod = 10;
	len = 1;
	while (n % mod != n && len < 20)
	{
		mod *= 10;
		len++;
	}
	num = ft_calloc(len + 1, sizeof(char));
	if (num)
		translate_u_nums(num, n, len);
	return (num);
}
