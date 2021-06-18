#include "ft_printf.h"

wchar_t	*wchar_strdup(wchar_t *s1)
{
	wchar_t	*dup;
	size_t	len;

	//printf("\n\nWCHAR :: %ls\n\n", s1);
	//if (!s1)
	//	return (NULL);
	len = 0;
	while (s1[len] != L'\0')
		len++;
	dup = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
	if (dup)
	{
		ft_memcpy(dup, s1, len * sizeof(wchar_t));
		dup[len] = L'\0';
	}
	//printf("\n\nWCHAR :: %ls\n\n", dup);
	return (dup);
}

static char	*wchar_joinstr(wchar_t *w_res, size_t len)
{
	size_t	i;
	char	*str;
	char	*tmp;
	char	*res;
	size_t	n;
	//wchar_t	ch;

	i = 0;
	res = (char *)ft_calloc(1, 1);
	str = (char *)malloc(sizeof(wchar_t) + 1);
	if (!str || !res)
	{
		free(str);
		free(res);
		return (NULL);
	}
	while (len-- && w_res[i])
	{
		n = wctomb(str, *(w_res + i++));
		str[n] = '\0';
		tmp = res;
		res = ft_strjoin(tmp, str);
		free(tmp);
	}
	free(str);
	//printf("\n\nRES :: %s\n\n", res);
	return (res);
}

char	*get_w_string(t_args *arg, va_list ap, int *count)
{
	wchar_t	*w_res;
	wchar_t	*tmp;
	size_t	len;
	char	*res;

	tmp = wchar_strdup(va_arg(ap, wchar_t *));
	//printf("\n\nTMP :: %ls\n\n", tmp);
	if (!tmp)
		tmp = wchar_strdup(L"(null)");
	//printf("\n\nTMP :: %ls\n\n", tmp);
	len = 0;
	while (tmp[len] != L'\0')
		len++;
	if (!arg->prec_flag || len < arg->prec || arg->prec_neg)
		arg->prec = len;
	if (len > arg->prec && arg->prec_flag)
	{
		w_res = (wchar_t *)ft_calloc(arg->prec + 1, sizeof(wchar_t));
		ft_memcpy(w_res, tmp, (arg->prec + 1) * sizeof(wchar_t));
		free(tmp);
	}
	else
		w_res = tmp;
	if (arg->width < arg->prec)
		arg->width = arg->prec;
	//printf("\n\nW_RES :: %ls\n\n", w_res);
	res = wchar_joinstr(w_res, len);
	if (!res)
	{
		free(w_res);
		*count = -1;
		return (NULL);
	}
	free(w_res);
	return (trim_and_align_str(res, arg, count));
}
