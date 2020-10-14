/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:55:56 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/13 23:32:00 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_dot(const char *fmt, t_printf *pr)
{
	int		format_int;
	int		l_fmt;
	int		len;
	char	*get_n;

    get_n = get_nbr(&fmt[pr->i + 2]);
    l_fmt = ft_strlen(get_n);
    format_int = ft_getnbr(&fmt[pr->i + 2]);
    len = ft_len(fmt[pr->i + l_fmt + 2], pr);
	if (fmt[pr->i + 2] == '*')
		handle_zerostar(fmt, pr, len);
	else
	{
		if (corresponding(fmt[pr->i + 2], "dixXu0") == 1 && pr->preczero == 1)
			pr->preczero = 0;
		else if (fmt[pr->i + l_fmt + 2] == 's')
			dot_string(pr, format_int, 0, len);
		else
		{
		    int_neg(pr);
			pr->c = pr->c + ft_putspace(format_int, len, '0');
			pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 2])](pr->ap);
		}
		pr->i = pr->i + l_fmt + 2;
	}
}
