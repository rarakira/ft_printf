#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("\n* * * ************* STARTING TEST ************* * * *\n");
	ft_printf("\n%%0.0d, %%5d, %%d:\n");
	ft_printf("%0.0d, %5d, %d\n", 5, 10, 20, 50, 100);
	ft_printf("\n%%%%, %%d , %%s, %%c:\n");
	ft_printf("%%, %d, %s, %c\n", 5, "Hello", 'W');
	ft_printf("%%, %d, %s, %d (changed to %%d)\n", 5, "Hello", 'W');
	ft_printf("\n%%%% %%%% %%d %%x %%i:\n");
	ft_printf("%% %% %d %x %i\n\n", 5, 10);
	//printf("Number of chars = %d\n", printf("%d, %5d, %d\n", 5, 10, 20));
	ft_printf("\n* * * ************* TEST COMPLETED ************ * * *\n\n");
	return (0);
}
