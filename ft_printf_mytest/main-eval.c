#include <stdio.h>

#include <unistd.h>
#include "ft_printf.h"

int main()
{
	int n;
	int n2;
	n = printf("HELLOWORLD\n");
	n2 = ft_printf("HELLOWORLD\n");
	n2 = printf("%d == %d\n", n, n2);

	printf("\033[31m###########\033[0m\n");
	n = printf("%s\n", "l");
	n2 = ft_printf("%s\n", "l");
	n2 = printf("%d == %d\n", n, n2);

	printf("\033[31m###########\033[0m\n");
	n = printf("%d %d %u %f\n", 0, 0 ,0 ,0.0);
	n2 = ft_printf("%d %d %u %f\n", 0, 0 ,0 ,0.0);
	n2 = printf("%d == %d\n", n, n2);

	printf("\033[31m###########\033[0m\n");
	n = printf("%+10%\n");
	n2 = ft_printf("%+10%\n");
	printf("%d == %d\n", n, n2);



	printf("\033[31m###########\033[0m\n");
	n = printf("%+10.8d\n", 30000);
	n2 = ft_printf("%+10.8d\n", 30000);
	printf("%d == %d\n", n, n2);



	char *s = "lol";
	printf("\033[32m###########\033[0m\n");
	n = printf("%10p\n", s);
	n2 = ft_printf("%10p\n", s);
	printf("%d == %d\n", n, n2);


	printf("\033[32m###########\033[0m\n");
	n = printf("%-*.*s\n",10, -1,s);
	n2 = ft_printf("%-*.*s\n",10,  -1, s);
	printf("%d == %d\n", n, n2);



	printf("\033[33m###########\033[0m\n");
	n = printf("|%-*.*s|\n",10, 0,s);
	n2 = ft_printf("|%-*.*s|\n",10,  0, s);
	printf("%d == %d\n", n, n2);


	printf("\033[33m###########\033[0m\n");
	n = printf("|%-*.s|\n",10, s);
	n2 = ft_printf("|%-*.s|\n",10, s);
	printf("%d == %d\n", n, n2);

	printf("\033[34m###########\033[0m\n");
	n = printf("|%lx|\n",10000000000);
	n2 = ft_printf("|%lx|\n",10000000000);
	printf("%d == %d\n", n, n2);


	printf("\033[34m###########\033[0m\n");
	n = printf("|%*li|\n",-10, 10000000000);
	n2 = ft_printf("|%*li|\n",-10, 10000000000);
	printf("%d == %d\n", n, n2);

	printf("\033[34m###########\033[0m\n");
	n = printf("|%*x|\n",-10, 10000000000);
	n2 = ft_printf("|%*x|\n",-10, 10000000000);
	printf("%d == %d\n", n, n2);


	printf("\033[34m###########\033[0m\n");
	n = printf("|%*X|\n",-10, -10000000000);
	n2 = ft_printf("|%*X|\n",-10, -10000000000);
	printf("%d == %d\n", n, n2);



	printf("\033[34m###########\033[0m\n");
	n = printf("|% *lc      %s      %f   %10c %2p |\n",-10, 98, "lol", 21.354, 'w', &strlen);
	n2 = ft_printf("|% *lc      %s      %f   %10c %2p |\n",-10, 98, "lol", 21.354, 'w', &strlen);
	printf("%d == %d\n", n, n2);

	sleep(30);

}
