#include "ft_printf.h"

char	*convert_arg_d(t_args *arg, va_list ap)
{
	char	*res;

	res = ft_itoa(va_arg(ap, int));
	if (!res)
		return (NULL);
	arg->prec = ft_strlen(res);
	return (trim_and_align(res, arg));
}
