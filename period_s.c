/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   period_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:34:24 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/14 19:41:20 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    nostar_s(const char *fmt, t_printf *pr, int fmt_int, int l_fmt)
{
    int fmt_int2;

    pr->cpy = va_arg(pr->ap, char *);
    fmt_int2 = ft_getnbr(&fmt[pr->i + l_fmt + 2]);
    pr->temp = pr->temp < fmt_int2 ? pr->temp : fmt_int2;
    pr->temp = pr->cpy == NULL ? 0 : pr->temp;
    if(fmt[pr->i + 2] == '.')
        fmt_int = 0;
    if(pr->cpy == NULL && fmt_int2 >= 6)
    {
    	write(1, "(null)", 6);
    	pr->c += 6;
    	pr->temp = 6;
    }
    pr->c = pr->c + ft_putstrn(pr->cpy, fmt_int2);
    pr->c = pr->c + ft_putspace(fmt_int * (-1), pr->temp, ' ');
}

void    prec_s(const char *fmt, t_printf *pr, int fmt_int, int l_fmt)
{
    int		fmt_int2;
    int		l_fmt2;
    char	*get_n;
    int		len;

    get_n = get_nbr(&fmt[pr->i + l_fmt + 2]);
    l_fmt2 = ft_strlen(get_n);
    fmt_int2 = ft_getnbr(&fmt[pr->i + l_fmt + 2]);
    pr->cpy = va_arg(pr->ap, char *);
	pr->temp = pr->cpy == NULL ? 0 : pr->temp;
    if (pr->cpy != NULL)
    {
        len = ft_len(fmt[pr->i + l_fmt + l_fmt2 + 2], pr);
        pr->temp = len < fmt_int2 ? len : fmt_int2;
    }
	if (pr->cpy == NULL && fmt_int2 >= 6)
	{
		pr->c += 6;
		pr->temp =6;
		pr->c = pr->c + ft_putspace(fmt_int, pr->temp, ' ');
		write(1, "(null)", 6);
	}
	else
		pr->c = pr->c + ft_putspace(fmt_int, pr->temp, ' ');
    pr->c = pr->c + ft_putstrn(pr->cpy, fmt_int2);
    pr->i = pr->i + l_fmt + l_fmt2 + 2;
}

void	star(t_printf *pr, int format_int, int min, int len)
{
    int target;

    target = pr->star_int2 < len ? len : pr->star_int2;
    if (min == 1)
	{
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
		pr->c = pr->c + ft_putspace(format_int, target, ' ');
	}
	else
	{
		pr->c = pr->c + ft_putspace(format_int, target, ' ');
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
	}
}

void	dot_stringstar(t_printf *pr, int min)
{
    int len;
    int target;

	pr->cpy = va_arg(pr->ap, char *);
	len = ft_strlen(va_arg(pr->pa, char *));
	pr->star_int2 = pr->star_int2 < 0 ? len : pr->star_int2;
	target = pr->star_int2 > len ? len : pr->star_int2;
	target = pr->cpy == NULL ? 0 : target;
	if (min == 1)
	{
		pr->star_int = pr->star_int > 0 ? pr->star_int * (-1) : pr->star_int;
		if(pr->cpy == NULL && pr->star_int2 >= 6)
		{
			write(1, "(null)", 6);
			pr->c += 6;
			target = 6;
		}
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
		pr->c = pr->c + ft_putspace(pr->star_int * (-1), target, ' ');
	}
	else
	{
		if(pr->cpy == NULL && pr->star_int2 >= 6)
		{
			pr->c += 6;
			target = 6;
			pr->c = pr->c + ft_putspace(pr->star_int, target, ' ');
			write(1, "(null)", 6);
		}
		else
	        pr->c = pr->c + ft_putspace(pr->star_int, target, ' ');
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
	}
}

void	dot_string(t_printf *pr, int format_int, int min, int len)
{
    int target;

	pr->cpy = va_arg(pr->ap, char *);
	if (pr->cpy == NULL)
		;
	else if (pr->star_int != 0)
	{
		target = format_int > len ? len : format_int;
		if (min == 1)
		{
			pr->c = pr->c + ft_putstrn(pr->cpy, format_int);
			pr->c = pr->c + ft_putspace(pr->star_int, target, ' ');
		}
		else
		{
			pr->c = pr->c + ft_putspace(pr->star_int, target, ' ');
			pr->c = pr->c + ft_putstrn(pr->cpy, format_int);
		}
	}
	else if (pr->star_int2 != 0)
		star(pr, format_int, min, len);
	else if (pr->starzero == 1)
	    pr->starzero = 0;
	else
        pr->c = pr->c + ft_putstrn(pr->cpy, format_int);
}
