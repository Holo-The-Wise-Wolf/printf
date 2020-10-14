#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a;
	int	b;

	a = ft_printf("percent 2 %12%\n");
	b = printf("percent 2 %12%\n");
	printf("%d\n%d\n", a, b);
}
