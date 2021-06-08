#include "ft_printf.h"

static char	*get_arg_string(t_args *arg, va_list ap)
{
	char	*res;

	if (arg->format == 'd' || arg->format == 'i')
	{
		if (arg->l != 0)
			res = ft_itoa_d(va_arg(ap, long int), &arg->sign);
		else
			res = ft_itoa_d((long int)va_arg(ap, int), &arg->sign);
	}
	if (arg->format == 'u')
	{
		if (arg->l != 0)
			res = ft_itoa_u(va_arg(ap, unsigned long int));
		else
			res = ft_itoa_u((unsigned long int) va_arg(ap, unsigned int));
	}
	return (res);
}

char	*convert_arg_d_u_i(t_args *arg, va_list ap, int *count)
{
	char	*res;

	res = get_arg_string(arg, ap);
	if (res == NULL)
	{
		*count = -1;
		return (NULL);
	}
	arg->len = ft_strlen(res);
	if (arg->prec_flag && arg->prec == 0 && *res == '0')
	{
		*res = '\0';
		arg->len = 0;
	}
	if (arg->prec < arg->len)
		arg->prec = arg->len;
	if (arg->sign)
		arg->prec++;
	return (trim_and_align_digit(res, arg, count));
}
