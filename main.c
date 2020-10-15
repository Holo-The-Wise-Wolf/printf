#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a;
	int	b;

	a = ft_printf("%-8.3i", 8375);
	b = printf("%-8.3i", 8375);
	printf("%d\n%d\n", a, b);
}
