/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:05:23 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/22 21:05:53 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "ft_printf_bonus.h"

void 	spec_float(t_printf *pr, t_arg *arg, t_formatted *f)
{

}

void	spec_n(t_printf *pr)
{
	int *n;

	n	= va_arg(pr->args, int *);
	*n	= pr->count;
}