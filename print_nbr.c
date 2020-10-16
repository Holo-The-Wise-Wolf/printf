/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:14:49 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/09 01:51:31 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_nbr(va_list ap)
{
	int			nbr;
	long int	x;
	int			count;

	nbr = va_arg(ap, int);
	x = nbr;
	count = 0;
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		count++;
		nbr /= 10;
	}
	if (x < 0)
	{
		x = -x;
		//write(1, "-", 1);
		count++;
	}
	if (x > 9)
		ft_putnbr(x / 10);
	write(1, &"0123456789"[x % 10], 1);
	return (count);
}

int	ft_printf_unbr(va_list ap)
{
	unsigned int	unbr;
	unsigned int	unbr2;
	int		    	nbr;
	int			    count;

	nbr = va_arg(ap, int);
	unbr = nbr;
	unbr2 = unbr;
	count = 0;
	if (unbr2 == 0)
		count++;
	while (unbr2 != 0)
	{
		count++;
		unbr2 /= 10;
	}
	if (unbr > 9)
		ft_putunbr(unbr / 10);
	write(1, &"0123456789"[unbr % 10], 1);
	return (count);
}
