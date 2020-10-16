#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a;
	int	b;
	unsigned int u = 4147483647;

	a = ft_printf("%-*.*d\n", 2, 0, -4);
	b = printf("%-*.*d\n", 2, 0, -4);
	printf("%d\n%d\n", a, b);
}
