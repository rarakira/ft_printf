/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg_sc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:52:34 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/20 19:26:10 by lbaela           ###   ########.fr       */
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

char	*get_string(t_args *arg, va_list ap)
{
	char	*res;
	char	*tmp;

	tmp = ft_strdup(va_arg(ap, char *));
	if (!tmp)
		tmp = ft_strdup("(null)");
	if (!arg->prec_flag || ft_strlen(tmp) < arg->prec || arg->prec_neg)
		arg->prec = ft_strlen(tmp);
	if (ft_strlen(tmp) > arg->prec && arg->prec_flag)
	{
		res = (char *)ft_calloc(arg->prec + 1, sizeof(char));
		ft_strlcpy(res, tmp, arg->prec + 1);
		free(tmp);
	}
	else
		res = tmp;
	if (arg->width < arg->prec)
		arg->width = arg->prec;
	return (res);
}

char	*convert_arg_s(t_args *arg, va_list ap)
{
	char	*res;
	char	*tmp;

	tmp = get_string(arg, ap);
	if (!tmp)
		return (NULL);
	if (ft_strlen(tmp) < arg->width)
	{
		res = (char *)ft_calloc(arg->width + 1, sizeof(char));
		ft_memset(res, ' ', arg->width);
		if (!arg->a_left)
			ft_memcpy((res + arg->width - arg->prec), tmp, arg->prec);
		else
			ft_memcpy(res, tmp, arg->prec);
		free(tmp);
	}
	else
		return (tmp);
	return (res);
}
