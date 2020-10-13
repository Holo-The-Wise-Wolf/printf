#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a;
	int	b;

	a = ft_printf("%.0x\n", 0);
	b = printf("%.0x\n", 0);
	printf("%d\n%d\n", a, b);
}
