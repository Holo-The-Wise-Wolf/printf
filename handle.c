/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:16:51 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/20 16:17:22 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		spec_number(t_printf *pr, t_arg *arg, t_formatted *f)
{
	int temp;
	int len;

	temp = va_arg(pr->args, int);
	if (corresponding(arg->specifier, "diu"))
	{
		len = len_base(temp, 10);
		ft_itoa_base(temp, 10);
	}
	if (arg->specifier == 'x')
	{
		len = len_base(temp, 16);
		ft_itoa_base(temp, 16);
	}
	if (arg->specifier == 'X')
	{
		len = len_base(temp, 16);
		ft_itoa_baseX(temp, 16);
	}
}

int		spec_string(t_printf *pr, t_arg	*arg, t_formatted *f)
{

}

int		spec_char(t_printf *pr, t_arg	*arg, t_formatted *f)
{

}

int		spec_pointer(t_printf *pr, t_arg	*arg, t_formatted *f)
{

}

void 	handle_specifier(t_printf *pr, t_arg *arg, t_formatted *f)
{
	int	len;

	if (corresponding(arg->specifier, "diuxX"))
		len = spec_number(&pr, &arg, &f);
	else if (arg->specifier == 's')
		len = spec_string(&pr, &arg, &f);
	else if (arg->specifier == 'c')
		len = spec_char(&pr, &arg, &f);
	else_if (arg->specifier == 'p')
		len = spec_pointer(&arg, &f);
	handle_precision(&arg, &f, len);
}
