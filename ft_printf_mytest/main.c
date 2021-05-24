#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

void print_name(char *name)
{
	printf("\n\n--Test %s--\n\n", name);
}

void next(void)
{
	printf("\n\n");
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
	int n1, n2;

	print_name(name);

	char *str1 = "Hello world!";
	char *str2 = "World Hello!";

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
	printf("\nRES LEN: %d, %d\n", n1, n2);
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

	printf("%s\n", "%*.5s %*.5s");
	n1 = printf("pf:\t|%*.5s| ||%*.5s||\n", -10, "123", 10, "4567");
	n2 = ft_printf("ft:\t|%*.5s| ||%*.5s||\n", -10, "123", 10, "4567");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%*.5s %*.5s");
	n1 = printf("pf:\t|%*.5s| ||%*.5s||\n", 10, "123", -10, "4567");
	n2 = ft_printf("ft:\t|%*.5s| ||%*.5s||\n", 10, "123", -10, "4567");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%*.5s %*.*s");
	n1 = printf("pf:\t|%*.5s| ||%*.*s||\n", 10, "123", 35, -2, "4567"); // neg_p
	n2 = ft_printf("ft:\t|%*.5s| ||%*.*s||\n", 10, "123", 35, -2, "4567");//ignr
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%*.5s %*.*s");
	n1 = printf("pf:\t|%*.5s| ||%*.*s||\n", 10, "123", 35, 2, "4567");
	n2 = ft_printf("ft:\t|%*.5s| ||%*.*s||\n", 10, "123", 35, 2, "4567");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%%");
	n1 = printf("pf:\t|%%|\n");
	n2 = ft_printf("ft:\t|%%|\n");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%s: NULL");
	n1 = printf("pf:\t|%s|\n", NULL);
	n2 = ft_printf("ft:\t|%s|\n", NULL);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%-3.s");
	n1 = printf("pf:\t|%-3.s|\n", NULL);
	n2 = ft_printf("ft:\t|%-3.s|\n", NULL);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%-9.1s");
	n1 = printf("pf:\t|%-9.1s|\n", NULL);
	n2 = ft_printf("ft:\t|%-9.1s|\n", NULL);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%.*s");
	n1 = printf("pf:\t|%.*s|\n", -2, NULL);
	n2 = ft_printf("ft:\t|%.*s|\n", -2, NULL);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%4.2ss %-1.s %-----5.3s");
	n1 = printf("pf:\t|%4.2s|s ||%-1.s|| |%-----5.3s|\n", "coco", NULL, "yooo");
	n2 = ft_printf("ft:\t|%4.2s|s ||%-1.s|| |%-----5.3s|\n", "coco", NULL, "yooo");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%4.2ss %-1.s %--5.3s");
	n1 = printf("pf:\t|%4.2s|s ||%-1.s|| ||%--5.3s||\n", "coco", NULL, "yooo");
	n2 = ft_printf("ft:\t|%4.2s|s ||%-1.s|| ||%--5.3s||\n", "coco", NULL, "yooo");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%*(-5).3s %*(5).3s");
	n1 = printf("pf:\t|%*.3s| ||%*.3s||\n", -5 , "yooo", 5 , "yooo");
	n2 = ft_printf("ft:\t|%*.3s| ||%*.3s||\n", -5 , "yooo", 5 , "yooo");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

}

void test_04(char *name)
{
	print_name(name);
	printf("Here is the %%.10x format = %.10x (%d), and %%.10X = %.0X\n\n", 125, 125, 125);
}

