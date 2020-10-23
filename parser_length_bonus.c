/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_length_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:55:57 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/23 23:56:41 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_length(t_printf *pr, t_arg *arg)
{
	char	length;

	length = '\0';
	if (corresponding(pr->fmt[pr->i], "hljztL"))
	{
		length = pr->fmt[pr->i];
		pr->i += 1;
	}
	arg->length = length;
}
