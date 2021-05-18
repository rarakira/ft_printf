/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:31:30 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/18 20:56:47 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_arg_x(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	(void) ap;
	res = ft_strdup("x-value");
	return (res);
}

char	*convert_arg_u(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	(void) ap;
	res = ft_strdup("u-value");
	return (res);
}

char	*convert_arg_i(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	(void) ap;
	res = ft_strdup("i-value");
	return (res);
}

char	*convert_arg_p(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	(void) ap;
	res = ft_strdup("p-value");
	return (res);
}

char	*convert_arg_d(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	res = ft_itoa(va_arg(ap, int));
	return (res);
}

void	print_arg(char *fspec, va_list ap, int *count)
{
	char	*str;
	char	format;

	str = NULL;
	format = fspec[ft_strlen(fspec) - 1];
	if (format == 'd')
		str = convert_arg_d(fspec, ap);
	else if (format == 's')
		str = convert_arg_s(fspec, ap);
	else if (format == 'c')
		str = convert_arg_c(fspec, ap);
	else if (format == 'p')
		str = convert_arg_p(fspec, ap);
	else if (format == 'i')
		str = convert_arg_i(fspec, ap);
	else if (format == 'u')
		str = convert_arg_u(fspec, ap);
	else if (format == 'x' || format == 'X')
		str = convert_arg_x(fspec, ap);
	else
		ft_putstr_fd("_unknown_format_", 1); //manage later
	if (str)
	{
		*count += ft_strlen(str);
		ft_putstr_fd(str, 1);
		free(str);
	}
}
