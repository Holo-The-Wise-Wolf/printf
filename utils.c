#include "ft_printf.h"

int		corresponding(char c, char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}

	return (0);
}
