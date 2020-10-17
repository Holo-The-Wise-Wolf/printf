/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_neg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 02:29:57 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/14 02:32:37 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int int_neg(t_printf *pr)
{
	if (pr->min == 1)
	{
	    ft_putchar ('-');
		pr->min = 0;
		return (1);
	}
	return (0);
}
