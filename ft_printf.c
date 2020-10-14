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

void	init_struct(t_printf *pr)
{
	pr->star = 0;
	pr->star_int = 0;
	pr->star_int2 = 0;
	pr->c = 0;
	pr->i = 0;
	pr->temp = 0;
	pr->preczero = 0;
	pr->min = 0;
	pr->len = -1;
}

void	fill_tab(t_printf *pr)
{
	pr->ptr[0] = &ft_printf_str;
	pr->ptr[1] = &ft_printf_nbr;
	pr->ptr[2] = &ft_printf_nbr;
	pr->ptr[3] = &ft_printf_char;
	pr->ptr[4] = &ft_printf_unbr;
	pr->ptr[5] = &ft_printf_hexa1;
	pr->ptr[6] = &ft_printf_hexa2;
	pr->ptr[7] = &ft_printf_ptr;
}

void	formating(const char *fmt, t_printf *pr)
{
	char	*get_n;
	int		len_format;

	if (fmt[pr->i + 1] == '.')
		handle_dot(fmt, pr);
	else
	{
		get_n = get_nbr(&fmt[pr->i + 1]);
		len_format = ft_strlen(get_n);
		if (fmt[pr->i + 2] == '*')
			pr->star = 1;
		if (get_n[0] == '0'
			&& corresponding(fmt[pr->i + len_format + pr->star + 1], "sc") != 1)
			handle_zero(fmt, pr);
		else if (fmt[pr->i + 1] == '-')
			handle_minus(fmt, pr);
		else if (check_tab(fmt[pr->i + len_format + 1]) == -1
			&& fmt[pr->i + len_format + 1] != '.')
		{
			ft_printf("lul");
			pr->c++;
			ft_putchar('%');
		}
		else
			handle_width(fmt, pr);
	}
}

void	handle_percent(const char *format, t_printf *pr)
{
	if (corresponding(format[pr->i + 1], "*") == 1)
		handle_star(format, pr);
	else if (corresponding(format[pr->i + 1], ".-0123456789") == 1)
		formating(format, pr);
	else if (format[pr->i + 1] == '%')
	{
		ft_putchar('%');
		pr->c++;
		pr->i++;
	}
	else if (check_tab(format[pr->i + 1]) != -1)
	{
	    ft_len(format[pr->i + 1], pr);
	    int_neg(pr);
		pr->c += pr->ptr[check_tab(format[pr->i + 1])](pr->ap);
		pr->i++;
	}
	else if (check_tab(format[pr->i + 1]) == -1
	&& corresponding(check_tab(format[pr->i + 1]), ".*-0123456789") != 1)
	{
		pr->c++;
		ft_putchar('%');
	}
}

int		ft_printf(const char *format, ...)
{
	t_printf	*pr;

	pr = malloc(sizeof(t_printf));
	va_start(pr->ap, format);
	va_start(pr->pa, format);
	init_struct(pr);
	fill_tab(pr);
	while (format[pr->i] != '\0')
	{
		if (format[pr->i] == '%')
			handle_percent(format, pr);
		else
		{
			pr->c++;
			ft_putchar(format[pr->i]);
		}
		pr->i++;
	}
	va_end(pr->pa);
	va_end(pr->ap);
	return (pr->c);
}
