#include "tests.h"

void	test_parse_flags(const char *fmt, long expected)
{
	t_printf	pr;
	t_printf_init(&pr, fmt);

	long result =  parse_flags(&pr);

	printf("%d\t==\t%d\t", result, expected);
	assert(result == expected);
	printf("\t=> OK!");
}
