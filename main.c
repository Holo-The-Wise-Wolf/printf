#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a;
	int	b;

	a = ft_printf("%-6.*d\n", 7, -23);
	b = printf("%-6.*d\n", 7, -23);
	printf("%d\n%d\n", a, b);
}
