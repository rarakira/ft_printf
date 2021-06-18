#include "ft_printf.h"

wchar_t	*wchar_strdup(wchar_t *s1)
{
	wchar_t	*dup;
	size_t	len;

	//printf("\n\nWCHAR :: %ls\n\n", s1);
	if (!s1)
		return (NULL);
	len = 0;
	while (s1[len] != L'\0')
		len++;
	dup = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
	if (dup)
	{
		ft_memcpy(dup, s1, len * sizeof(wchar_t));
		dup[len] = L'\0';
	}
	return (dup);
}

static void	wchar_putstr_fd(wchar_t *s, int fd, int *count)
{
	size_t	len;
	size_t	i;

	i = 0;
	setlocale(LC_ALL, "");
	if (!s)
		return ;
	len = 0;
	while (s[len] != L'\0')
		len++;
	*count += len;
	//printf("\nLEN = %zu\n\n", len);
	while (len-- && s[i])
		write(fd, (s + i++), sizeof(wchar_t));
}

char	*get_w_string(t_args *arg, va_list ap, int *count)
{
	wchar_t	*res;
	wchar_t	*tmp;
	size_t	len;

	tmp = wchar_strdup(va_arg(ap, wchar_t *));
	//printf("\n\nTMP :: %ls\n\n", tmp);
	if (!tmp)
		tmp = wchar_strdup(L"(null)");
	len = 0;
	while (tmp[len] != L'\0')
		len++;
	if (!arg->prec_flag || len < arg->prec || arg->prec_neg)
		arg->prec = len;
	if (len > arg->prec && arg->prec_flag)
	{
		res = (wchar_t *)ft_calloc(arg->prec + 1, sizeof(wchar_t));
		ft_memcpy(res, tmp, (arg->prec + 1) * sizeof(wchar_t));
		free(tmp);
		//printf("\n\nRES :: %ls\n\n", res);
	}
	else
		res = tmp;
	if (arg->width < arg->prec)
		arg->width = arg->prec;
	wchar_putstr_fd(res, 1, count);
	free(res);
	return (NULL);
}
