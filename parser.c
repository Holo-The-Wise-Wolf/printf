/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:46:23 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/23 23:46:29 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	parse_arg(t_printf *pr)
{
	t_arg arg;

	t_arg_init(&arg);
	parse_flags(pr, &arg);
	parse_width(pr, &arg);
	parse_precision(pr, &arg);
	parse_length(pr, &arg);
	parse_specifier(pr, &arg);
	return (arg);
}

void	parse_flags(t_printf *pr, t_arg *arg)
{
	long int	flags;

	flags = 0;
	while (corresponding(pr->fmt[pr->i], "-+ #0"))
	{
		if (pr->fmt[pr->i] == '-')
			flags |= LEFT_JUSTIFY;
		if (pr->fmt[pr->i] == '+')
			flags |= SHOW_SIGN;
		if (pr->fmt[pr->i] == ' ')
			flags |= NO_SIGN;
		if (pr->fmt[pr->i] == '#')
			flags |= SHOW_PREFIX;
		if (pr->fmt[pr->i] == '0')
			flags |= PAD_ZERO;
		pr->i += 1;
	}
	arg->flags = flags;
}

void	parse_width(t_printf *pr, t_arg *arg)
{
	int			width;
	long int	flags;

	width = 0;
	flags = arg->flags;
	while (corresponding(pr->fmt[pr->i], "*0123456789"))
	{
		if (pr->fmt[pr->i] == '*')
		{
			width = va_arg(pr->args, int);
			if (width < 0)
			{
				flags |= LEFT_JUSTIFY;
				width = width * (-1);
			}
		}
		else
			width = width * 10 + (pr->fmt[pr->i] - '0');
		pr->i += 1;
	}
	arg->width = width;
	arg->flags = flags;
}

void	parse_precision(t_printf *pr, t_arg *arg)
{
	int precision;

	if (pr->fmt[pr->i] == '.')
	{
		arg->has_precision = 1;
		pr->i += 1;
	}
	precision = 0;
	while (corresponding(pr->fmt[pr->i], "*0123456789"))
	{
		if (pr->fmt[pr->i] == '*')
			precision = va_arg(pr->args, int);
		else
			precision = precision * 10 + (pr->fmt[pr->i] - '0');
		pr->i += 1;
	}
	arg->precision = precision;
}

void	parse_specifier(t_printf *pr, t_arg *arg)
{
	char	specifier;

	specifier = '\0';
	if (corresponding(pr->fmt[pr->i], "diuxXpcs%nfge"))
	{
		specifier = pr->fmt[pr->i];
		pr->i += 1;
	}
	arg->specifier = specifier;
}
