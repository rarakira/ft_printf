#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("Hello! All set & good!\n");
	ft_printf("\n%%d, %%d, %%d\n");
	ft_printf("%d, %d, %d\n", 5, 10, 20, 50, 100);
	ft_printf("\n%%, %%d , %%d\n");
	ft_printf("%%, %d, %d\n", 5, 10);
	return (0);
}
