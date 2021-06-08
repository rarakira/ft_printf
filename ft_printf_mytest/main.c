#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <limits.h>

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
	int n1, n2;

	print_name(name);

	printf("%s -> %d\n", "test 1: %.0x %.0X", 125);
	n1 = printf("pf:\t|%.0x| ||%.0X||\n", 125, 125);
	n2 = ft_printf("ft:\t|%.0x| ||%.0X||\n", 125, 125);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s -> %d\n", "test 2 %.10x %.10X", 125);
	n1 = printf("pf:\t|%.10x| ||%.10X||\n", 125, 125);
	n2 = ft_printf("ft:\t|%.10x| ||%.10X||\n", 125, 125);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s -> %d\n", "test 3: %-10.5x %-10.5X", 125);
	n1 = printf("pf:\t|%-10.5x| ||%-10.5X||\n", 125, 125);
	n2 = ft_printf("ft:\t|%-10.5x| ||%-10.5X||\n", 125, 125);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s -> %d\n", "test 4: %x %X", 17);
	n1 = printf("pf:\t|%x| ||%X||\n", 17, 17);
	n2 = ft_printf("ft:\t|%x| ||%X||\n", 17, 17);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s -> %d\n", "test 5: %x %X", -17);
	n1 = printf("pf:\t|%x| ||%X||\n", -17, -17);
	n2 = ft_printf("ft:\t|%x| ||%X||\n", -17, -17);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s -> %d\n", "test 6.1: %x %X", 123456789);
	n1 = printf("pf:\t|%x| ||%X||\n", 123456789, 123456789);
	n2 = ft_printf("ft:\t|%x| ||%X||\n", 123456789, 123456789);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s -> %d\n", "test 6.2: %x %X", -123456789);
	n1 = printf("pf:\t|%x| ||%X||\n", -123456789, -123456789);
	n2 = ft_printf("ft:\t|%x| ||%X||\n", -123456789, -123456789);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s -> %d %d %d\n", "test 7: %-3.2x %10.42x %10.42x", 10, 10, -10);
	n1 = printf("pf:\t|%-3.2x| ||%10.42x|| |%10.42x|\n", 10, 10, -10);
	n2 = ft_printf("ft:\t|%-3.2x| ||%10.42x|| |%10.42x|\n", 10, 10, -10);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s -> %d %d %d\n", "test 8: %#-3.2X %#10.42x %#10.42x", 10, 10, -10);
	n1 = printf("pf:\t|%#-3.2X| ||%#10.42x|| |%#10.42x|\n", 10, 10, -10);
	n2 = ft_printf("ft:\t|%#-3.2X| ||%#10.42x|| |%#10.42x|\n", 10, 10, -10);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s -> %d\n", "test 9: %-5.0x %-5.0X", 100);
	n1 = printf("pf:\t|%-5.0x| ||%-5.0X||\n", 100, 100);
	n2 = ft_printf("ft:\t|%-5.0x| ||%-5.0X||\n", 100, 100);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s -> %d\n", "test 10: %#-5.0x %#-5.0X %#5.0x", 100);
	n1 = printf("pf:\t|%#-5.0x| ||%#-5.0X|| |%#5.0x|\n", 100, 100, 100);
	n2 = ft_printf("ft:\t|%#-5.0x| ||%#-5.0X|| |%#5.0x|\n", 100, 100, 100);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%s -> %d\n", "test 11: %#X %#X %#x", 0);
	n1 = printf("pf:\t|%#X| ||%#X|| |%#x|\n", 0, 0, 0);
	n2 = ft_printf("ft:\t|%#X| ||%#X|| |%#x|\n", 0, 0, 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
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

	printf("9: %s -> 3, -3\n", "%.6d %.6d");
	n1 = printf("pf:\t|%.6d| ||%.6d||\n", 3, -3);
	n2 = ft_printf("ft:\t|%.6d| ||%.6d||\n", 3, -3);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("9: %s -> 3, -3\n", "%.6i %.6i");
	n1 = printf("pf:\t|%.6i| ||%.6i||\n", 3, -3);
	n2 = ft_printf("ft:\t|%.6i| ||%.6i||\n", 3, -3);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("9: %s -> -6, 3, -6, -3\n", "%.*d %.*d");
	n1 = printf("pf:\t|%.*d| ||%.*d||\n", -6, 3, -6, -3);
	n2 = ft_printf("ft:\t|%.*d| ||%.*d||\n", -6, 3, -6, -3);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("9: %s -> -6, 3, -6, -3\n", "%.*i");
	n1 = printf("pf:\t|%.*i| ||%.*i||\n", -6, 3, -6, -3);
	n2 = ft_printf("ft:\t|%.*i| ||%.*i||\n", -6, 3, -6, -3);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("10.1: %s -> -1, 42, 1\n", "% -010.3d % -010.*d");
	n1 = printf("pf:\t|% -10.3d| ||% -10.*d||\n", -1, 42, 1);
	n2 = ft_printf("ft:\t|% -010.3d| ||% -010.*d||\n", -1, 42, 1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("10.2: %s -> -1, 42, 1\n", "%+-10.3d %+-10.*d");
	n1 = printf("pf:\t|%+-10.3d| ||%+-10.*d||\n", -1, 42, 1);
	n2 = ft_printf("ft:\t|%+-10.3d| ||%+-10.*d||\n", -1, 42, 1);
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

	printf("1: %s -> 4418596912\n", "%lx");
	n1 = printf("pf:\t||%lx||\n", 4418596912);
	n2 = ft_printf("ft:\t||%lx||\n", 4418596912);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("2: %s -> 4418596912\n", "%ld");
	n1 = printf("pf:\t||%ld||\n", 4418596912);
	n2 = ft_printf("ft:\t||%ld||\n", 4418596912);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("3: %s -> 4, 5, 10, 10, 21, -10\n", "*%-*.*x* *%*.*x*");
	n1 = printf("pf:\t||*%-*.*x* *%*.*x*||\n", 4, 5, 10, 10, 21, -10);
	n2 = ft_printf("ft:\t||*%-*.*x* *%*.*x*||\n", 4, 5, 10, 10, 21, -10);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("3: %s -> -6, 2, 102, 10, 21, 101\n", "*%*.*x* *%*.*x*");
	n1 = printf("pf:\t||*%*.*x* *%*.*x*||\n", -6, 2, 102, 10, 21, 101);
	n2 = ft_printf("ft:\t||*%*.*x* *%*.*x*||\n", -6, 2, 102, 10, 21, 101);
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

	printf("1: %s -> 100, 100000000000, 100000000000000000\n", "%d %ld %ld");
	n1 = printf("pf:\t|%d| ||%ld|| |%ld|\n", 100, 100000000000, 100000000000000000);
	n2 = ft_printf("ft:\t|%d| ||%ld|| |%ld|\n", 100, 100000000000, 100000000000000000);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	//long int a = (long int) (INT_MAX + 1);
	//long int b = (long int) (INT_MIN - 1);
	printf("1: %s -> INT_MAX + 1, INT_MIN - 1\n", "%d %d");
	n1 = printf("pf:\t|%d| ||%d||\n", INT_MAX + 1, INT_MIN - 1);
	n2 = ft_printf("ft:\t|%d| ||%d||\n", INT_MAX + 1, INT_MIN - 1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("1: %s -> LONG_MAX, LONG_MIN\n", "%ld %ld");
	n1 = printf("pf:\t|%ld| ||%ld||\n", LONG_MAX, LONG_MIN);
	n2 = ft_printf("ft:\t|%ld| ||%ld||\n", LONG_MAX, LONG_MIN);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("1: %s -> LONG_MAX + 1, LONG_MIN - 1\n", "%ld %ld");
	n1 = printf("pf:\t|%ld| ||%ld||\n", LONG_MAX + 1, LONG_MIN - 1);
	n2 = ft_printf("ft:\t|%ld| ||%ld||\n", LONG_MAX + 1, LONG_MIN - 1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	long int l_b = LONG_MIN;
	printf("LONG_MAX = %ld, LONG_MIN = %ld\n", LONG_MAX, LONG_MIN);
	printf("int = %zu\tshort int = %zu\tlong long int = %zu\n", sizeof(int), sizeof(long int), sizeof(long long int));
	printf("int = %zu\tshort int = %zu\tunsigned long int = %zu\n", sizeof(int), sizeof(short int), sizeof(unsigned long int));
	printf("l_b = %ld, so(l_b) = %zu, so(LONG_MIN) = %zu\n", l_b, sizeof(l_b), sizeof(LONG_MIN));
	next();

	short s_a = SHRT_MAX;
	short s_b = SHRT_MIN;

	printf("1: %s -> SHRT_MAX, SHRT_MIN\n", "%hd %hd");
	n1 = printf("pf:\t|%hd| ||%hd||\n", s_a, s_b);
	n2 = ft_printf("ft:\t|%hd| ||%hd||\n", s_a, s_b);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("sizeof: s_a = %zu\tSHRT_MAX = %zu\n\n", sizeof(s_a), sizeof(SHRT_MAX));

	s_a += 1;
	s_b -= 1;

	printf("1: %s -> SHRT_MAX + 1, SHRT_MIN - 1\n", "%d %d");
	n1 = printf("pf:\t|%d| ||%d||\n", s_a, s_b);
	n2 = ft_printf("ft:\t|%d| ||%d||\n", s_a, s_b);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	char sn_a = CHAR_MAX;
	char sn_b = CHAR_MIN;

	printf("1: %s -> CHAR_MAX, CHAR_MIN\n", "%hhd %hhd");
	n1 = printf("pf:\t|%hhd| ||%hhd||\n", sn_a, sn_b);
	n2 = ft_printf("ft:\t|%hhd| ||%hhd||\n", sn_a, sn_b);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("sizeof: sn_a = %zu\tCHAR_MAX = %zu\n\n", sizeof(sn_a), sizeof(CHAR_MAX));

	sn_a += 1;
	sn_b -= 1;

	printf("1: %s -> CHAR_MAX + 1, CHAR_MIN - 1\n", "%hhd %hhd");
	n1 = printf("pf:\t|%hhd| ||%hhd||\n", sn_a, sn_b);
	n2 = ft_printf("ft:\t|%hhd| ||%hhd||\n", sn_a, sn_b);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	unsigned long u_l = ULONG_MAX;

	printf("1: %s -> ULONG_MAX, ULONG_MAX + 1\n", "%lu %lu");
	n1 = printf("pf:\t|%lu| ||%lu||\n", u_l, u_l + 1);
	n2 = ft_printf("ft:\t|%lu| ||%lu||\n", u_l, u_l + 1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
}

void test_16(char *name)
{
	int n1, n2;

	print_name(name);

	//int	n = 0;
	//int	m = -123;

	printf("1: %s -> 0\n", "%#-03.x");
	n1 = printf("pf:\t|%#-3.x|\n", 0);
	n2 = ft_printf("ft:\t|%#-03.x|\n", 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("1: %s -> 1\n", "%#-03.x");
	n1 = printf("pf:\t|%#-3.x|\n", 1);
	n2 = ft_printf("ft:\t|%#-03.x|\n", 1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("1: %s -> 1\n", "%#x");
	n1 = printf("pf:\t|%#x|\n", 1);
	n2 = ft_printf("ft:\t|%#x|\n", 1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("1: %s -> 0xff11ff11ff88\n", "%ld");
	n1 = printf("pf:\t|%ld|\n", 0xff11ff11ff88);
	n2 = ft_printf("ft:\t|%ld|\n", 0xff11ff11ff88);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

}

void test_17(char *name)
{
	int n1 = 0;
	int n2 = 0;
	int	*a = &n1;
	int *b = &n1;
	int aa = 16;
	//int bb = 17;

	print_name(name);

	printf("Test 1: %s\n", "%p %p");
	n1 = printf("pf:\t|%p| ||%p||\n", a, b);
	n2 = ft_printf("ft:\t|%p| ||%p||\n", a, b);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("Test 2: %s -> NULL\n", "%p %p");
	n1 = printf("pf:\t|%p|\n", NULL);
	n2 = ft_printf("ft:\t|%p|\n", NULL);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("Test 2.2: %s -> NULL\n", "%12p %-12p");
	n1 = printf("pf:\t|%12p| ||%-12p||\n", NULL, NULL);
	n2 = ft_printf("ft:\t|%12p| ||%-12p||\n", NULL, NULL);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("Test 2_x: %s -> 0\n", "%x %x");
	n1 = printf("pf:\t|%x|\n", 0);
	n2 = ft_printf("ft:\t|%x|\n", 0);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("Test 3: %s\n", "%20p %20p");
	n1 = printf("pf:\t|%20p| ||%20p||\n", a, b);
	n2 = ft_printf("ft:\t|%20p| ||%20p||\n", a, b);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("Test 4: %s\n", "%-25p %-25p");
	n1 = printf("pf:\t|%-25p| ||%-25p||\n", a, b);
	n2 = ft_printf("ft:\t|%-25p| ||%-25p||\n", a, b);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("Test 5: %s -> &aa\n", "%p %p");
	n1 = printf("pf:\t|%p|\n", &aa);
	n2 = ft_printf("ft:\t|%p|\n", &aa);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	/*
	long int a01 = 123456;
	int a02 = 123456;
	char a03 = 'a';
	char *a04 = "123456"; */

	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;

	printf("Test 5: %s -> &a01, &a02, &a03, &a04\n", "%p %p %p %p");
	n1 = printf("pf:\t|%p %p %p %p|\n", &a01, &a02, &a03, &a04);
	n2 = ft_printf("ft:\t|%p %p %p %p|\n", &a01, &a02, &a03, &a04);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	/*
	printf("Test 6: %s -> 5, NULL\n", "%.*p");
	//n1 = printf("pf:\t|%.*p|\n", 5, NULL);
	n2 = ft_printf("ft:\t|%.*p|\n", 5, NULL);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next(); */

	long int a_l_min = LONG_MIN;
	long int a_l_max = LONG_MAX;

	printf("Test 7: %s -> LONG_MIN, LONG_MAX\n", "%p %p");
	n1 = printf("pf:\t|%p| ||%p||\n", &a_l_min, &a_l_max);
	n2 = ft_printf("ft:\t|%p| ||%p||\n", &a_l_min, &a_l_max);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("%zu\n", sizeof(int *));
	printf("%zu\n", sizeof(long int *));
	printf("%zu\n", sizeof(long long int *));

	printf("LONG_MIN = %ld,\n\n", ULONG_MAX, LONG_MIN);
	printf("Test 7: %s -> LONG_MIN\n", "%lx");
	n1 = printf("pf:\t|%lx|\n", LONG_MIN);
	n2 = ft_printf("ft:\t|%lx|\n", LONG_MIN);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("LONG_MAX = %ld\n\n", LONG_MAX);
	printf("Test 7: %s -> LONG_MAX\n", "%lx");
	n1 = printf("pf:\t|%lx|\n", LONG_MAX);
	n2 = ft_printf("ft:\t|%lx|\n", LONG_MAX);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("ULONG_MAX = %lu\n\n", ULONG_MAX);
	printf("Test 7: %s -> ULONG_MAX, -ULONG_MAX\n", "%lx %lx");
	n1 = printf("pf:\t|%lx| ||%lx||\n", ULONG_MAX, -ULONG_MAX);
	n2 = ft_printf("ft:\t|%lx| ||%lx||\n", ULONG_MAX, -ULONG_MAX);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("ULONG_MAX = %lu\n\n", ULONG_MAX);
	printf("Test 7: %s -> INT_MIN, INT_MAX\n", "%x %x");
	n1 = printf("pf:\t|%x| ||%x||\n", INT_MIN, INT_MAX);
	n2 = ft_printf("ft:\t|%x| ||%x||\n", INT_MIN, INT_MAX);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	float f = 214.52;   
    n1 = printf("f = %f\t",f); // 214.520004
	printf("= %d symbols\n", n1);
	n1 = printf("e = %e\t",f); // 2.145200e+02
	printf("= %d symbols\n", n1);
	n1 = printf("g = %g\t",f); // 214.52
	printf("= %d symbols\n", n1);
	
}

void test_18(char *name)
{
	int n1, n2;

	print_name(name);

	printf("1: %s -> 43\n", "%#05x");
	n1 = printf("pf:\t|%#05x|\n", 43);
	n2 = ft_printf("ft:\t|%#05x|\n", 43);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("1: %s -> 43\n", "%#05X");
	n1 = printf("pf:\t|%#05X|\n", 43);
	n2 = ft_printf("ft:\t|%#05X|\n", 43);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("1: %s -> 3254267760\n", "%lx");
	n1 = printf("pf:\t|%lx|\n", 3254267760);
	n2 = ft_printf("ft:\t|%lx|\n", 3254267760);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("1: %s -> \"3254267760\"\n", "%p");
	n1 = printf("pf:\t|%p|\n", "3254267760");
	n2 = ft_printf("ft:\t|%p|\n", "3254267760");
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	long int a_l_min = LONG_MIN;
	long int a_l_max = LONG_MAX;

	printf("Test 7: %s -> LONG_MIN, LONG_MAX\n", "%p %p");
	n1 = printf("pf:\t|%p| ||%p||\n", &a_l_min, &a_l_max);
	n2 = ft_printf("ft:\t|%p| ||%p||\n", &a_l_min, &a_l_max);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("LONG_MIN = %ld,\n\n", LONG_MIN);
	printf("Test 7: %s -> LONG_MIN\n", "%lx");
	n1 = printf("pf:\t|%lx|\n", LONG_MIN);
	n2 = ft_printf("ft:\t|%lx|\n", LONG_MIN);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	print_name("----------------------------------");

	printf("ULONG_MAX = %lu\n\n", ULONG_MAX);
	printf("Test 7: %s -> ULONG_MAX, -ULONG_MAX\n", "%lx %lx");
	n1 = printf("pf:\t|%lx| ||%lx||\n", ULONG_MAX, -ULONG_MAX);
	n2 = ft_printf("ft:\t|%lx| ||%lx||\n", ULONG_MAX, -ULONG_MAX);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("Test 7.2: %s -> LONG_MIN + 1\n", "%lx");
	n1 = printf("pf:\t|%lx|\n", LONG_MIN + 1);
	n2 = ft_printf("ft:\t|%lx|\n", LONG_MIN + 1);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	wchar_t	 empty[] = {0};
	wchar_t	 s[] = {u'ƀ', u'ɏ', u'ɐ', ' ', u'ʯ', ' ', u'ʰ', u'˿', ' ', u'ୟ', ' ', u'௫', ' ', ' ', u'࿚', 0};
	//wchar_t	 s[] = {' ', 'ƀ', 'ɏ', 'ɐ', ' ', 'ʯ', ' ', 'ʰ', '˿', ' ', 'ୟ', ' ', '௫', ' ', ' ', '࿚', 0};

/*
	printf("Test 8: %s -> \"ƀ абв\"\n", "%ls");
	n1 = printf("pf:\t|%ls|\n", "ƀ абв");
	n2 = ft_printf("ft:\t|%ls|\n", "ƀ абв");
	printf("\nRES LEN: pf: %d, ft: %d\n", n1, n2);
	next();
*/
	printf("Test 8: %s -> s\n", "%ls");
	n1 = printf("pf:\t|%ls|\n", s);
	n2 = ft_printf("ft:\t|%ls|\n", s);
	printf("\nRES LEN: pf: %d, ft: %d\n", n1, n2);
	next();

	printf("Test 9: %s -> empty\n", "%ls");
	n1 = printf("pf:\t|%ls|\n", empty);
	n2 = ft_printf("ft:\t|%ls|\n", empty);
	printf("\nRES LEN: pf: %d, ft: %d\n", n1, n2);
	next();

/*
	char *str = "Hello World";
	printf("Wierd test:\n");
	n1 = printf("pf: |%15p| ||%*.7d|| MIXED |%*.*s| TEST! ||%%%05%%%|| I |%10.7u| H%dPE %c%c %.3sSH %10.6x%-7.5X YOUR PRINTF!%%\n", &str, 8, -42, -5, 3, "woop", 15975, 0, 'I', 'T', "CRASH", 15, 15013);
	n2 = ft_printf("ft: |%15p| ||%*.7d|| MIXED |%*.*s| TEST! ||%%%05%%%|| I |%10.7u| H%dPE %c%c %.3sSH %10.6x%-7.5X YOUR PRINTF!%%\n", &str, 8, -42, -5, 3, "woop", 15975, 0, 'I', 'T', "CRASH", 15, 15013);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();

	printf("Wierd test:\n");
	n1 = printf("pf: %15p %*.7d MIXED %*.*s TEST! %%%05%%% I %10.7u H%dPE %c%c %.3sSH %10.6x%-7.5X YOUR PRINTF!%%\n", &str, 8, -42, -5, 3, "woop", 15975, 0, 'I', 'T', "CRASH", 15, 15013);
	n2 = ft_printf("ft: %15p %*.7d MIXED %*.*s TEST! %%%05%%% I %10.7u H%dPE %c%c %.3sSH %10.6x%-7.5X YOUR PRINTF!%%\n", &str, 8, -42, -5, 3, "woop", 15975, 0, 'I', 'T', "CRASH", 15, 15013);
	printf("\nRES LEN: %d, %d\n", n1, n2);
	next();
*/
	
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
	//test_07("07, d");
	//test_08("08, more d");
	//test_09("09, u");
	//test_10("10, %%");
	test_11("11, p");
	//test_12("12, x & X");
	//test_13("13, i");
	//test_14("14, n f g e");
	//test_15("15, l ll h hh");
	//test_16("16, #");
	test_17("17, p");
	//test_18("Troubleshooting");

	/*
	int n = 0;
	unsigned int m = 3254267760;

	printf("sizeof: unsigned long int = %zu, unsigned int = %zu, long int = %zu\n", sizeof(unsigned long int), sizeof(unsigned int), sizeof(long int));
	printf("Sizeof: &n = %zu, m = %zu, &m = %zu\n", sizeof(&n), sizeof(m), sizeof(&m)); */

	//printf("Before: flag_alt = %c, prec_flag = %d, prec = %zu, len = %zu, format = %c\n", arg->flag_alt, arg->prec_flag, arg->prec, arg->len, arg->format);
	
	ft_printf("\n* * * ************* TEST COMPLETED ************ * * *\n\n");
	return (0);
}
