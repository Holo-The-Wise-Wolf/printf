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

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if(s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_itoa_base(int value, int base, char spec, t_formatted *f)
{
	int				size;
	unsigned int	nbr;
	char			*result;
	char			*ref_base;

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
		len = len_base(nbr, 10, arg->specifier, f);
		str = ft_itoa_base(nbr, 10, arg->specifier, f);
	}
	if (arg->specifier == 'x')
	{
		len = len_base(nbr, 16, arg->specifier, f);
		str = ft_itoa_base(nbr, 16, arg->specifier, f);
	}
	if (arg->specifier == 'X')
	{
		len = len_base(nbr, 16, arg->specifier, f);
		str = ft_itoa_base(nbr, 16, arg->specifier, f);
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
	if(arg->precision >= 6 && str == NULL)
	{
		f->content = "(null)";
		return (ft_strlen(f->content));
	}
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
		i++;
	}
	f->content = str;
	return (arg->precision);
}

int		spec_char(t_printf *pr, t_formatted *f)
{
	char 	c;
	char	*str;

	c = va_arg(pr->args, int);
	str = malloc(sizeof(char) + 1);
	str[0] = c;
	str[1] = '\0';
	f->content = str;
	return (1);
}

int		spec_pointer(t_printf *pr, t_arg *arg, t_formatted *f)
{
	long int	ptr;
	int			len;
	char 		*str;

	ptr = va_arg(pr->args, long int);
	if (ptr == 0)
	{
		f->content = "(nil)";
		return (ft_strlen (f->content));
	}
	len = len_ptr(ptr);
	str = ft_itoa_base(ptr, 16, arg->specifier, f);
	f->content = str;
	return (len);
}

void 	handle_precision(t_arg *arg, t_formatted *f, int len)
{
	if(arg->precision > 0 && arg->precision > len)
		f->zeroes = arg->precision - len;
}

int 	handle_specifier(t_printf *pr, t_arg *arg, t_formatted *f)
{
	int	len;

	len = 0;
	if (corresponding(arg->specifier, "diuxX"))
	{
		len = spec_number(pr, arg, f);
		handle_precision(arg, f, len);
	}
	else if (arg->specifier == 's')
		len = spec_string(pr, arg, f);
	else if (arg->specifier == 'c')
		len = spec_char(pr, f);
	else if (arg->specifier == 'p')
		len = spec_pointer(pr, arg, f);
	return (len);
}
