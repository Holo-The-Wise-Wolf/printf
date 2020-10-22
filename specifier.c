/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:41:57 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/21 19:42:22 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i])
		i++;
	if (dstsize <= 0)
		return (i);
	if (dstsize > i)
		dstsize = i + 1;
	while (*src && dstsize-- - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (i);
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

	str = va_arg(pr->args, char *);
	if ((arg->precision >= 6 || arg->precision < 0) && str == NULL)
	{
		len = ft_strlen("(null)");
		f->content = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(f->content, "(null)", len + 1);
		return (0);
	}
	if (arg->precision == 0 && arg->has_precision == 1)
		return (0);
	len = ft_strlen(str);
	if (arg->precision > len || arg->precision < 0 || arg->has_precision == 0)
	{
		f->content = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(f->content, str, len + 1);
	}
	else
	{
		len = arg->precision;
		f->content = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(f->content, str, len + 1);
	}
	return (0);
}

int		spec_char(t_printf *pr, t_formatted *f)
{
	char 	c;

	c = va_arg(pr->args, int);
	f->content = malloc(sizeof(char) * 2);
	if (c == NULL)
	{
		f->c_null = 1;
		return (0);
	}
	f->content[0] = c;
	f->content[1] = '\0';
	return (1);
}

void 	spec_percent(t_arg *arg, t_formatted *f)
{
	f->content = malloc(sizeof(char) * 2);
	f->content[0] = '%';
	f->content[1] = '\0';
	f->prefix = '\0';
	f->sign = '\0';
	f->zeroes = 0;
	f->spaces = 0;
	arg->precision = 0;
	arg->width = 0;
}

void	spec_pointer(t_printf *pr, t_arg *arg, t_formatted *f)
{
	long int	ptr;
	char 		*str;
	int 		len;

	ptr = va_arg(pr->args, long int);
	if (ptr == 0)
	{
		len = ft_strlen("(nil)");
		f->content = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(f->content, "(nil)", len + 1);
	}
	else
	{
		str = itoa_base_ptr(ptr, 16);
		len = ft_strlen(str);
		ft_strlcpy(f->content, str, len + 1);
	}
}