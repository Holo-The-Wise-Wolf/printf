#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a;
	int	b;

	a = ft_printf("%.*s\n", 0, "coucou");
	b = printf("%.*s\n", 0, "coucou");
	printf("%d\n%d\n", a, b);
}
