#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a;
	int	b;

	a = ft_printf("%.3s%.2s", "holla", "bitch");
	b = printf("%.3s%.2s", "holla", "bitch");
	printf("%d\n%d\n", a, b);
}
