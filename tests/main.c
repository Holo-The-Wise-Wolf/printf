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
}
