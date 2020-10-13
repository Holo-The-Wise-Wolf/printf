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
		pr->cpy = va_arg(pr->ap, char *);
		va_arg(pr->pa, char *);
		if (pr->star_int2 < fmt_int)
			pr->c = pr->c + ft_putspace(fmt_int, pr->star_int2, ' ');
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
	}
	else if (pr->star_int2 < fmt_int)
	{
		pr->c = pr->c + ft_putspace(fmt_int, pr->star_int2, ' ');
		fmt_int = fmt_int - (fmt_int - pr->star_int2);
		pr->c = pr->c + ft_putspace(fmt_int, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
	}
	else
	{
		pr->c = pr->c + ft_putspace(pr->star_int2, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
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
	if (fmt_int2 < fmt_int)
	{
		if (fmt_int2 == 0)
			fmt_int2 = 1;
		pr->c = pr->c + ft_putspace(fmt_int, fmt_int2, ' ');
		fmt_int = fmt_int - (fmt_int - fmt_int2);
		pr->c = pr->c + ft_putspace(fmt_int, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + l2 + 2])](pr->ap);
	}
	else
	{
		pr->c = pr->c + ft_putspace(fmt_int2, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + l2 + 2])](pr->ap);
	}
	pr->i = pr->i + l_fmt + l2 + 2;
}

void	h_precis(const char *fmt, t_printf *pr, int l_fmt, int fmt_int)
{
	int		l_fmt2;
	int		fmt_int2;
	char	*get_n;

	get_n = get_nbr(&fmt[pr->i + l_fmt + 2]);
	l_fmt2 = ft_strlen(get_n);
	fmt_int2 = ft_getnbr(&fmt[pr->i + l_fmt + 2]);
	if (fmt[pr->i + l_fmt + 2] == '*')
		precstar(fmt, pr, l_fmt, fmt_int);
	else
	{
		if (fmt[pr->i + l_fmt + l_fmt2 + 2] == 's')
		{
			pr->cpy = va_arg(pr->ap, char *);
			va_arg(pr->pa, char *);
			if (fmt_int2 < fmt_int)
				pr->c = pr->c + ft_putspace(fmt_int, fmt_int2, ' ');
			pr->c = pr->c + ft_putstrn(pr->cpy, fmt_int2);
			pr->i = pr->i + l_fmt + l_fmt2 + 2;
		}
		else
			precis(fmt, pr, l_fmt, fmt_int);
	}
	pr->star_int2 = 0;
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
	len = ft_len(fmt[pr->i + len_format + 1], pr);
	if (fmt[pr->i + len_format + 1] == '.')
		h_precis(fmt, pr, len_format, format_int);
	else
	{
		pr->c = pr->c + ft_putspace(format_int, len, ' ');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + len_format + 1])](pr->ap);
		pr->i = pr->i + len_format + 1;
	}
}
