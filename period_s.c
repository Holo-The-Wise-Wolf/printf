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
    if (pr->cpy != NULL)
    {
        len = ft_len(fmt[pr->i + l_fmt + l_fmt2 + 2], pr);
        pr->temp = len < fmt_int2 ? len : fmt_int2;
    }
    else if (pr->cpy == NULL)
        pr->temp = 0;
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
	target = pr->star_int2 > len ? len : pr->star_int2;
	if (min == 1)
	{
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
		pr->c = pr->c + ft_putspace(pr->star_int * (-1), target, ' ');
	}
	else
	{
	    pr->c = pr->c + ft_putspace(pr->star_int, target, ' ');
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
	}
}

void	dot_string(t_printf *pr, int format_int, int min, int len)
{
    int target;

	pr->cpy = va_arg(pr->ap, char *);
	if (pr->star_int != 0)
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
