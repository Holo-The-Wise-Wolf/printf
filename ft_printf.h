/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:36:04 by lmoi              #+#    #+#             */
/*   Updated: 2020/10/13 23:36:49 by lmoi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_printf
{
	const char	*fmt;
	int			i;
	va_list		args;
}				t_printf;

typedef struct	s_arg
{
	long	flags;
	int		width;
	int 	has_precision;
	int		precision;
	char	length;
	char	specifier;
}				t_arg;

typedef enum	e_flags {
	LEFT_JUSTIFY	= 1 << 0,
	SHOW_SIGN		= 1 << 1,
	NO_SIGN			= 1 << 2,
	SHOW_PREFIX		= 1 << 3,
	PAD_ZERO		= 1 << 4,
}				t_flags;

// ft_printf.c
int		ft_printf(const char *format, ...);
void	t_printf_init(t_printf *pr, const char *fmt);
int		t_printf_peek(t_printf *pr, char *next);

// parser.c
void	t_arg_init(t_arg *arg);
t_arg	parse_arg(t_printf *pr);
void	parse_flags(t_printf *pr, t_arg *arg);
void	parse_width(t_printf *pr, t_arg *arg);
void	parse_precision(t_printf *pr, t_arg *arg);
void	parse_length(t_printf *pr, t_arg *arg);
void	parse_specifier(t_printf *pr, t_arg *arg);

// print.c
int		print_arg(t_printf *pr, t_arg *arg);

// utils.c
int		corresponding(char c, char *s);

#endif
