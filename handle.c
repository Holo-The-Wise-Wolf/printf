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

void	handle_width(t_arg *arg, t_formatted *f)
{
	int	len;

	len = count_printed(f);
	if (arg->width > len && corresponding(arg->specifier, "n") != 1)
		f->spaces = arg->width - len;
	if ((arg->flags & PAD_ZERO) != 0 && arg->has_precision == 0
		&& f->left_justify != 1)
	{
		if (corresponding(arg->specifier, "diuxX%"))
		{
			f->zeroes = f->spaces;
			f->spaces = 0;
		}
	}
}

void	handle_flags(t_arg *arg, t_formatted *f)
{
	if ((arg->flags & LEFT_JUSTIFY) != 0)
		f->left_justify = 1;
	if ((arg->flags & SHOW_SIGN) != 0 && f->sign != '-')
		f->sign = '+';
	if ((arg->flags & NO_SIGN) != 0 && f->sign == '\0')
		f->sign = ' ';
	if ((arg->flags & SHOW_PREFIX) != 0)
		if (corresponding(arg->specifier, "xX"))
			if (f->content != NULL && f->content[0] != '0')
				f->prefix = arg->specifier;
}

void	handle_zeroes(t_arg *arg, t_formatted *f)
{
	int len;

	len = ft_strlen(f->content);
	if (arg->precision > 0 && arg->precision > len)
		f->zeroes = arg->precision - len;
}

void	handle_specifier(t_printf *pr, t_arg *arg, t_formatted *f)
{
	if (corresponding(arg->specifier, "diuxX"))
	{
		spec_number(pr, arg, f);
		handle_zeroes(arg, f);
	}
	else if (arg->specifier == 's')
		spec_string(pr, arg, f);
	else if (arg->specifier == 'c')
		spec_char(pr, f);
	else if (arg->specifier == 'p')
		spec_pointer(pr, f);
	else if (arg->specifier == '%')
		spec_percent(arg, f);
	else if (arg->specifier == 'n')
		spec_n(pr);
}
