/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:00:10 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/23 23:03:01 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char		next;

	t_printf_init(&pr, format);
	va_start(pr.args, format);
	while (t_printf_peek(&pr, &next))
	{
		pr.i += 1;
		if (next == '%')
		{
			arg = parse_arg(&pr);
			pr.count += print_arg(&pr, &arg);
		}
		else
		{
			write(1, &next, 1);
			pr.count++;
		}
	}
	va_end(pr.args);
	return (pr.count);
}
