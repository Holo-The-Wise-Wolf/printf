/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:50:38 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/23 23:50:52 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	t_printf_init(t_printf *pr, const char *fmt)
{
	pr->fmt = fmt;
	pr->i = 0;
	pr->count = 0;
}

void	t_arg_init(t_arg *arg)
{
	arg->flags = 0;
	arg->width = 0;
	arg->has_precision = 0;
	arg->precision = 0;
	arg->length = '\0';
	arg->specifier = '\0';
}

void	t_formatted_init(t_formatted *f)
{
	f->spaces = 0;
	f->zeroes = 0;
	f->sign = '\0';
	f->left_justify = 0;
	f->prefix = '\0';
	f->c_null = 0;
	f->content = NULL;
}

void	t_formatted_free(t_formatted *f)
{
	free(f->content);
}
