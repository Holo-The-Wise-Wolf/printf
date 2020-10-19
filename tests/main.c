#include "tests.h"

//void	test_flags()
//{
//	long flags = 0;
//
//	flags |= SHOW_SIGN;
//	flags |= LEFT_JUSTIFY;
//	flags |= NO_SIGN;
//
//	printf("Flags: %d\n", flags);
//	printf("%0*0d\n", 3, 4, 12);
//	printf("%0#+10d\n", 256);
//	long is_show_sign = flags & SHOW_SIGN;
//	if (flags & SHOW_SIGN == SHOW_SIGN) {
//		printf("C'est un show_sign! %d\n", is_show_sign);
//	}
//	long is_pad_zero = flags & PAD_ZERO;
//	if (flags & PAD_ZERO) {
//		printf("C'est un pad_zero! %d\n", is_pad_zero);
//	}
//}

int main()
{
	test_parse_flags("-",	LEFT_JUSTIFY);
	test_parse_flags("+",	SHOW_SIGN);
	test_parse_flags("+#",	SHOW_SIGN | SHOW_PREFIX);
	test_parse_width("64", 64);
	test_parse_width("*", 18, -18);
	test_parse_width("*", 15, 15);
	test_parse_precision(".22", 22);
	test_parse_precision(".*", 12, 12);
	test_parse_precision("*", -32, -32);
	test_parse_precision(".*", -240, -240);
	test_parse_length("l", 'l');
	test_parse_length("h", 'h');
	test_parse_specifier("d", 'd');
	test_parse_arg("-0126.36ld", LEFT_JUSTIFY | PAD_ZERO, 126, 1, 36, 'l', 'd');
}
