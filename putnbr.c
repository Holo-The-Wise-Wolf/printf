/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:16:37 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/09 01:44:12 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(int nbr, char *base)
{
	int				nbr_final[100];
	unsigned int	unbr;
	int				i;
	int				count;

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

int	ft_putnbr_ptr(long int nbr, char *base)
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
