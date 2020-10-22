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

int	len_ptr(long int nb)
{
	int                 i;
	long unsigned int   unb;

	unb = nb;
	i = 0;
	if (unb == 0)
		return (0);
	while (unb > 0)
	{
		unb = unb / 16;
		i++;
	}
	return (i + 2);
}

int	len_base(int nb, int b, char spec, t_formatted *f)
{
	int i;
	unsigned int unb;

	if (nb < 0 && corresponding(spec, "di"))
	{
		f->sign = '-';
		nb = -nb;
	}
	unb = nb;
	i = 0;
	if (unb == 0)
		return (1);
	while (unb > 0)
	{
		unb = unb / b;
		i++;
	}
	return (i);
}

char	*itoa_base_ptr(long int value, int base)
{
	int						size;
	long unsigned int		nbr;
	char					*result;
	char					*ref_base;

	nbr = value;
	ref_base = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	size = len_ptr(nbr);
	if (!(result = (char*)malloc(sizeof(*result) * (size + 1))))
		return (NULL);
	result[size--] = '\0';
	result[0] = '0';
	result[1] = 'x';
	while (nbr > 0)
	{
		result[size--] = ref_base[nbr % base];
		nbr /= base;
	}
	return (result);
}

char	*ft_itoa_base(int value, int base, char spec, t_formatted *f)
{
	int					size;
	unsigned int		nbr;
	char				*result;
	char				*ref_base;

	if (value < 0 && (spec == 'd' || spec == 'i'))
		value = -value;
	nbr = value;
	if (spec == 'X')
		ref_base = "0123456789ABCDEF";
	else
		ref_base = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	size = len_base(nbr, base, spec, f);
	if (!(result = (char*)malloc(sizeof(*result) * (size + 1))))
		return (NULL);
	result[size--] = '\0';
	result[0] = (value < 0 ? '-' : '0');
	while (nbr > 0)
	{
		result[size--] = ref_base[nbr % base];
		nbr /= base;
	}
	return (result);
}

void 	handle_width(t_arg *arg, t_formatted *f)
{
	int	len;

	len = count_printed(f);
	if (arg->width > len)
		f->spaces = arg->width - len;
	if((arg->flags & PAD_ZERO) != 0 && arg->has_precision == 0)
	{
		if(corresponding(arg->specifier, "diuxX"))
		{
			f->zeroes = f->spaces;
			f->spaces = 0;
		}
	}
}

void 	handle_flags(t_arg *arg, t_formatted *f)
{
	if((arg->flags & LEFT_JUSTIFY) != 0)
		f->left_justify = 1;
}

void 	handle_zeroes(t_arg *arg, t_formatted *f, int len)
{
	if(arg->precision > 0 && arg->precision > len)
		f->zeroes = arg->precision - len;
}

void 	handle_specifier(t_printf *pr, t_arg *arg, t_formatted *f)
{
	int	len;

	len = 0;
	if (corresponding(arg->specifier, "diuxX"))
	{
		len = spec_number(pr, arg, f);
		handle_zeroes(arg, f, len);
	}
	else if (arg->specifier == 's')
		spec_string(pr, arg, f);
	else if (arg->specifier == 'c')
		spec_char(pr, f);
	else if (arg->specifier == 'p')
		spec_pointer(pr, arg, f);
	else if (arg->specifier == '%')
		spec_percent(arg, f);
}
