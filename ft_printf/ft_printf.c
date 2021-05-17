/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:51:22 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/17 14:45:49 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Function that mimics the real printf */
int ft_printf(const char *str, ...)
{
	va_list	ap;
	//va_list cp_ap;
	//char *s = (char *)str;
	int	n_args;
	int num = 0;

	n_args = count_f_specifiers(str);
	
	if (n_args == 0)
	{
		ft_putstr_fd((char *)str, 1);
		return (0);
	}
	va_start(ap, str);
	//va_copy(cp_ap, ap);
	while(n_args-- > 0)
	{
		num = va_arg(ap, int);
		ft_putnbr_fd(num, 1);
		ft_putchar_fd('\n', 1);
	}
	//va_end(cp_ap);
	va_end(ap);
	return (0);
}
