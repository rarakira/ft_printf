#include "ft_printf.h"

char	*trim_and_align(char *str, t_args *arg)
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
