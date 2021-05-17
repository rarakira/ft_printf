/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:51:22 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/17 20:54:45 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_arg(int format, va_list ap)
{
	int		num;
	char	ch;
	char	*str;

	if (format == 0)
	{
		ft_putstr_fd("_unknown_format_", 1);
	}
	if (format == 1)
	{
		num = va_arg(ap, int);
		ft_putnbr_fd(num, 1);
	}
	if (format == 2)
	{
		str = ft_strdup(va_arg(ap, char *));
		if (!str)
			return ;
		ft_putstr_fd(str, 1);
		free(str);
	}
	if (format == 3)
	{
		ch = va_arg(ap, int);
		ft_putchar_fd(ch, 1);
	}
}
char	*fetch_fspec(char **s)
{
	size_t	n;
	char	*res;

	n = 0;
	while(!ft_isalpha(*(*s + n)))
		n++;
	n++;
	res = ft_substr(*s, 0, n);
	*s += n;
	return(res);
}

int	check_format(char *fspec)
{
	if (fspec[ft_strlen(fspec) - 1] == 'd')
		return (1);
	if (fspec[ft_strlen(fspec) - 1] == 's')
		return (2);
	if (fspec[ft_strlen(fspec) - 1] == 'c')
		return (3);
	return (0);
}

void	print_control_string(int n_args, char *s, va_list ap)
{
	char	*fspec;
	int		format;

	while(n_args-- > 0 || *s != '\0')
	{
		while (*s != '\0' && *s != '%')
			ft_putchar_fd(*s++, 1);
		if (*s == '%' && *(s + 1) == '%')
		{
			ft_putchar_fd('%', 1);
			s += 2;
			n_args++;
		}
		else if (*s == '%')
		{
			fspec = fetch_fspec(&s);
			format = check_format(fspec);
			print_arg(format, ap);
			free(fspec);
		}
	}
	va_end(ap);
}
/* Function that mimics the real printf */
int ft_printf(const char *str, ...)
{
	va_list	ap;
	int	n_args;

	n_args = count_f_specifiers(str);
	va_start(ap, str);
	print_control_string(n_args, (char *)str, ap);
	va_end(ap);
	return (0);
}
