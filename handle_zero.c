/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:48:01 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/09 01:42:49 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_zerostar(const char *format, t_printf *pr)
{
    int len;

	get_argstar2(pr);
	len = ft_len(format[pr->i + 3], pr);
    if (pr->star_int2 == 0 && pr->preczero == 1)
    {
        pr->preczero = 0;
        va_arg(pr->ap, int);
    }
	else if (format[pr->i + 3] == 's')
	{
        pr->starzero = 1;
        dot_string(pr, 1, 0, len);
    }
	else
	{
		len = ft_len(format[pr->i + 3], pr);
		len += int_neg(pr);
		pr->c += ft_putspace(pr->star_int2, len, '0');
		pr->c += pr->ptr[check_tab(format[pr->i + 3])](pr->ap);
	}
	pr->i += 3;
	pr->star_int2 = 0;
}

void	handle_zero(const char *fmt, t_printf *pr)
{
	int		format_int;
	int		l_fmt;
	int		len;
	char	*get_n;

    get_n = get_nbr(&fmt[pr->i + 1]);
    l_fmt = ft_strlen(get_n);
    format_int = ft_getnbr(&fmt[pr->i + 1]);
	if (fmt[pr->i + 2] == '*')
		handle_zerostar(fmt, pr);
	else
	{
        len = ft_len(fmt[pr->i + l_fmt + 1], pr);
		len += int_neg(pr);
		pr->c = pr->c + ft_putspace(format_int, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 1])](pr->ap);
		pr->i = pr->i + l_fmt + 1;
	}
}
