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
	printf("%%.s -> %s\n", "lol");
	printf("Printf: %d\n", printf("|%.s|\n", "lol"));
	printf("Ft_printf: %d\n", ft_printf("|%.s|\n", "lol"));
	next();
	printf("%%5.s -> %s\n", "lol");
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
	printf("Here is the %%.0x format = |%.0x| (%d), and %%.0X = |%.0X|\n\n", 125, 125, 125);
	printf("Here is the %%.10x format = |%.10x| (%d), and %%.10X = |%.10X|\n\n", 125, 125, 125);
	printf("Here is the %%-10.5x format = |%-10.5x| (%d), and %%-10.5X = |%-10.5X|\n\n", 125, 125, 125);
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

	printf("3.1: %s -> %d\n", "%0d %+0d %0+d", m);
	n1 = printf("pf:\t|%0d| |%+0d| |%0+d|\n", m, m, m);
	n2 = ft_printf("ft:\t|%0d| |%+0d| |%0+d|\n", m, m, m);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("3.2: %s -> %.4d\n", "%0.4d %+0.4d %0+.4d", m);
	n1 = printf("pf:\t|%0.4d| |%+0.4d| |%0+.4d|\n", m, m, m);
	n2 = ft_printf("ft:\t|%0.4d| |%+0.4d| |%0+.4d|\n", m, m, m);
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

	printf("12: %s -> %d\n", "%010d %010.d %0.0d %-010d", n);
	n1 = printf("pf:\t|%010d| |%010.d| ||%0.0d|| |%+010d|\n", n, n, n, n);
	n2 = ft_printf("ft:\t|%010d| |%010.d| ||%0.0d|| |%+010d|\n", n, n, n, n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("13: %s -> %d\n", "%.3d %.4d", m);
	n1 = printf("pf:\t|%.3d| ||%.4d||\n", m, m);
	n2 = ft_printf("ft:\t|%.3d| ||%.4d||\n", m, m);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

}

