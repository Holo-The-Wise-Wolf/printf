#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a;
	int	b;

	a = ft_printf("%-7.5s\n", "yolo");
	b = printf("%-7.5s\n", "yolo");
	printf("%d\n%d\n", a, b);
}
