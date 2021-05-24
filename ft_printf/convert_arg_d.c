#include "ft_printf.h"

static void	translate_nums(char *num, long int n, unsigned int len)
{
	if (n == 0)
		num[--len] = '0';
	while (n)
	{
		num[--len] = (n % 10) + '0';
		n = (n - (n % 10)) / 10;
	}
}

/* Function converts integers to strings (memory allocated). */
char	*ft_itoa_d(int n, char	*sign)
{
	char			*num;
	unsigned int	len;
	long int		mod;
	long int		nn;

	mod = 10;
	len = 1;
	nn = n;
	if (nn < 0)
	{
		*sign = '-';
		nn *= -1;
	}
	while (nn % mod != nn)
	{
		mod *= 10;
		len++;
	}
	num = ft_calloc(len + 1, sizeof(char));
	if (num)
		translate_nums(num, nn, len);
	return (num);
}

char	*convert_arg_d(t_args *arg, va_list ap)
{
	char	*res;

	res = ft_itoa_d(va_arg(ap, int), &arg->sign);
	if (!res)
		return (NULL);
	arg->len = ft_strlen(res);
	if (arg->prec < arg->len)
		arg->prec = arg->len;
	if (arg->sign)
		arg->prec++;
	return (trim_and_align_digit(res, arg));
}