void test_08(char *name)
{
	int n1, n2;

	print_name(name);

	int	n = 0;
	//int	m = -123;

	printf("1: %s -> %d\n", "%.1d %.2d %4.2d", n);
	n1 = printf("pf:\t|%.1d| ||%.2d|| |%4.2d|\n", n, n, n);
	n2 = ft_printf("ft:\t|%.1d| ||%.2d|| |%4.2d|\n", n, n, n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("2: %s -> %d\n", "%.d %5.d %-5.d", n);
	n1 = printf("pf:\t|%.d| ||%5.d|| |%-5.d|\n", n, n, n);
	n2 = ft_printf("ft:\t|%.d| ||%5.d|| |%-5.d|\n", n, n, n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("3: %s -> %d, %d, %d, %d,\n", "0*%0-*d*0 0*%0*d*0", 21, 1021, 21, -1011);
	n1 = printf("pf:\t|0*|%-*d|*0 0*||%0*d||*0|\n", 21, 1021, 21, -1011);
	n2 = ft_printf("ft:\t|0*|%0-*d|*0 0*||%0*d||*0|\n", 21, 1021, 21, -1011);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("4: %s -> %d\n", "%+.d %+5.d", n);
	n1 = printf("pf:\t|%+.d| ||%+5.d||\n", n, n);
	n2 = ft_printf("ft:\t|%+.d| ||%+5.d||\n", n, n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("5: %s -> %d, %d, %d, %d,\n", "--0*%0*.0d*0 0*%0*.10d*0--", -2, 0, 21, 1);
	n1 = printf("pf:\t--0*|%0*.0d|*0 0*||%0*.10d||*0--\n", -2, 0, 21, 1);
	n2 = ft_printf("ft:\t--0*|%0*.0d|*0 0*||%0*.10d||*0--\n", -2, 0, 21, 1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("6: %s -> %d %d\n", "%0*d", -7, -54);
	n1 = printf("pf:\t|%0*d|\n", -7, -54);
	n2 = ft_printf("ft:\t|%0*d|\n", -7, -54);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("7: %s -> %d\n", "% d", 0);
	n1 = printf("pf:\t|% d|\n", 0);
	n2 = ft_printf("ft:\t|% d|\n", 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("7: %s -> %d\n", "%+d", 0);
	n1 = printf("pf:\t|%+d|\n", 0);
	n2 = ft_printf("ft:\t|%+d|\n", 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
	
}

void test_09(char *name)
{
	int n1, n2;

	print_name(name);

	//int	n = 0;
	//int	m = -123;
/*
	printf("4: %s -> %d\n", "%+.d %+5.d", n);
	n1 = printf("pf:\t|%+.d| ||%+5.d||\n", n, n);
	n2 = ft_printf("ft:\t|%+.d| ||%+5.d||\n", n, n);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next(); */

	printf("1: %s -> %d %d\n", "%-3.2u %10.42u", 1, -1);
	n1 = printf("pf:\t|%-3.2u| ||%10.42u||\n", 1, -1);
	n2 = ft_printf("ft:\t|%-3.2u| ||%10.42u||\n", 1, -1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("1: %s -> %d %d %d\n", "%-3.2u %+-3.2u % 3.2u", 1, 1, 1);
	n1 = printf("pf:\t|%-3.2u| ||%-3.2u|| |%3.2u|\n", 1, 1, 1); // undef behaviour with '+' & ' ' should i remove mine?
	n2 = ft_printf("ft:\t|%-3.2u| ||%+-3.2u|| |% 3.2u|\n", 1, 1, 1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
}

void test_10(char *name)
{
	int n1, n2;

	print_name(name);

	//int	n = 0;
	//int	m = -123;

	printf("1: %s\n", "%% %10.42%");
	n1 = printf("pf:\t|%%| ||%10.42%||\n");
	n2 = ft_printf("ft:\t|%%| ||%10.42%||\n");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
}

void test_11(char *name)
{
	int n1, n2;

	print_name(name);

	//int	n = 0;
	//int	m = -123;

	printf("1: %s\n", "%p");
	n1 = printf("pf:\t|%%| ||%10.42%||\n");
	n2 = ft_printf("ft:\t|%%| ||%10.42%||\n");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
}

void test_12(char *name)
{
	int n1, n2;

	print_name(name);

	//int	n = 0;
	//int	m = -123;

	printf("1: %s\n", "%% %10.42%");
	n1 = printf("pf:\t|%%| ||%10.42%||\n");
	n2 = ft_printf("ft:\t|%%| ||%10.42%||\n");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
}

void test_13(char *name)
{
	int n1, n2;

	print_name(name);

	//int	n = 0;
	//int	m = -123;

	printf("1: %s\n", "%i %.i %-.2i %-3.2i -> 0");
	n1 = printf("pf:\t|%i| ||%.i|| |%-.2i| ||%-3.2i||\n", 0, 0, 0, 0);
	n2 = ft_printf("ft:\t|%i| ||%.i|| |%-.2i| ||%-3.2i||\n", 0, 0, 0, 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

}

void test_14(char *name)
{
	int n1;
	//int n2;

	print_name(name);

	int	n = 555555;
	double	m = 0.000999;
/*
	printf("1: %s\n", "%n %ln %lln %hn %hhn");
	n1 = printf("pf:\t|%n| ||%ln|| |%lln| ||%hn|| |%hhn|\n", n, n, n, n, n);
	//n2 = ft_printf("ft:\t|%%| ||%10.42%||\n");
	//printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	*/

	printf("1: %s\n", "%.5f %.5g %.5e %.5n -> 0.000999");
	n1 = printf("pf:\t|%.5f| ||%.5g|| |%.5e| ||%n||\n", m, m, m, &n);
	//n2 = ft_printf("ft:\t|%%| ||%10.42%||\n");
	//printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
}

void test_15(char *name)
{
	int n1, n2;

	print_name(name);

	//int	n = 0;
	//int	m = -123;

	printf("1: %s\n", "%% %10.42%");
	n1 = printf("pf:\t|%%| ||%10.42%||\n");
	n2 = ft_printf("ft:\t|%%| ||%10.42%||\n");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
}

void test_16(char *name)
{
	int n1, n2;

	print_name(name);

	//int	n = 0;
	//int	m = -123;

	printf("1: %s\n", "%% %10.42%");
	n1 = printf("pf:\t|%%| ||%10.42%||\n");
	n2 = ft_printf("ft:\t|%%| ||%10.42%||\n");
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
	test_04("04, Xx-format");
	//test_05("05, chars");
	//test_06("06, wtf is S?");
	//test_07("07, d");
	//test_08("08, more d");
	//test_09("09, u");
	//test_10("10, %%");
	//test_11("11, p");
	//test_12("12, x & X");
	//test_13("13, i");
	//test_14("14, n f g e");
	//test_15("15, l ll h hh");
	//test_16("16, #");
	
	ft_printf("\n* * * ************* TEST COMPLETED ************ * * *\n\n");
	return (0);
}
