/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:00:45 by lbaela            #+#    #+#             */
/*   Updated: 2021/06/07 18:29:31 by lbaela           ###   ########.fr       */
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

static int	inset(char ch, char const *set)
{
	int	i;

	i = 0;
	while (*set)
	{
		if (*set++ == ch)
			return (1);
	}
	return (0);
}

void	check_for_mods(t_args *arg, char **fspec)
{
	int	len;

	len = (int) ft_strlen(*fspec);
	if (len > 1)
		len -= 2;
	while ((*(*fspec + len) == 'l' || *(*fspec + len) == 'h') && len >= 0)
	{
		if (*(*fspec + len) == 'l')
			arg->l += 1;
		else if (*(*fspec + len) == 'h')
			arg->h += 1;
		len--;
	}
}

void	check_for_flags(t_args *arg, char **fspec)
{
	while (inset(**fspec, "-+0 #"))
	{
		if (**fspec == '-')
			arg->a_left = 1;
		else if (**fspec == '0')
		{
			arg->padding = '0';
			arg->flag_0 = 1;
		}
		else if (**fspec == '#' && (arg->format == 'x' || arg->format == 'X'))
			arg->flag_alt = 1;
		else if (**fspec == '+' && arg->sign != '-')
			arg->sign = '+';
		else if (**fspec == ' ' && arg->sign != '+' && arg->sign != '-')
			arg->sign = ' ';
		*fspec += 1;
	}
}

void	init_arg(t_args *arg)
{
	arg->flag_0 = 0;
	arg->sign = 0;
	arg->flag_alt = 0;
	arg->padding = ' ';
	arg->width = 0;
	arg->a_left = 0;
	arg->prec = 0;
	arg->prec_flag = 0;
	arg->prec_neg = 0;
	arg->str = NULL;
	arg->l = 0;
	arg->h = 0;
}

void	get_arg(t_args *arg, va_list ap, char *fspec)
{
	init_arg(arg);
	arg->format = fspec[ft_strlen(fspec) - 1];
	check_for_mods(arg, &fspec);
	check_for_flags(arg, &fspec);
	if (*fspec == '*' || ft_isdigit(*fspec))
		arg->width = get_size_arg(&fspec, ap, &(arg->a_left));
	if (*fspec == '.')
	{
		arg->prec_flag = 1;
		fspec++;
		arg->prec = get_size_arg(&fspec, ap, &(arg->prec_neg));
	}
	if (arg->prec_neg)
	{
		arg->prec_flag = 0;
		arg->prec = 0;
	}
	if ((arg->prec_flag && arg->width > arg->prec) || arg->a_left)
		arg->padding = ' ';
	if (arg->format == 'p')
	{
		arg->flag_alt = 1;
		arg->prec_flag = 0;
		arg->prec = 0;
	}
}
