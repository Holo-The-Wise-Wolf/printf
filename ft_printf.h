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
	int		star;
	int		star_int;
	int		star_int2;
	int		c;
	int		i;
	int		temp;
	int		preczero;
	int     min;
	int     starzero;
	char	*cpy;
	va_list	(ap);
	va_list	(pa);
	int		(*ptr[9])(va_list);
}				t_printf;

int				ft_printf(const char *format, ...);
void            prec_s(const char *fmt, t_printf *pr, int fmt_int, int l_fmt);
void            nostar_s(const char *fmt, t_printf *pr, int fmt_int, int l_fmt);
int 	        int_neg(t_printf *pr);
void			init_struct(t_printf *pr);
void			ft_putchar(char c);
int				ft_strlen(const char *s);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strdup(const char *src);
int				ft_putstrn(const char *src, int n);
int				ft_putnbr_hexa(int nbr, char *base);
int				ft_putnbr_ptr(long int nbr, char *base);
int				ft_printf_ptr(va_list ap);
int				ft_printf_hexa1(va_list ap);
int				ft_printf_hexa2(va_list ap);
int				ft_printf_str(va_list ap);
int				ft_printf_char(va_list ap);
void			ft_putnbr(long int x);
void			ft_putunbr(unsigned int x);
int				ft_printf_nbr(va_list ap);
int				ft_printf_unbr(va_list ap);
int				ft_getnbr(char const *str);
void			fill_tab(t_printf *pr);
int				corresponding(char c, char *string);
int				check_tab(const char comp);
int				len_nbr(int nb, t_printf *pr);
int				len_base(int nb, int b, t_printf *pr, int p);
int				ft_putspace(int len1, int len2, char l);
int				ft_len(char c, t_printf *pr);
char			*get_nbr(const char *str);
void            preczero(t_printf *pr);
void            get_argstars(t_printf *pr);
void			get_argstar(t_printf *pr);
void			get_argstar2(t_printf *pr);
void			star(t_printf *pr, int format_int, int min, int len);
void			dot_stringstar(t_printf *pr, int min);
void			dot_string(t_printf *pr, int format_int, int min, int len);
void			precstar(const char *fmt, t_printf *pr, int l_fmt, int fmt_int);
void			precis(const char *fmt, t_printf *pr, int l_fmt, int fmt_int);
void			h_precis(const char *fmt, t_printf *pr, int l_fmt, int fmt_int);
void			handle_minstardotstar(const char *fmt, t_printf *pr);
void			handle_zerostar(const char *format, t_printf *pr);
void			mindot(const char *fmt, t_printf *pr, int l_fmt, int fmt_int);
void			h_mindotstar(const char *fmt, t_printf *pr, int l_fmt, int f_i);
void			handle_stardotstar(const char *fmt, t_printf *pr);
void			minstardot(const char *fmt, t_printf *pr, int l_fmt, int fmt_i);
void			stardot(const char *fmt, t_printf *pr, int l_fmt, int fmt_int);
void			handle_minstardot(const char *fmt, t_printf *pr);
void			h_mindot(const char *fmt, t_printf *pr, int l_fmt, int fmt_int);
void			handle_stardot(const char *fmt, t_printf *pr);
void			handle_minstar(const char *format, t_printf *pr);
void			handle_zero(const char *fmt, t_printf *pr);
void			handle_dot(const char *fmt, t_printf *pr);
void			handle_star(const char *format, t_printf *pr);
void			handle_minus(const char *fmt, t_printf *pr);
void			handle_width(const char *fmt, t_printf *pr);
void			formating(const char *fmt, t_printf *pr);
void			handle_percent(const char *format, t_printf *pr);

#endif
