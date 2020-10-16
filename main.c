#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a;
	int	b;
	unsigned int u = 4147483647;

	a = ft_printf("Hello 42 school! |%s|\n", NULL);
	b = printf("Hello 42 school! |%s|\n", NULL);
	printf("%d\n%d\n", a, b);
}
