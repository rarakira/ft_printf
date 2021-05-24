#include "ft_printf.h"

static void	print_spaces(t_args *arg, int *count)
{
	while (arg->width-- > 1)
	{
		*count += 1;
		ft_putchar_fd(' ', 1);
	}
}

char	*convert_arg_c(t_args *arg, va_list ap, int *count)
{
	char	*res;

	res = ft_calloc(2, sizeof(char));
	*res = va_arg(ap, int);
	if (*res == '\0')
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
		free(res);
		return (NULL);
	}
	arg->prec = 1;
	return (trim_and_align_str(res, arg));
}
