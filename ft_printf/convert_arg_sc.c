/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg_sc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:52:34 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/18 20:52:47 by lbaela           ###   ########.fr       */
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

char	*convert_arg_s(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	res = ft_strdup(va_arg(ap, char *));
	return (res);
}
