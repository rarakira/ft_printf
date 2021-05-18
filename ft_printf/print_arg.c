/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:31:30 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/18 12:57:30 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(char *fspec, va_list ap)
{
	int		num;
	char	ch;
	char	*str;
	char	format;

	format = fspec[ft_strlen(fspec) - 1];
	if (format == 'd')
	{
		num = va_arg(ap, int);
		ft_putnbr_fd(num, 1);
	}
	else if (format == 's')
	{
		str = ft_strdup(va_arg(ap, char *));
		if (!str)
			return ;
		ft_putstr_fd(str, 1);
		free(str);
	}
	else if (format == 'c')
	{
		ch = va_arg(ap, int);
		ft_putchar_fd(ch, 1);
	}
	else
	{
		ft_putstr_fd("_unknown_format_", 1);
	}
	
}
