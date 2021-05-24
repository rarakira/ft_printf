#include "ft_printf.h"

char	*trim_and_align_digit(char *str, t_args *arg)
{
	char	*res;

	res = NULL;
	//printf("\nwidth = %zu, prec = %zu, strlen = %zu\n", arg->width, arg->prec, ft_strlen(str));
	if (ft_strlen(str) < arg->width || ft_strlen(str) < arg->prec)
	{
		if (arg->width > arg->prec)
		{
			res = (char *)ft_calloc(arg->width + 1, sizeof(char));
			ft_memset(res, arg->padding, arg->width);
			if (arg->len < arg->prec && !arg->a_left && arg->prec_flag)
				ft_memset(res + arg->width - arg->prec, '0', arg->prec);
			if (arg->len < arg->prec && arg->a_left && arg->prec_flag)
				ft_memset(res, '0', arg->prec);
		}
		else
		{
			arg->padding = '0';
			res = (char *)ft_calloc(arg->prec + 1, sizeof(char));
			ft_memset(res, arg->padding, arg->prec);
			arg->width = arg->prec;
		}
		if (!arg->a_left)
		{
			if (arg->sign) // ADD if (*str == '0')
			{
				if (arg->flag_0 && !arg->prec_flag)
					*res = arg->sign;
				else
					res[arg->width - arg->prec--] = arg->sign;
			}
			if (arg->prec > arg->len)
				ft_memcpy((res + arg->width - arg->len), str, arg->len);
			else
				ft_memcpy((res + arg->width - arg->len), str, arg->len);
		}
		else
		{
			if (arg->sign)
			{
				*res = arg->sign;
				if (arg->prec > arg->len)
					ft_memcpy(res + arg->prec - arg->len, str, arg->len);
				else
					ft_memcpy(res + 1, str, arg->prec);
			}
			else
				if (arg->prec > arg->len)
					ft_memcpy(res + arg->prec - arg->len, str, arg->len);
				else
					ft_memcpy(res, str, arg->prec);
		}
		free(str);
	}
	else
		return (str);
	return (res);
}

char	*trim_and_align_str(char *str, t_args *arg)
{
	char	*res;

	res = NULL;
	if (ft_strlen(str) < arg->width)
	{
		res = (char *)ft_calloc(arg->width + 1, sizeof(char));
		ft_memset(res, arg->padding, arg->width);
		if (!arg->a_left)
			ft_memcpy((res + arg->width - arg->prec), str, arg->prec);
		else
			ft_memcpy(res, str, arg->prec);
		free(str);
	}
	else
		return (str);
	return (res);
}
