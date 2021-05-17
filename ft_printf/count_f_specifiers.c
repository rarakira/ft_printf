/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_f_specifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:42:35 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/17 14:43:05 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_f_specifiers(const char *str)
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
