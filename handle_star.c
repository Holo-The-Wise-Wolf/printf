/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_star.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:52:26 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/09 01:41:01 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_stardotstar(const char *fmt, t_printf *pr)
{
	int	len;

	get_argstar(pr);
	get_argstar2(pr);
	if (fmt[pr->i + 4] == 's')
		dot_stringstar(pr, 0);
	else
	{
		len = ft_len(fmt[pr->i + 4], pr);
		if (pr->star_int > pr->star_int2)
		{
			pr->temp = pr->star_int - (pr->star_int - pr->star_int2);
			pr->c = pr->c + ft_putspace(pr->star_int, pr->star_int2, ' ');
			pr->c = pr->c + ft_putspace(pr->temp, len, '0');
			pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + 4])](pr->ap);
		}
		else
		{
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

	len = ft_len(fmt[pr->i + l_fmt + 3], pr);
	if (fmt_int < pr->star_int)
	{
		pr->c = pr->c + ft_putspace(pr->star_int, fmt_int, ' ');
		res = pr->star_int - (pr->star_int - fmt_int);
		pr->c = pr->c + ft_putspace(res, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
	}
	else
	{
		pr->c = pr->c + ft_putspace(pr->star_int, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
	}
}

void	handle_stardot(const char *fmt, t_printf *pr)
{
	int		format_int;
	int		l_fmt;
	char	*get_n;

	if (fmt[pr->i + 3] == '*')
		handle_stardotstar(fmt, pr);
	else
	{
		get_argstar(pr);
		get_n = get_nbr(&fmt[pr->i + 3]);
		l_fmt = ft_strlen(get_n);
		format_int = ft_getnbr(&fmt[pr->i + 3]);
		if (fmt[pr->i + l_fmt + 3] == 's')
			dot_string(pr, format_int, 0);
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
		pr->c += ft_putspace(pr->star_int, len, ' ');
		pr->c += pr->ptr[check_tab(format[pr->i + 2])](pr->ap);
		pr->i += 2;
	}
	pr->star_int = 0;
}
