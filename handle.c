/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:16:51 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/20 16:17:22 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		spec_number(t_printf *pr, t_arg *arg, t_formatted *f)
{
	int 	nbr;
	int 	len;
	char	*str;

	nbr = va_arg(pr->args, int);
	if(nbr == 0 && arg->precision == 0 && arg->has_precision == 1)
		return (0);
	if (corresponding(arg->specifier, "diu"))
	{
		len = len_base(nbr, 10);
		str = ft_itoa_base(nbr, 10);
	}
	if (arg->specifier == 'x')
	{
		len = len_base(nbr, 16);
		str = ft_itoa_base(nbr, 16);
	}
	if (arg->specifier == 'X')
	{
		len = len_base(nbr, 16);
		str = ft_itoa_baseX(nbr, 16);
	}
	f->content = str;
	return (len);
}

int		spec_string(t_printf *pr, t_arg	*arg, t_formatted *f)
{
	char 	*str;
	int 	len;
	int 	i;

	i = 0;
	str = va_arg(pr->args, char *);
	if(arg->precision == 0)
		return (0);
	len = ft_strlen(str);
	if (arg->precision < 0 || arg->precision > len)
	{
		f->content = str;
		return (len);
	}
	while (arg->precision + i != len)
	{
		str[arg->precision - 1 + i] = '\0';
		i++
	}
	f->content = str;
	return (arg->precision);
}

int		spec_char(t_printf *pr, t_formatted *f)
{
	char c;
	char *str;

	c = va_arg(pr->args, char);
	str = malloc(sizeof(char) + 1);
	str[0] = c;
	str[1] = '\0';
	f->content = str;
	return (1);
}

int		spec_pointer(t_printf *pr, t_formatted *f)
{
	long int	nbr;
	int			len;
	char 		*str;

	nbr = va_arg(pr->args, long int);
	len = len_ptr(nbr);
	str = ft_itoa_base(nbr, 16);
	f->content = str;
	return (len);
}

void 	handle_specifier(t_printf *pr, t_arg *arg, t_formatted *f)
{
	int	len;

	if (corresponding(arg->specifier, "diuxX"))
		len = spec_number(&pr, &arg, &f);
	else if (arg->specifier == 's')
		len = spec_string(&pr, &f);
	else if (arg->specifier == 'c')
		len = spec_char(&pr, &f);
	else_if (arg->specifier == 'p')
		len = spec_pointer(&arg, &f);
	handle_precision(&arg, &f, len);
}
