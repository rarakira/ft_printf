#include "ft_printf.h"

static void	print_spaces(t_args *arg, int *count)
{
	while (arg->width-- > 1)
	{
		*count += 1;
		ft_putchar_fd(' ', 1);
	}
}

static void	print_eol(t_args *arg, int *count)
{
	if (!arg->a_left)
	{
		print_spaces(arg, count);
		ft_putchar_fd('\0', 1);
	}
	else
	{
		ft_putchar_fd('\0', 1);
		print_spaces(arg, count);
	}
	*count += 1;
}

char	*convert_arg_long_c(t_args *arg, va_list ap, int *count)
{
	wchar_t		w_ch;
	char		*res;
	size_t		n;

	w_ch = va_arg(ap, wchar_t);
	if (w_ch == '\0')
	{
		print_eol(arg, count);
		return (NULL);
	}
	arg->prec = 1;
	res = (char *)malloc(sizeof(w_ch) + 1);
	n = wctomb(res, w_ch);
	res[n] = '\0';
	return(trim_and_align_str(res, arg, count));
}
