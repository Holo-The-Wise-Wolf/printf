/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:23:51 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/09 01:18:13 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getnbr(char const *str)
{
	int			i;
	int			neg;
	long int	number;

	i = -1;
	neg = 1;
	number = 0;
	if (str == 0)
		return (0);
	while (str[++i] != '\0' && number == 0)
	{
		if (str[i] == '-')
			neg *= -1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			number = 10 * number + (str[i] - 48);
			++i;
		}
		if (str[i] == 0)
			i--;
	}
	return (number * neg);
}

char	*get_nbr(const char *str)
{
	char	*output;
	int		i;

	i = 0;
	output = malloc(sizeof(char) * 8);
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
	{
		output[i] = str[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

void	get_argstar(t_printf *pr)
{
	pr->star_int = va_arg(pr->ap, int);
	va_arg(pr->pa, int);
}

void	get_argstar2(t_printf *pr)
{
	pr->star_int2 = va_arg(pr->ap, int);
	va_arg(pr->pa, int);
}
