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

void test_02_2(char *name)
{
	char *str1 = "Hello world!";
	char *str2 = "World Hello!";

	print_name(name);
	printf("%%-20s\n");
	printf("Printf: %d\n", printf("|%-20s|\n", str1));
	printf("Ft_printf: %d\n", ft_printf("|%-20s|\n", str1));
	next();
	printf("%%30.5s\n");
	printf("Printf: %d\n", printf("|%30.5s|\n", str1));
	printf("Ft_printf: %d\n", ft_printf("|%30.5s|\n", str1));
	next();
	printf("%%20.30s\n");
	printf("Printf: %d\n", printf("|%20.30s|\n", str2));
	printf("Ft_printf: %d\n", ft_printf("|%20.30s|\n", str2));
	next();
	printf("%%*.*s\n");
	printf("Printf: %d\n", printf("|%*.*s|\n", 15, 5, str1));
	printf("Ft_printf: %d\n", ft_printf("|%*.*s|\n", 15, 5, str1));
	next();
	printf("%%.s\n");
	printf("Printf: %d\n", printf("|%.s|\n", "lol"));
	printf("Ft_printf: %d\n", ft_printf("|%.s|\n", "lol"));
	next();
	printf("%%5.s\n");
	printf("Printf: %d\n", printf("|%5.s|\n", "lol"));
	printf("Ft_printf: %d\n", ft_printf("|%5.s|\n", "lol"));
}

void test_03(char *name)
{
	char *str1 = "Hello world!";
	char *str2 = "World Hello!";
	int n1, n2;

	print_name(name);
	printf("%%s\n");
	n1 = printf("pf:\t|%s|\n", str1);
	n2 = ft_printf("ft:\t|%s|\n", str1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%%.5s\n");
	n1 = printf("pf:\t|%.5s|\n", str1);
	n2 = ft_printf("ft:\t|%.5s|\n", str1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%%20s\n");
	n1 = printf("pf:\t|%20s|\n", str1);
	n2 = ft_printf("ft:\t|%20s|\n", str1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%%-20s\n");
	n1 = printf("pf:\t|%-20s|\n", str1);
	n2 = ft_printf("ft:\t|%-20s|\n", str1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
	printf("%%30.5s\n");
	n1 = printf("pf:\t|%30.5s|\n", str1);
	n2 = ft_printf("ft:\t|%30.5s|\n", str1);
	next();

	printf("%%20.30s\n");
	n1 = printf("pf:\t|%20.30s|\n", str2);
	n2 = ft_printf("ft:\t|%20.30s|\n", str2);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%%*.*s\n");
	n1 = printf("pf:\t|%*.*s|\n", 15, 5, str1);
	n2 = ft_printf("ft:\t|%*.*s|\n", 15, 5, str1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%%.s\n");
	n1 = printf("pf:\t|%.s|\n", "lol");
	n2 = ft_printf("ft:\t|%.s|\n", "lol");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%%5.s\n");
	n1 = printf("pf:\t|%5.s|\n", "lol");
	n2 = ft_printf("ft:\t|%5.s|\n", "lol");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", " %*.5s %*.5s ");
	n1 = printf("pf:\t|%*.5s| ||%*.5s||\n", -10, "123", 10, "4567");
	n2 = ft_printf("ft:\t|%*.5s| ||%*.5s||\n", 10, "123", 10, "4567"); // "-"
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", " %*.5s %*.5s ");
	n1 = printf("pf:\t|%*.5s| ||%*.5s||\n", 10, "123", -10, "4567");
	n2 = ft_printf("ft:\t|%*.5s| ||%*.5s||\n", 10, "123", 10, "4567"); // "-"
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
}

void test_04(char *name)
{
	print_name(name);
	printf("Here is the %%.10x format = %.10x (%d), and %%.10X = %.0X\n\n", 125, 125, 125);
}

int	main(void)
{
	ft_printf("\n* * * ************* STARTING TEST ************* * * *\n");
	//test_01("01, all formats");
	//test_02("02, return values");
	//test_02_2("02-2, return values (strings)");
	test_03("03, string args");
	//test_04("04, Xx-format");
	
	ft_printf("\n* * * ************* TEST COMPLETED ************ * * *\n\n");
	return (0);
}
