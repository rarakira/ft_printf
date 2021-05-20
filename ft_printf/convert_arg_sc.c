/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg_sc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:52:34 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/20 13:59:55 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_arg_c(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	res = ft_calloc(2, sizeof(char));
	*res = va_arg(ap, int);
	return (res);
}

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

void	init_arg(t_args *arg)
{
	arg->width = 0;
	arg->a_left = 0;
	arg->prec = 0;
	arg->prec_flag = 0;
	arg->prec_neg = 0;
	arg->str = NULL;
}

char	*convert_arg_s(char *fspec, va_list ap)
{
	char	*res;
	char	*tmp;
	t_args	arg;

	init_arg(&arg);
	if (*fspec == '-')
	{
		arg.a_left = 1;
		fspec++;
	}
	if (*fspec == '*' || ft_isdigit(*fspec))
		arg.width = get_size_arg(&fspec, ap, &arg.a_left);
	if (*fspec == '.')
	{
		arg.prec_flag = 1;
		fspec++;
		arg.prec = get_size_arg(&fspec, ap, &arg.prec_neg);
	}
	res = ft_strdup(va_arg(ap, char *));
	if (!arg.prec_flag || ft_strlen(res) < arg.prec || arg.prec_neg)
		arg.prec = ft_strlen(res);
	if (ft_strlen(res) > arg.prec && arg.prec_flag)
	{
		tmp = (char *)ft_calloc(arg.prec + 1, sizeof(char));
		ft_strlcpy(tmp, res, arg.prec + 1);
		free(res);
		res = NULL;
	}
	else
	{
		tmp = res;
		res = NULL;
	}
	if (arg.width < arg.prec)
		arg.width = arg.prec;
	if (ft_strlen(tmp) < arg.width)
	{
		res = (char *)ft_calloc(arg.width + 1, sizeof(char));
		ft_memset(res, ' ', arg.width);
		if (!arg.a_left)
				ft_memcpy((res + arg.width - arg.prec), tmp, arg.prec);
		else
				ft_memcpy(res, tmp, arg.prec);
		free(tmp);
	}
	else
		return (tmp);
	return (res);
}
