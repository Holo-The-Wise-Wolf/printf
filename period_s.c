/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   period_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:34:24 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/09 01:45:37 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star(t_printf *pr, int format_int, int min)
{
	if (min == 1)
	{
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
		if (format_int > pr->star_int2)
			pr->c = pr->c + ft_putspace(format_int, pr->star_int2, ' ');
	}
	else
	{
		if (format_int > pr->star_int2)
			pr->c = pr->c + ft_putspace(format_int, pr->star_int2, ' ');
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
	}
}

void	dot_stringstar(t_printf *pr, int min)
{
	pr->cpy = va_arg(pr->ap, char *);
	va_arg(pr->pa, char *);
	if (min == 1)
	{
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
		if (pr->star_int > pr->star_int2)
			pr->c = pr->c + ft_putspace(pr->star_int, pr->star_int2, ' ');
	}
	else
	{
		if (pr->star_int > pr->star_int2)
			pr->c = pr->c + ft_putspace(pr->star_int, pr->star_int2, ' ');
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
	}
}

void	dot_string(t_printf *pr, int format_int, int min)
{
	pr->cpy = va_arg(pr->ap, char *);
	va_arg(pr->pa, char *);
	if (pr->star_int != 0)
	{
		if (min == 1)
		{
			pr->c = pr->c + ft_putstrn(pr->cpy, format_int);
			if (format_int < pr->star_int)
				pr->c = pr->c + ft_putspace(pr->star_int, format_int, ' ');
		}
		else
		{
			if (format_int < pr->star_int)
				pr->c = pr->c + ft_putspace(pr->star_int, format_int, ' ');
			pr->c = pr->c + ft_putstrn(pr->cpy, format_int);
		}
	}
	else if (pr->star_int2 != 0)
		star(pr, format_int, min);
	else
		pr->c = pr->c + ft_putstrn(pr->cpy, format_int);
}
