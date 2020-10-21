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
	long int 	flags;
	int			width;
	int 		has_precision;
	int			precision;
	char		length;
	char		specifier;
}				t_arg;

typedef struct	s_formatted
{
	int		left_justify;
	int 	spaces;
	int 	zeroes;
	char 	prefix;
	char 	sign;
	char	*content;
}				t_formatted;

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
void 	t_formatted_init(t_formatted *f);
int		print_arg(t_printf *pr, t_arg *arg);
void 	t_formatted_free(t_formatted *f);
void 	do_print(t_formatted *f);
int 	count_printed(t_formatted *f);

// utils.c
int		ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
int		ft_putspace(int len, char l);
int		corresponding(char c, char *s);

//handle.c
void 	handle_width(t_arg *arg, t_formatted *f);
void 	handle_flags(t_arg *arg, t_formatted *f);
void 	handle_zeroes(t_arg *arg, t_formatted *f, int len);
void 	handle_specifier(t_printf *pr, t_arg *arg, t_formatted *f);
char	*ft_itoa_base(int value, int base, char spec, t_formatted *f);
int		len_base(int nb, int b, char spec, t_formatted *f);
int		len_ptr(long int nb);

//specifier.c
int		spec_number(t_printf *pr, t_arg *arg, t_formatted *f);
int 	spec_string(t_printf *pr, t_arg	*arg, t_formatted *f);
int		spec_char(t_printf *pr, t_formatted *f);
void	spec_pointer(t_printf *pr, t_arg *arg, t_formatted *f);

#endif
