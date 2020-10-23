/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:37:10 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/23 23:37:29 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_ptr(long int nb)
{
	int					i;
	long unsigned int	unb;

	unb = nb;
	i = 0;
	if (unb == 0)
		return (0);
	while (unb > 0)
	{
		unb = unb / 16;
		i++;
	}
	return (i);
}

int		len_base(int nb, int b)
{
	int				i;
	unsigned int	unb;

	unb = nb;
	i = 0;
	if (unb == 0)
		return (1);
	while (unb > 0)
	{
		unb = unb / b;
		i++;
	}
	return (i);
}

char	*itoa_base_ptr(long int value, int base)
{
	int						size;
	long unsigned int		nbr;
	char					*result;
	char					*ref_base;

	nbr = value;
	ref_base = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	size = len_ptr(nbr);
	size += 2;
	if (!(result = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	result[size--] = '\0';
	result[0] = '0';
	result[1] = 'x';
	while (nbr > 0)
	{
		result[size--] = ref_base[nbr % base];
		nbr /= base;
	}
	return (result);
}

char	*ft_itoa_base(int value, int base, char spec)
{
	int					size;
	unsigned int		nbr;
	char				*result;
	char				*ref_base;

	if (value < 0 && (spec == 'd' || spec == 'i'))
		value = -value;
	nbr = value;
	if (spec == 'X')
		ref_base = "0123456789ABCDEF";
	else
		ref_base = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	size = len_base(nbr, base);
	if (!(result = (char*)malloc(sizeof(*result) * (size + 1))))
		return (NULL);
	result[size--] = '\0';
	result[0] = (value < 0 ? '-' : '0');
	while (nbr > 0)
	{
		result[size--] = ref_base[nbr % base];
		nbr /= base;
	}
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i])
		i++;
	if (dstsize <= 0)
		return (i);
	if (dstsize > i)
		dstsize = i + 1;
	while (*src && dstsize-- - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (i);
}
