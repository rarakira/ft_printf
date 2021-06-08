/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:43:41 by lbaela            #+#    #+#             */
/*   Updated: 2021/06/08 14:29:34 by lbaela           ###   ########.fr       */
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
	char	padding; // '0' || ' '
	char	sign;
	size_t	width;
	size_t	len;
	int		a_left; // '-'
	int		flag_0; // '0'
	int		flag_alt; // '#'
	size_t	prec;
	int		prec_flag;
	int		prec_neg;
	char	*str;
	int		l;
	int		h;
}				t_args;

int		ft_printf(const char *str, ...);
int		print_control_string(char *s, va_list ap, int *count);
int		print_arg(char *fspec, va_list ap, int *count);
void	get_arg(t_args *arg, va_list ap, char *fspec);
void	check_for_mods(t_args *arg, char **fspec);
void	check_for_flags(t_args *arg, char **fspec);
char	*convert_arg_c_prc(t_args *arg, va_list ap, int *count);
char	*convert_arg_s(t_args *arg, va_list ap, int *count);
char	*convert_arg_d_u_i(t_args *arg, va_list ap, int *count);
char	*convert_arg_x_p(t_args *arg, va_list ap, int *count);
char	*convert_arg_i(char *fspec, va_list ap);
char	*convert_arg_p(char *fspec, va_list ap);
char	*trim_and_align_str(char *str, t_args *arg, int *count);
char	*trim_and_align_digit(char *str, t_args *arg, int *count);
char	*ft_itoa_d(long int n, char *sign);
char	*ft_itoa_x(long int n, t_args *arg);
char	*ft_itoa_u(unsigned long int n);
//char	*ft_itoa_p(long long int n, char *sign, char format);

#endif
