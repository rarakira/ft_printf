#include "ft_printf.h"

char	*convert_arg_x_p(t_args *arg, va_list ap, int *count)
{
	char	*res;

	if (arg->format == 'x' || arg->format == 'X')
		res = ft_itoa_x(va_arg(ap, int), &arg->sign, arg->format);
	if (arg->format == 'p')
		res = ft_itoa_x(va_arg(ap, long int), &arg->sign, arg->format);
	if (res == NULL)
	{
		*count = -1;
		return (NULL);
	}
	arg->len = ft_strlen(res);
	if (arg->prec_flag && arg->prec == 0 && *res == '0' && arg->format != 'p')
	{
		*res = '\0';
		arg->len = 0;
	}
	if (arg->prec < arg->len)
		arg->prec = arg->len;
	if (arg->sign)
		arg->sign = 0;
	return (trim_and_align_digit(res, arg, count));
}
