/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:43:41 by lbaela            #+#    #+#             */
/*   Updated: 2021/05/24 13:03:41 by lbaela           ###   ########.fr       */
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
	char	format;
	char	padding;
	size_t	width;
	int		a_left;
	int		flag_p;
	int		flag_0;
	int		flag_alt;
	size_t	prec;
	int		prec_flag;
	int		prec_neg;
	char	*str;
}				t_args;

int		ft_printf(const char *str, ...);
void	print_control_string(char *s, va_list ap, int *count);
void	print_arg(char *fspec, va_list ap, int *count);
char	*convert_arg_c(t_args *arg, va_list ap, int *count);
char	*convert_arg_s(t_args *arg, va_list ap);
char	*convert_arg_d(t_args *arg, va_list ap);
char	*convert_arg_x(char *fspec, va_list ap);
char	*convert_arg_u(char *fspec, va_list ap);
char	*convert_arg_i(char *fspec, va_list ap);
char	*convert_arg_p(char *fspec, va_list ap);
char	*trim_and_align(char *str, t_args *arg);

#endif
