/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:43:41 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/20 14:00:03 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_args
{
	size_t	width;
	int		a_left;
	size_t	prec;
	int		prec_flag;
	int		prec_neg;
	char	*str;
}				t_args;

int		ft_printf(const char *str, ...);
void	print_control_string(int n_args, char *s, va_list ap, int *count);
void	print_arg(char *fspec, va_list ap, int *count);
char	*convert_arg_c(char *fspec, va_list ap);
char	*convert_arg_s(char *fspec, va_list ap);

#endif
