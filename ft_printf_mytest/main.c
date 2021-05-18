#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

void print_name(char *name)
{
	printf("\n\n--Test %s--\n\n", name);
}

void next(void)
{
	printf("\n");
}
void test_01(char *name)
{
	print_name(name);
	ft_printf("%%0.0d, %%5d, %%d:\n");
	ft_printf("%0.0d, %5d, %d\n", 5, 10, 20, 50, 100);
	next();
	ft_printf("%%%%, %%d , %%s, %%c:\n");
	ft_printf("%%, %d, %s, %c\n", 5, "Hello", 'W');
	ft_printf("%%, %d, %s, %d (changed to %%d)\n", 5, "Hello", 'W');
	next();
	ft_printf("%%%% %%%% %%d %%x %%i:\n");
	ft_printf("%% %% %d %x %i\n", 5, 10);
}

void test_02(char *name)
{
	int	a;
	int	ft_a;
	print_name(name);
	printf("Printf: Number of chars = %d\n",
	a = printf("%d, %d, %d\n", 5, 10, 20000000));
	ft_printf("Ft_Printf: Number of chars = %d\n",
	ft_a = ft_printf("%d, %d, %d\n", 5, 10, 20000000));

	if (a == ft_a)
		ft_printf("\n+++++++++++++++\n++ All good! ++\n+++++++++++++++\n");
	else
	{
		ft_printf("\n-----------------\nXX Error found XX\n-----------------\n");
	}

	next();
	printf("Printf: Number of chars = %d\n",
	a = printf("%%%% %%%%\n"));;
	ft_printf("Ft_Printf: Number of chars = %d\n",
	ft_a = ft_printf("%%%% %%%%\n"));

	if (a == ft_a)
		ft_printf("\n+++++++++++++++\n++ All good! ++\n+++++++++++++++\n");
	else
	{
		ft_printf("\n-----------------\nXX Error found XX\n-----------------\n");
	}
}

void test_03(char *name)
{
	print_name(name);
	ft_printf("\n\n");
}

void test_04(char *name)
{
	print_name(name);
	printf("Here is the %%.10x format = %.10x (%d), and %%.10X = %.0X\n\n", 125, 125, 125);
}

int	main(void)
{
	ft_printf("\n* * * ************* STARTING TEST ************* * * *\n");
	test_01("01, all formats");
	test_02("02, return values");
	//test_03("02, string args");
	test_04("04, Xx-format");
	
	ft_printf("\n* * * ************* TEST COMPLETED ************ * * *\n\n");
	return (0);
}
