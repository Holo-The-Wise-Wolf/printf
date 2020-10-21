#include "ft_printf.h"

void	ft_putchar(char c)
{
	if (c != '\0')
		write(1, &c, 1);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if(s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd <= 2 && fd >= 0 && s)
		write(fd, s, ft_strlen(s));
}

int		ft_putspace(int len, char l)
{
	if (len <= 0)
		return (0);
	while (len > 0)
	{
		ft_putchar(l);
		len--;
	}
	return (0);
}

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
