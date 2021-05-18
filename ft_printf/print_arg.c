/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:31:30 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/18 18:33:12 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_arg_d(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	res = ft_itoa(va_arg(ap, int));
	return (res);
}

char	*convert_arg_c(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	res = ft_calloc(2, sizeof(char));
	*res = va_arg(ap, int);
	return (res);
}

char	*convert_arg_s(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	res = ft_strdup(va_arg(ap, char *));
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
	else
		ft_putstr_fd("_unknown_format_", 1);
	if (str)
	{
		*count += ft_strlen(str);
		ft_putstr_fd(str, 1);
		free(str);
	}
}
