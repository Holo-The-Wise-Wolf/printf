/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:11:02 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/09 01:47:55 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ptr(va_list ap)
{
	long int	ptr;

	ptr = va_arg(ap, long int);
	if (ptr == 0)
	{
	    ft_putstr_fd("(nil)", 1);
	    return (5);
	}
	write(1, "0x", 2);
	return (ft_putnbr_ptr(ptr, "0123456789abcdef") + 2);
}

int	ft_printf_hexa1(va_list ap)
{
	int	nbr;
	int	count;

	nbr = va_arg(ap, int);
	count = ft_putnbr_hexa(nbr, "0123456789abcdef");
	return (count);
}

int	ft_printf_hexa2(va_list ap)
{
	int	nbr;
	int	count;

	nbr = va_arg(ap, int);
	count = ft_putnbr_hexa(nbr, "0123456789ABCDEF");
	return (count);
}

int	ft_printf_str(va_list ap)
{
	char	*str;
	int		count;

	str = va_arg(ap, char *);
	if(str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		write(1, str, ft_strlen(str));
		count = ft_strlen(str);
		return (count);
	}
}

int	ft_printf_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}
