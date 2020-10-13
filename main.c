#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a;
	int	b;

	a = ft_printf("%1.d\n", 0);
	b = printf("%1.d\n", 0);
	printf("%d\n%d\n", a, b);
}
