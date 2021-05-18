/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:51:22 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/18 18:32:26 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_f_specifiers(const char *str)
{
	int	res;

	res = 0;
	while (*str != '\0')
	{
		if (*str == '%' && *(str + 1) == '%')
			str++;
		else if (*str == '%')
			res++;
		str++;
	}
	return (res);
}

/* Function that mimics the real printf */
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		n_args;
	int		count;

	count = 0;
	n_args = count_f_specifiers(str);
	va_start(ap, str);
	print_control_string(n_args, (char *)str, ap, &count);
	va_end(ap);
	return (count);
}
