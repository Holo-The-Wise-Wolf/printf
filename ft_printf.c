/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:00:10 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/13 18:09:29 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	t_printf_init(t_printf *pr, const char *fmt)
{
	pr->fmt	= fmt;
	pr->i = 0;
}

int		t_printf_peek(t_printf *pr, char *next)
{
	*next = pr->fmt[pr->i];

	if (*next != '\0')
		return (1);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	t_printf	pr;
	t_arg		arg;
	int			count;
	char		next;

	count = 0;
	t_printf_init(&pr, format);
	va_start(pr.args, format);
	while (t_printf_peek(&pr, &next))
	{
		pr.i += 1;
		if (next == '%')
		{
			arg = parse_arg(&pr);
			count += print_arg(&pr, &arg, count);
		}
		else
		{
			write(1, &next, 1);
			count ++;
		}
	}
	va_end(pr.args);

	return (count);
}