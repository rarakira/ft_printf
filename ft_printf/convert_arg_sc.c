/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg_sc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:52:34 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/20 13:18:58 by lbaela           ###   ########.fr       */
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

char	*convert_arg_s(char *fspec, va_list ap)
{
	char	*res;
	char	*tmp;
	int		adj_l;
	int		prec_neg;
	size_t	width;
	size_t	precision;
	int		flag_p;

	adj_l = 0;
	prec_neg = 0;
	precision = 0;
	width = 0;
	flag_p = 0;
	if (*fspec == '-')
	{
		adj_l = 1;
		fspec++;
	}
	if (*fspec == '*' || ft_isdigit(*fspec))
		width = get_size_arg(&fspec, ap, &adj_l);
	if (*fspec == '.')
	{
		flag_p = 1;
		fspec++;
		precision = get_size_arg(&fspec, ap, &prec_neg);
	}
	res = ft_strdup(va_arg(ap, char *));
	if (!flag_p || ft_strlen(res) < precision || prec_neg)
		precision = ft_strlen(res);
	if (ft_strlen(res) > precision && flag_p)
	{
		tmp = (char *)ft_calloc(precision + 1, sizeof(char));
		ft_strlcpy(tmp, res, precision + 1);
		free(res);
		res = NULL;
	}
	else
	{
		tmp = res;
		res = NULL;
	}
	if (width < precision)
		width = precision;
	if (ft_strlen(tmp) < width)
	{
		res = (char *)ft_calloc(width + 1, sizeof(char));
		ft_memset(res, ' ', width);
		if (!adj_l)
				ft_memcpy((res + width - precision), tmp, precision);
		else
				ft_memcpy(res, tmp, precision);
		free(tmp);
	}
	else
		return (tmp);
	return (res);
}
