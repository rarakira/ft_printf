#include "ft_printf.h"

char	*convert_arg_x(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	(void) ap;
	res = ft_strdup("x-value");
	return (res);
}

char	*convert_arg_u(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	(void) ap;
	res = ft_strdup("u-value");
	return (res);
}

char	*convert_arg_i(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	(void) ap;
	res = ft_strdup("i-value");
	return (res);
}

char	*convert_arg_p(char *fspec, va_list ap)
{
	char	*res;

	(void) fspec;
	(void) ap;
	res = ft_strdup("p-value");
	return (res);
}