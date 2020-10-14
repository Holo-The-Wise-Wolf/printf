/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:48:26 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/09 20:52:27 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd <= 2 && fd >= 0 && s)
		write(fd, s, ft_strlen(s));
}

char	*ft_strdup(const char *src)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!(cpy = malloc(ft_strlen(src) * (sizeof(char)) + 1)))
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int		ft_putstrn(const char *src, int n)
{
	int	i;
	int	c;
	int	j;

	i = 0;
	c = 0;
	j = 0;
	if (!src)
		return (0);
	while (src[i])
		i++;
	if (n <= 0)
		return (0);
	if (n > i)
		n = i + 1;
	while (src[j] && n--)
	{
		ft_putchar(src[j]);
		j++;
		c++;
	}
	return (c);
}
