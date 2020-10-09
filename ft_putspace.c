/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:06:53 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/09 01:07:33 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putspace(int len1, int len2, char l)
{
	int	res;
	int	count;

	res = len1 - len2;
	count = 0;
	if (res <= 0)
		return (0);
	while (res > 0)
	{
		ft_putchar(l);
		res--;
		count++;
	}
	return (count);
}
