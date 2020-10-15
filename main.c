#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a;
	int	b;

	a = ft_printf("%-4x", 9648627);
	b = printf("%-4x", 9648627);
	printf("%d\n%d\n", a, b);
}
