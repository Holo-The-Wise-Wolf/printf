/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_star.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:52:26 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/10 17:34:16 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_stardotstar(const char *fmt, t_printf *pr)
{
	int	len;

	get_argstar(pr);
	get_argstar2(pr);
	if (fmt[pr->i + 4] == 's')
		dot_stringstar(pr, pr->star_int > 0 ? 0 : 1);
	else
	{
		len = ft_len(fmt[pr->i + 4], pr);
        pr->temp = len > pr->star_int2 ? len : pr->star_int2;
		if (pr->star_int < 0)
		{
			pr->temp += int_neg(pr);
			pr->c = pr->c + ft_putspace(pr->star_int2, len, '0');
			pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + 4])](pr->ap);
            pr->c = pr->c + ft_putspace(pr->star_int * (-1), pr->temp, ' ');
        }
		else
		{
		    pr->c += ft_putspace(pr->star_int, pr->temp + pr->min, ' ');
		    int_neg(pr);
			pr->c = pr->c + ft_putspace(pr->star_int2, len, '0');
			pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + 4])](pr->ap);
		}
	}
	pr->i = pr->i + 4;
	pr->star_int = 0;
	pr->star_int2 = 0;
}

void	stardot(const char *fmt, t_printf *pr, int l_fmt, int fmt_int)
{
	int	len;
	int	res;

	if (pr->star_int < 0)
	{
		pr->star_int = pr->star_int * (-1);
		l_fmt = l_fmt - 1;
		minstardot(fmt, pr, l_fmt, fmt_int);
	}
	else if (fmt_int < pr->star_int)
	{
		len = ft_len(fmt[pr->i + l_fmt + 3], pr);
        res = pr->star_int - (pr->star_int - fmt_int);
		pr->c = pr->c + ft_putspace(pr->star_int, res + pr->min, ' ');
		int_neg(pr);
		pr->c = pr->c + ft_putspace(res, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
	}
	else
	{
		len = ft_len(fmt[pr->i + l_fmt + 3], pr);
		int_neg(pr);
		pr->c = pr->c + ft_putspace(pr->star_int, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
	}
}

void	handle_stardot(const char *fmt, t_printf *pr)
{
	int		format_int;
	int		l_fmt;
	char	*get_n;
	int     len;

	if (fmt[pr->i + 3] == '*')
		handle_stardotstar(fmt, pr);
	else
	{
		get_argstar(pr);
		get_n = get_nbr(&fmt[pr->i + 3]);
		l_fmt = ft_strlen(get_n);
		format_int = ft_getnbr(&fmt[pr->i + 3]);
		if (fmt[pr->i + l_fmt + 3] == 's')
		{
            len = ft_len(fmt[pr->i + l_fmt + 3], pr);
            dot_string(pr, format_int, 0, len);
        }
		else
			stardot(fmt, pr, l_fmt, format_int);
		pr->i = pr->i + l_fmt + 3;
		pr->star_int = 0;
	}
}

void	handle_star(const char *format, t_printf *pr)
{
	int	len;

	if (format[pr->i + 2] == '.')
		handle_stardot(format, pr);
	else
	{
		get_argstar(pr);
		len = ft_len(format[pr->i + 2], pr);
		if (pr->star_int < 0)
		{
		    len += int_neg(pr);
			pr->c += pr->ptr[check_tab(format[pr->i + 2])](pr->ap);
			pr->c += ft_putspace(pr->star_int * (-1), len, ' ');
		}
		else
		{
			pr->c += ft_putspace(pr->star_int, len + pr->min, ' ');
            int_neg(pr);
			pr->c += pr->ptr[check_tab(format[pr->i + 2])](pr->ap);
		}
		pr->i += 2;
	}
	pr->star_int = 0;
}