void test_05(char *name)
{
	int n1, n2;

	print_name(name);
/*
	char ch1 = 'A';
	char ch2 = 'B';

	printf("%s\n", "%5c %-5c");
	n1 = printf("pf:\t|%5c| ||%-5c||\n", ch1, ch2);
	n2 = ft_printf("ft:\t|%5c| ||%-5c||\n", ch1, ch2);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%*c %*c");
	n1 = printf("pf:\t|%*c| ||%*c||\n", -10, '1', 10, '2');
	n2 = ft_printf("ft:\t|%*c| ||%*c||\n", -10, '1', 10, '2');
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%-c%-c%c*");
	n1 = printf("pf:\t|%-c%-c%c*|\n", 1, '0', 0);
	n2 = ft_printf("ft:\t|%-c%-c%c*|\n", 1, '0', 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s\n", "%c");
	n1 = printf("pf:\t|%c|\n", 0);
	n2 = ft_printf("ft:\t|%c|\n", 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
	*/

	printf("%s\n", "%----4c %1c %10c%-c");
	n1 = printf("pf:\t|%----4c| ||%1c|| |%10c| ||%-c||", '\0', '\n', (char)564, 0);
	n2 = ft_printf("ft:\t|%----4c| ||%1c|| |%10c| ||%-c||", '\0', '\n', (char)564, 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	//for (int i = 0; i < 100; i++)
	//	printf("%d\t%c\n", i, i);

}


void test_06(char *name)
{
	wchar_t	s[4];
	int	a;

	s[0] = 'f';
	s[1] = 'o';
	s[2] = 'o';
	s[3] = '\0';

	print_name(name);
	a = printf("Here is the %S, wchar_t = %lu, char = %lu\n", s, sizeof(wchar_t), sizeof(char));
	//printf("a = %d\n", a);
	for (wchar_t i = 0; i < 1000; i++)
		printf("%d\t%C\n", i, i);
}

void test_07(char *name)
{
	int n1, n2;

	print_name(name);

	int	n = 123;
	int	m = -123;

	printf("1: %s -> %d\n", "%d", n);
	n1 = printf("pf:\t|%d|\n", n);
	n2 = ft_printf("ft:\t|%d|\n", n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("2: %s -> %d\n", "%0d %+0d %0+d", n);
	n1 = printf("pf:\t|%0d| |%+0d| |%0+d|\n", n, n, n);
	n2 = ft_printf("ft:\t|%0d| |%+0d| |%0+d|\n", n, n, n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("3: %s -> %d\n", "%0d %+0d %0+d", m);
	n1 = printf("pf:\t|%0d| |%+0d| |%0+d|\n", m, m, m);
	n2 = ft_printf("ft:\t|%0d| |%+0d| |%0+d|\n", m, m, m);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
	
	printf("4.1.1: %s -> %d\n", "%0.10d %+0.10d %0+.10d", m);
	n1 = printf("pf:\t|%0.10d| |%+0.10d| |%0+.10d|\n", m, m, m);
	n2 = ft_printf("ft:\t|%0.10d| |%+0.10d| |%0+.10d|\n", m, m, m);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("4.1.2: %s -> %d\n", "%.10d %+.10d %.10d", m);
	n1 = printf("pf:\t|%.10d| |%+.10d| |%.10d|\n", m, m, m);
	n2 = ft_printf("ft:\t|%.10d| |%+.10d| |%.10d|\n", m, m, m);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("4.2: %s -> %d\n", "%06.10d %+06.10d %0+6.10d", n);
	n1 = printf("pf:\t|%06.10d| |%+06.10d| |%0+6.10d|\n", n, n, n);
	n2 = ft_printf("ft:\t|%06.10d| |%+06.10d| |%0+6.10d|\n", n, n, n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("4.3: %s -> %d\n", "%6.10d %+6.10d %-6.10d", n);
	n1 = printf("pf:\t|%6.10d| |%+6.10d| |%-6.10d|\n", n, n, n);
	n2 = ft_printf("ft:\t|%6.10d| |%+6.10d| |%-6.10d|\n", n, n, n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("4.4: %s -> %d\n", "%6.10d %+6.10d %-6.10d", m);
	n1 = printf("pf:\t|%6.10d| |%+6.10d| |%-6.10d|\n", m, m, m);
	n2 = ft_printf("ft:\t|%6.10d| |%+6.10d| |%-6.10d|\n", m, m, m);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("4.5: %s -> %d\n", "%10.6d %+10.6d %-10.6d", m);
	n1 = printf("pf:\t|%10.6d| |%+10.6d| |%-10.6d|\n", m, m, m);
	n2 = ft_printf("ft:\t|%10.6d| |%+10.6d| |%-10.6d|\n", m, m, m);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("5: %s -> %d\n", "%0+0000010.6d %010.d %+0.0d %-.0d %020d", n);
	n1 = printf("pf:\t|%0+0000010.6d| ||%010.d|| |%+0.0d| |%-.0d| ||%020d||\n", n, n, n, n, n);
	n2 = ft_printf("ft:\t|%0+0000010.6d| ||%010.d|| |%+0.0d| |%-.0d| ||%020d||\n", n, n, n, n, n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("6: %s -> %d\n", "%0000010.6d %010.d %+0.0d %-.0d %020d", m);
	n1 = printf("pf:\t|%0000010.6d| ||%010.d|| |%+0.0d| |%-.0d| ||%020d||\n", m, m, m, m, m);
	n2 = ft_printf("ft:\t|%0000010.6d| ||%010.d|| |%+0.0d| |%-.0d| ||%020d||\n", m, m, m, m, m);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("7: %s -> %d\n", "%0000010.6d %-10.6d", n);
	n1 = printf("pf:\t|%0000010.6d| ||%-10.6d||\n", m, m);
	n2 = ft_printf("ft:\t|%0000010.6d| ||%-10.6d||\n", m, m);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("8: %s -> %d\n", "%10.2d %-10.2d", n);
	n1 = printf("pf:\t|%10.2d| ||%-10.2d||\n", n, n);
	n2 = ft_printf("ft:\t|%10.2d| ||%-10.2d||\n", n, n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("9: %s -> %d\n", "%10.d %-10.d", m);
	n1 = printf("pf:\t|%10.d| ||%-10.d||\n", m, m);
	n2 = ft_printf("ft:\t|%10.d| ||%-10.d||\n", m, m);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("10: %s -> %d\n", "%10.0d %-10.0d", n);
	n1 = printf("pf:\t|%10.0d| ||%-10.0d||\n", n, n);
	n2 = ft_printf("ft:\t|%10.0d| ||%-10.0d||\n", n, n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("11: %s -> %d\n", "%010.0d %0.0d %010d", n);
	n1 = printf("pf:\t|%010.0d| ||%0.0d|| |%010d|\n", n, n, n);
	n2 = ft_printf("ft:\t|%010.0d| ||%0.0d|| |%010d|\n", n, n, n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("12: %s -> %d\n", "%010d %0.0d %-010d", n);
	n1 = printf("pf:\t|%010d| ||%0.0d|| |%+010d|\n", n, n, n);
	n2 = ft_printf("ft:\t|%010d| ||%0.0d|| |%+010d|\n", n, n, n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
}

int	main(void)
{
	ft_printf("\n* * * ************* STARTING TEST ************* * * *\n");
	//test_01("01, all formats");
	//test_02("02, return values");
	//test_02_2("02-2, return values (strings)");
	//test_03("03, string args");
	//test_04("04, Xx-format");
	//test_05("05, chars");
	//test_06("06, wtf is S?");
	test_07("07, d");
	
	ft_printf("\n* * * ************* TEST COMPLETED ************ * * *\n\n");
	return (0);
}
