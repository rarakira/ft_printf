/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:48:46 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/25 12:57:24 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_arg_u(t_args *arg, va_list ap)
{
	char	*res;

	res = ft_itoa_d((long int)va_arg(ap, unsigned int), &arg->sign);
	if (!res)
		return (NULL);
	arg->len = ft_strlen(res);
	if (arg->sign == '-')
	{
		arg->sign = 0;
	}
	if (arg->prec_flag && arg->prec == 0 && *res == '0')
	{
		*res = '\0';
		arg->len = 0;
	}
	if (arg->prec < arg->len)
		arg->prec = arg->len;
	return (trim_and_align_digit(res, arg));
}
