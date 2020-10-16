/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:38:05 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/09 01:34:24 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mindot(const char *fmt, t_printf *pr, int l_fmt, int fmt_int)
{
	int		fmt_int2;
	int		l2;
	char	*get_n;
	int		len;

	get_n = get_nbr(&fmt[pr->i + l_fmt + 2]);
	l2 = ft_strlen(get_n);
	fmt_int2 = ft_getnbr(&fmt[pr->i + l_fmt + 2]);
	len = ft_len(fmt[pr->i + l_fmt + l2 + 2], pr);
	fmt_int = fmt_int * (-1);
	pr->temp = len > fmt_int2 ? len : fmt_int2;
	pr->temp += int_neg(pr);
	pr->c = pr->c + ft_putspace(fmt_int2, len, '0');
	if (fmt_int2 == 0 && pr->preczero == 1)
	{
		preczero(pr);
		pr->temp = 0;
	}
	else
		pr->c += pr->ptr[check_tab(fmt[pr->i + l_fmt + l2 + 2])](pr->ap);
	pr->c = pr->c + ft_putspace(fmt_int, pr->temp, ' ');
}

void	h_mindotstar(const char *fmt, t_printf *pr, int l_fmt, int f_i)
{
    int len;
    int res;
    int n;

    get_argstar2(pr);
    n = f_i * (-1);
    len = ft_len(fmt[pr->i + l_fmt + 3], pr);
    if (fmt[pr->i + l_fmt + 3] == 's')
        dot_string(pr, n, 1, len);
    else
    {
        res = len > pr->star_int2 ? len : pr->star_int2;
        res += int_neg(pr);
        pr->c = pr->c + ft_putspace(pr->star_int2, len, '0');
        if (pr->star_int2 == 0 && pr->preczero == 1)
        {
        	preczero(pr);
        	res = 0;
        }
        else
            pr->c += pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
        pr->c += ft_putspace(n, res, ' ');
    }
	pr->i = pr->i + l_fmt + 3;
	pr->star_int2 = 0;
}

void	h_mindot(const char *fmt, t_printf *pr, int l_fmt, int fmt_int)
{
	int		l2;
	char	*get_n;

	if (fmt[pr->i + l_fmt + 2] == '*')
		h_mindotstar(fmt, pr, l_fmt, fmt_int);
	else
	{
		get_n = get_nbr(&fmt[pr->i + l_fmt + 2]);
		l2 = ft_strlen(get_n);
		if (fmt[pr->i + l_fmt + l2 + 2] == 's')
		{
            pr->temp = ft_len(fmt[pr->i + l_fmt + l2 + 2], pr);
            nostar_s(fmt, pr, fmt_int, l_fmt);
        }
		else
			mindot(fmt, pr, l_fmt, fmt_int);
		pr->i = pr->i + l_fmt + l2 + 2;
	}
}

void	handle_minstar(const char *format, t_printf *pr)
{
	int	star_int;
	int	len;

	if (format[pr->i + 3] == '.')
		handle_minstardot(format, pr);
	else
	{
		star_int = va_arg(pr->ap, int);
		va_arg(pr->pa, int);
		if(star_int < 0)
			star_int = star_int * (-1);
		len = ft_len(format[pr->i + 3], pr);
        len += int_neg(pr);
		pr->c += pr->ptr[check_tab(format[pr->i + 3])](pr->ap);
		pr->c += ft_putspace(star_int, len, ' ');
		pr->i += 3;
	}
}

void	handle_minus(const char *fmt, t_printf *pr)
{
	int		format_int;
	int		len_format;
	int		len;
	char	*get_n;

	if (fmt[pr->i + 2] == '0')
		pr->i += 1;
	if (fmt[pr->i + 2] == '*')
		handle_minstar(fmt, pr);
	else
	{
		get_n = get_nbr(&fmt[pr->i + 1]);
		len_format = ft_strlen(get_n);
		format_int = ft_getnbr(&fmt[pr->i + 1]);
		if (fmt[pr->i + len_format + 1] == '.')
			h_mindot(fmt, pr, len_format, format_int);
		else
		{
			len = ft_len(fmt[pr->i + len_format + 1], pr);
			len += int_neg(pr);
			pr->c += pr->ptr[check_tab(fmt[pr->i + len_format + 1])](pr->ap);
			pr->c += ft_putspace((format_int * (-1)), len, ' ');
			pr->i += len_format + 1;
		}
	}
}
