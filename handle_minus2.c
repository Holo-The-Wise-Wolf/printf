/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_minus2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:44:22 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/09 01:41:43 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minstardot(const char *fmt, t_printf *pr, int l_fmt, int fmt_i)
{
	int	len;
	int	res;

	len = ft_len(fmt[pr->i + l_fmt + 4], pr);
	if (fmt_i < pr->star_int)
	{
		res = pr->star_int - (pr->star_int - fmt_i);
		pr->c = pr->c + ft_putspace(res, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 4])](pr->ap);
		pr->c = pr->c + ft_putspace(pr->star_int, fmt_i, ' ');
	}
	else
	{
		pr->c = pr->c + ft_putspace(fmt_i, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 4])](pr->ap);
	}
}

void	handle_minstardot(const char *fmt, t_printf *pr)
{
	int		format_int;
	int		l_fmt;
	char	*get_n;

	if (fmt[pr->i + 4] == '*')
		handle_minstardotstar(fmt, pr);
	else
	{
		get_argstar(pr);
		get_n = get_nbr(&fmt[pr->i + 4]);
		l_fmt = ft_strlen(get_n);
		format_int = ft_getnbr(&fmt[pr->i + 4]);
		if (fmt[pr->i + l_fmt + 4] == 's')
			dot_string(pr, format_int, 1);
		else
			minstardot(fmt, pr, l_fmt, format_int);
		pr->i = pr->i + l_fmt + 4;
		pr->star_int = 0;
	}
}

void	handle_minstardotstar(const char *fmt, t_printf *pr)
{
	int	len;

	get_argstar(pr);
	get_argstar2(pr);
	if (fmt[pr->i + 5] == 's')
		dot_stringstar(pr, 1);
	else
	{
		len = ft_len(fmt[pr->i + 5], pr);
		if (pr->star_int > pr->star_int2)
		{
			pr->temp = pr->star_int - (pr->star_int - pr->star_int2);
			pr->c = pr->c + ft_putspace(pr->temp, len, '0');
			pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + 5])](pr->ap);
			pr->c = pr->c + ft_putspace(pr->star_int, pr->star_int2, ' ');
		}
		else
		{
			pr->c = pr->c + ft_putspace(pr->star_int2, len, '0');
			pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + 5])](pr->ap);
		}
	}
	pr->i = pr->i + 5;
	pr->star_int = 0;
	pr->star_int2 = 0;
}