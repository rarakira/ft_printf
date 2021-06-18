#include "ft_printf.h"

wchar_t	*trim_and_align_long_c(wchar_t *str, t_args *arg, int *count)
{
	wchar_t		*res;
	size_t		len;

	res = NULL;
	len = 0;
	while (str[len] != '\0')
		len++;
	if (len < arg->width)
	{
		res = (wchar_t *)ft_calloc(arg->width + 1, sizeof(wchar_t));
		if (res == NULL)
		{
			*count = -1;
			return (NULL);
		}
		ft_memset(res, ' ', arg->width * sizeof(wchar_t));
		if (!arg->a_left)
		{
			ft_memset(res, arg->padding, arg->width * sizeof(wchar_t));
			ft_memcpy((res + arg->width - arg->prec), str, arg->prec * sizeof(wchar_t));
		}
		else
			ft_memcpy(res, str, arg->prec * sizeof(wchar_t));
		free(str);
	}
	else
		return (str);
	return (res);
}

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

static void	wchar_putstr_fd(wchar_t *s, int fd, int *count)
{
	size_t	len;
	size_t	i;

	i = 0;
	setlocale(LC_ALL, "");
	//printf("\n\n*S = %ls\n\n", s);
	if (!s)
		return ;
	len = 0;
	while (s[len] != '\0')
		len++;
	//printf("\nLEN = %zu\n\n", len);
	*count += len;
	while (s[i])
		write(fd, (s + i++), sizeof(wchar_t));
}

char	*convert_arg_long_c(t_args *arg, va_list ap, int *count)
{
	wchar_t		*tmp;
	wchar_t		*res;

	tmp = ft_calloc(2, sizeof(wchar_t));
	if (!tmp)
	{
		*count = -1;
		return (NULL);
	}
	*tmp = va_arg(ap, wint_t);
	//printf("\n\nTMP = %lc\n", *tmp);
	if (*tmp == '\0')
	{
		print_eol(arg, count);
		free(tmp);
		return (NULL);
	}
	arg->prec = 1;
	res = trim_and_align_long_c(tmp, arg, count);
	//printf("\n\nRES = %lc\n", *res);
	if (!res)
	{
		*count = -1;
		return (NULL);
	}
	wchar_putstr_fd(res, 1, count);
	//printf("\n\nPOINTERS :: tmp %p & res %p\n\n", tmp, res);
	//free(tmp);
	free(res);
	return (NULL);
}
