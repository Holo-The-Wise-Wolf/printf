#ifndef FT_PRINTF_TESTS_H
# define FT_PRINTF_TESTS_H

#include <assert.h>
#include <stdio.h>
#include "../ft_printf.h"

void	test_parse_flags(const char *fmt, long expected);
void	test_parse_width(const char *fmt, int expected, ...);
void	test_parse_precision(const char *fmt, int expected, ...);
void	test_parse_length(const char *fmt, char expected);
void	test_parse_specifier(const char *fmt, char expected);
void 	test_parse_arg(const char *fmt, long int ef, int ew, int ehp, int ep, char el, char es);

#endif
