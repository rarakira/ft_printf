#include "ft_printf.h"

static char	*get_arg_string(t_args *arg, va_list ap)
{
	char	*res;

	if (arg->format == 'x' || arg->format == 'X')
	{
		if (arg->mod_l != 0)
			res = ft_itoa_x(va_arg(ap, long int), arg);
		else
			res = ft_itoa_x((long int) va_arg(ap, int), arg);
	}
	if (arg->format == 'p')
		res = ft_itoa_p(va_arg(ap, unsigned long int), arg);
	return (res);
}

char	*convert_arg_x_p(t_args *arg, va_list ap, int *count)
{
	char	*res;

	res = get_arg_string(arg, ap);
	if (res == NULL)
	{
		*count = -1;
		return (NULL);
	}
	arg->len = ft_strlen(res);
	//printf("\nP_FLAG : %d, PREC = %zu, RES : %s, FORMAT : \'%c\'\n", arg->prec_flag, arg->prec, res, arg->format);
	if ((arg->prec_flag && arg->prec == 0 && ft_strlen(res) == 1 && arg->format != 'p') || (arg->format == 'p' && arg->prec_flag))
	{
		*res = '\0';
		arg->len = 0;
	}
	//printf("\nP_FLAG : %d, PREC = %zu, RES : %s, FORMAT : \'%c\'\n", arg->prec_flag, arg->prec, res, arg->format);
	if (arg->prec < arg->len)
		arg->prec = arg->len;
	if (arg->sign)
		arg->sign = 0;
	return (trim_and_align_digit(res, arg, count));
}
