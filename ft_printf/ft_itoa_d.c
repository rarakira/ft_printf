/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:53:01 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/25 12:56:55 by lbaela           ###   ########.fr       */
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
