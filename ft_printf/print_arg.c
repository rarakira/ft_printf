/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:31:30 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/20 18:30:42 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_size_arg(char **fspec, va_list ap, int *sign)
{
	long	res;

	if (**fspec == '*')
	{
		res = va_arg(ap, int);
		*fspec += 1;
	}
	else
	{
		res = ft_atoi(*fspec);
		while (ft_isdigit(**fspec))
			*fspec += 1;
	}
	if (res < 0)
	{
		*sign = 1;
		res *= -1;
	}
	return ((size_t)res);
}

void	init_arg(t_args *arg, va_list ap, char *fspec)
{
	arg->width = 0;
	arg->a_left = 0;
	arg->prec = 0;
	arg->prec_flag = 0;
	arg->prec_neg = 0;
	arg->str = NULL;
	arg->format = fspec[ft_strlen(fspec) - 1];
	if (*fspec == '-')
	{
		arg->a_left = 1;
		fspec++;
	}
	if (*fspec == '*' || ft_isdigit(*fspec))
		arg->width = get_size_arg(&fspec, ap, &(arg->a_left));
	if (*fspec == '.')
	{
		arg->prec_flag = 1;
		fspec++;
		arg->prec = get_size_arg(&fspec, ap, &(arg->prec_neg));
	}
}

void	print_arg(char *fspec, va_list ap, int *count)
{
	t_args	arg;

	init_arg(&arg, ap, fspec);
	if (arg.format == 'd')
		arg.str = convert_arg_d(fspec, ap);
	else if (arg.format == 's')
		arg.str = convert_arg_s(&arg, ap);
	else if (arg.format == 'c')
		arg.str = convert_arg_c(fspec, ap);
	else if (arg.format == 'p')
		arg.str = convert_arg_p(fspec, ap);
	else if (arg.format == 'i')
		arg.str = convert_arg_i(fspec, ap);
	else if (arg.format == 'u')
		arg.str = convert_arg_u(fspec, ap);
	else if (arg.format == 'x' || arg.format == 'X')
		arg.str = convert_arg_x(fspec, ap);
	else
		ft_putstr_fd("_unknown_format_", 1); //manage later
	if (arg.str)
	{
		*count += ft_strlen(arg.str);
		ft_putstr_fd(arg.str, 1);
		free(arg.str);
	}
}
