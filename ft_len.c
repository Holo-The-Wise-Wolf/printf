/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:29:46 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/14 00:36:12 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	len_ptr(long int nb)
{
	int                 i;
	long unsigned int   unb;

	unb = nb;
	i = 0;
	if (unb == 0)
		return (5);
	while (unb > 0)
	{
		unb = unb / 16;
		i++;
	}
	return (i + 2);
}

int	len_nbr(int nb, t_printf *pr)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
	    //ft_printf("lul");
		pr->preczero = 1;
		return (1);
	}
	if (nb < 0)
	{
	    pr->min = 1;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	len_base(int nb, int b, t_printf *pr)
{
	int             i;
	unsigned int    unb;

	unb = nb;
	i = 0;
	if (unb == 0)
	{
		pr->preczero = 1;
		return (1);
	}
	while (unb > 0)
	{
		unb = unb / b;
		i++;
	}
	return (i);
}

int	ft_len(char c, t_printf *pr)
{
	if (corresponding(c, "di") == 1)
		return (len_nbr(va_arg(pr->pa, int), pr));
	if (corresponding(c, "u") == 1)
	    return (len_base(va_arg(pr->pa, int), 10, pr));
	if (corresponding(c, "xX"))
		return (len_base(va_arg(pr->pa, int), 16, pr));
	if (corresponding(c, "p"))
		return (len_ptr(va_arg(pr->pa, long int)));
	if (corresponding(c, "s") == 1)
		return (ft_strlen(va_arg(pr->pa, char *)));
	if (corresponding(c, "c%") == 1)
		return (1);
	else
		return (0);
}
