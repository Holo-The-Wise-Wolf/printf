#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a;
	int	b;
	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;


	a = ft_printf("%-27p\n", &a01);
	b = printf("%-27p\n",&a01);
	printf("%d\n%d\n", a, b);
}
