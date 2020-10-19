#include "tests.h"

void	test_parse_flags(const char *fmt, long expected)
{
	t_printf	pr;
	t_arg 		arg;
	t_printf_init(&pr, fmt);

	parse_flags(&pr, &arg);
	long result =  arg.flags;
	printf("%d\t==\t%d\n", result, expected);
	assert(result == expected);
	printf("\t=> OK!\n");
}

void	test_parse_width(const char *fmt, int expected, ...)
{
	t_printf	pr;
	t_arg 		arg;
	t_printf_init(&pr, fmt);
	va_start(pr.args, fmt);

	parse_width(&pr, &arg);
	int result = arg.width;
	printf("%d\t==\t%d\n", result, expected);
	assert(result == expected);
	printf("\t=> OK!\n");
	va_end(pr.args);
}