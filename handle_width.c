/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:01:47 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/13 18:01:48 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precstar(const char *fmt, t_printf *pr, int l_fmt, int fmt_int)
{
	int	len;

	get_argstar2(pr);
	len = ft_len(fmt[pr->i + l_fmt + 3], pr);
	if (fmt[pr->i + l_fmt + 3] == 's')
	{
	    pr->temp = len > pr->star_int2 ? len : pr->star_int2;
		pr->cpy = va_arg(pr->ap, char *);
		pr->c = pr->c + ft_putspace(fmt_int, pr->temp, ' ');
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
	}
	else
	{
        pr->temp = len > pr->star_int2 ? len : pr->star_int2;
        pr->c += ft_putspace(fmt_int, pr->temp + pr->min, ' ');
        int_neg(pr);
        pr->c += ft_putspace(pr->star_int2, len, '0');
        pr->c += pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
    }
	pr->i = pr->i + l_fmt + 3;
}

void	precis(const char *fmt, t_printf *pr, int l_fmt, int fmt_int)
{
	int		len;
	int		l2;
	int		fmt_int2;
	char	*get_n;

	get_n = get_nbr(&fmt[pr->i + l_fmt + 2]);
	l2 = ft_strlen(get_n);
	fmt_int2 = ft_getnbr(&fmt[pr->i + l_fmt + 2]);
	len = ft_len(fmt[pr->i + l_fmt + l2 + 2], pr);
	pr->temp = len > fmt_int2 ? len : fmt_int2;
	pr->c += ft_putspace(fmt_int, pr->temp + pr->min, ' ');
	int_neg(pr);
	pr->c += ft_putspace(fmt_int2, len, '0');
	if (fmt_int2 == 0 && pr->preczero == 1)
	{
		preczero(pr);
        pr->c += ft_putspace(1, 0, ' ');
    }
	else
	    pr->c += pr->ptr[check_tab(fmt[pr->i + l_fmt + l2 + 2])](pr->ap);
	pr->i = pr->i + l_fmt + l2 + 2;
}

void	h_precis(const char *fmt, t_printf *pr, int l_fmt, int fmt_int)
{
	int		l_fmt2;
	char	*get_n;

	get_n = get_nbr(&fmt[pr->i + l_fmt + 2]);
	l_fmt2 = ft_strlen(get_n);
	if (fmt[pr->i + l_fmt + 2] == '*')
		precstar(fmt, pr, l_fmt, fmt_int);
	else
	{
		if (fmt[pr->i + l_fmt + l_fmt2 + 2] == 's')
		    prec_s(fmt, pr, fmt_int, l_fmt);
		else
			precis(fmt, pr, l_fmt, fmt_int);
	}
	pr->star_int2 = 0;
	pr->min = 0;
}

void	handle_width(const char *fmt, t_printf *pr)
{
	int		format_int;
	int		len_format;
	int		len;
	char	*get_n;

	get_n = get_nbr(&fmt[pr->i + 1]);
	len_format = ft_strlen(get_n);
	format_int = ft_getnbr(&fmt[pr->i + 1]);
	if (fmt[pr->i + len_format + 1] == '.')
		h_precis(fmt, pr, len_format, format_int);
	else
	{
        len = ft_len(fmt[pr->i + len_format + 1], pr);
		pr->c = pr->c + ft_putspace(format_int, len + pr->min, ' ');
		int_neg(pr);
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + len_format + 1])](pr->ap);
		pr->i = pr->i + len_format + 1;
	}
}
