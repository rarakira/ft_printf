/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:53:01 by lbaela            #+#    #+#             */
/*   Updated: 2021/06/01 21:14:58 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	translate_nums(char *num, long long int n, unsigned int len)
{
	if (n == 0)
		num[--len] = '0';
	while (n)
	{
		num[--len] = (n % 10) + '0';
		n = (n - (n % 10)) / 10;
	}
}

/* Function converts integers to strings (memory allocated). */
char	*ft_itoa_d(long int n, char	*sign)
{
	char			*num;
	unsigned int	len;
	long int		mod;
	long long int	nn;

	mod = 10;
	len = 1;
	nn = n;
	if (nn < 0)
	{
		*sign = '-';
		nn *= -1;
	}
	while (nn % mod != nn)
	{
		mod *= 10;
		len++;
	}
	num = ft_calloc(len + 1, sizeof(char));
	if (num)
		translate_nums(num, nn, len);
	return (num);
}

char	convert_to_hex(int n)
{
	if (n < 10)
		return (n + '0');
	if (n == 10)
		return ('a');
	if (n == 11)
		return ('b');
	if (n == 12)
		return ('c');
	if (n == 13)
		return ('d');
	if (n == 14)
		return ('e');
	if (n == 15)
		return ('f');
	return (0);
}
static void	translate_hex(char *num, long long int n, unsigned int len)
{
	int		rem;
	int		res;

	rem = n;
	res = 0;
	if (n == 0)
		num[--len] = '0';
	while (rem)
	{
		res = (rem / 16);
		rem = rem - (res * 16);
		num[--len] = convert_to_hex(res);
	}
}

char	*ft_itoa_x(long int n, char	*sign)
{
	char			*num;
	unsigned int	len;
	long int		res;
	long long int	rem;

	rem = n;
	res = 0;
	len = 1;
	if (rem < 0)
	{
		*sign = '-';
		rem *= -1;
	}
	while (rem != 0)
	{
		res = (rem / 16);
		rem = rem - (res * 16);
		len++;
	}
	num = ft_calloc(len + 1, sizeof(char));
	if (*sign == '-')
		rem = n * -1;
	else
		rem = n;
	if (num)
		translate_hex(num, n, len);
	return (num);
}
