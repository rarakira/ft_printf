/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_control_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:26:24 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/18 18:33:57 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fetch_fspec(char **s)
{
	size_t	n;
	char	*res;

	n = 0;
	while (!ft_isalpha(*(*s + n)))
		n++;
	n++;
	res = ft_substr(*s, 0, n);
	*s += n;
	return (res);
}

void	print_control_string(int n_args, char *s, va_list ap, int *count)
{
	char	*fspec;

	while (n_args-- > 0 || *s != '\0')
	{
		while (*s != '\0' && *s != '%')
		{
			ft_putchar_fd(*s++, 1);
			*count += 1;
		}
		if (*s == '%' && *(s + 1) == '%')
		{
			ft_putchar_fd('%', 1);
			s += 2;
			n_args++;
		}
		else if (*s == '%')
		{
			fspec = fetch_fspec(&s);
			print_arg(fspec, ap, count);
			free(fspec);
		}
	}
	// va_end(ap); // should there be one?
}
