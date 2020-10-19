#ifndef FT_PRINTF_TESTS_H
# define FT_PRINTF_TESTS_H

#include <assert.h>
#include <stdio.h>
#include "../ft_printf.h"

void	test_parse_flags(const char *fmt, long expected);
void	test_parse_width(const char *fmt, int expected, ...);

#endif
