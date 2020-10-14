/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:16:37 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/13 23:26:34 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_hexa(int nbr, char *base)
{
	int				nbr_final[100];
	unsigned int	unbr;
	int				i;
	int				count;

	i = 0;
	unbr = nbr;
	if(nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else
	{
		while (unbr)
		{
			nbr_final[i] = unbr % 16;
			unbr = unbr / 16;
			i++;
		}
		count = i;
		while (--i >= 0)
			ft_putchar(base[nbr_final[i]]);
		return (count);
	}
}

int		ft_putnbr_ptr(long int nbr, char *base)
{
	int					nbr_final[100];
	unsigned long int	unbr;
	int					i;
	int					count;

	i = 0;
	unbr = nbr;
	while (unbr)
	{
		nbr_final[i] = unbr % 16;
		unbr = unbr / 16;
		i++;
	}
	count = i;
	while (--i >= 0)
		ft_putchar(base[nbr_final[i]]);
	return (count);
}

void	ft_putnbr(long int x)
{
	if (x < 0)
	{
		x = -x;
	//	write(1, "-", 1);
	}
	if (x > 9)
		ft_putnbr(x / 10);
	write(1, &"0123456789"[x % 10], 1);
}

void	ft_putunbr(unsigned int x)
{
	if (x > 9)
		ft_putnbr(x / 10);
	write(1, &"0123456789"[x % 10], 1);
}
