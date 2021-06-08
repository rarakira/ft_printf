/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:31:30 by lbaela            #+#    #+#             */
/*   Updated: 2021/06/08 12:49:36 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(char *fspec, va_list ap, int *count)
{
	t_args	arg;

	get_arg(&arg, ap, fspec);
	if (arg.format == 'd' || arg.format == 'u' || arg.format == 'i')
		arg.str = convert_arg_d_u_i(&arg, ap, count);
	else if (arg.format == 's')
		arg.str = convert_arg_s(&arg, ap, count);
	else if (arg.format == 'c' || arg.format == '%')
		arg.str = convert_arg_c_prc(&arg, ap, count);
	else if (arg.format == 'x' || arg.format == 'X' || arg.format == 'p')
		arg.str = convert_arg_x_p(&arg, ap, count);
	if (!arg.str && *count == -1)
		return (-1);
	if (arg.str)
	{
		*count += ft_strlen(arg.str);
		ft_putstr_fd(arg.str, 1);
		free(arg.str);
	}
	return (0);
}
