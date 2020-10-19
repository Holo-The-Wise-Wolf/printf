#include "tests.h"

void	test_parse_flags(const char *fmt, long expected)
{
	t_printf	pr;
	t_arg 		arg;
	t_printf_init(&pr, fmt);

	parse_flags(&pr, &arg);
	long result =  arg.flags;
	printf("%ld\t==\t%ld\n", result, expected);
	assert(result == expected);
	printf("\t=> OK!\n");
}

void	test_parse_width(const char *fmt, int expected, ...)
{
	t_printf	pr;
	t_arg 		arg;
	t_printf_init(&pr, fmt);
	va_start(pr.args, expected);

	parse_width(&pr, &arg);
	int result = arg.width;
	printf("%d\t==\t%d\n", result, expected);
	assert(result == expected);
	printf("\t=> OK!\n");
	va_end(pr.args);
}

void	test_parse_precision(const char *fmt, int expected, ...)
{
	t_printf	pr;
	t_arg 		arg;
	t_printf_init(&pr, fmt);

	va_start(pr.args, expected);
	parse_precision(&pr, &arg);
	int result = arg.precision;
	printf("%d\t==\t%d\n", result, expected);
	assert(result == expected);
	printf("\t=> OK!\n");
	va_end(pr.args);
}

void	test_parse_length(const char *fmt, char expected)
{
	t_printf	pr;
	t_arg 		arg;
	t_printf_init(&pr, fmt);

	parse_length(&pr, &arg);
	char result =  arg.length;
	printf("%c\t==\t%c\n", result, expected);
	assert(result == expected);
	printf("\t=> OK!\n");
}

void	test_parse_specifier(const char *fmt, char expected)
{
	t_printf	pr;
	t_arg 		arg;
	t_printf_init(&pr, fmt);

	parse_specifier(&pr, &arg);
	char result =  arg.specifier;
	printf("%c\t==\t%c\n", result, expected);
	assert(result == expected);
	printf("\t=> OK!\n");
}

void 	test_parse_arg(const char *fmt, long int ef, int ew, int ehp, int ep, char el, char es)
{
	t_printf	pr;
	t_arg		arg;
	t_printf_init(&pr, fmt);

	parse_flags(&pr, &arg);
	long int flags = arg.flags;
	assert(arg.flags == ef);
	parse_width(&pr, &arg);
	int width = arg.width;
	assert(arg.width == ew);
	parse_precision(&pr, &arg);
	int has_precision = arg.has_precision;
	assert(arg.has_precision == ehp);
	int precision = arg.precision;
	assert(arg.precision == ep);
	parse_length(&pr, &arg);
	char length =  arg.length;
	assert(arg.length == el);
	parse_specifier(&pr, &arg);
	char specifier =  arg.specifier;
	assert(arg.specifier == es);

	printf("flags = %li\nwidth = %i\nhas_precision = %i\nprecision = %i\nlength = %c\nspecifier = %c\n", flags, width, has_precision, precision, length, specifier);
}
