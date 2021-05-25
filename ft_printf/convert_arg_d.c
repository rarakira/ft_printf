#include "ft_printf.h"

char	*convert_arg_d(t_args *arg, va_list ap)
{
	char	*res;

	res = ft_itoa_d(va_arg(ap, int), &arg->sign);
	if (!res)
		return (NULL);
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
	return (trim_and_align_digit(res, arg));
}
