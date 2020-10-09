/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:28:31 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/09 01:46:52 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	corresponding(char c, char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (c == string[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_tab(const char comp)
{
	int		i;
	char	*list;

	i = 0;
	list = ft_strdup("sdicuxXp");
	while (comp != list[i])
	{
		if (list[i] == 0)
			return (-1);
		i++;
	}
	return (i);
}
