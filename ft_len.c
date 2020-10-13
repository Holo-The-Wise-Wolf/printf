/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:29:46 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/13 23:36:53 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_nbr(int nb, t_printf *pr)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		pr->preczero = 1;
		return (1);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	len_base(unsigned int nb, int b, t_printf *pr)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		pr->preczero = 1;
		return (1);
	}
	while (nb > 0)
	{
		nb = nb / b;
		i++;
	}
	return (i);
}

int	ft_len(char c, t_printf *pr)
{
	if (corresponding(c, "diu") == 1)
		return (len_nbr(va_arg(pr->pa, int), pr));
	if (corresponding(c, "xX"))
		return (len_base(va_arg(pr->pa, unsigned int), 16));
	if (corresponding(c, "p"))
		return (len_base(va_arg(pr->pa, unsigned int), 16) + 2);
	if (corresponding(c, "s") == 1)
		return (ft_strlen(va_arg(pr->pa, char *)));
	if (corresponding(c, "c%") == 1)
		return (1);
	else
		return (0);
}
