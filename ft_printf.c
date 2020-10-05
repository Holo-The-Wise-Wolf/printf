#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_printf(const char *format, ...);

typedef struct s_printf
{
	int		star;
	int		star_int;
	int		star_int2;
	int		c;
	int		i;
	int		temp;
	char	*cpy;
	va_list(ap);
	va_list(pa);
	int(*ptr[9])(va_list);
}			s_printf;

void	init_struct(s_printf *pr)
{
	pr->star = 0;
	pr->star_int = 0;
	pr->star_int2 = 0;
	pr->c = 0;
	pr->i = 0;
	pr->temp = 0;
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd <= 2 && fd >= 0 && s)
		write(fd, s, ft_strlen(s));
}

char	*ft_strdup(const char *src)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!(cpy = malloc(ft_strlen(src) * (sizeof(char)) + 1)))
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int		ft_putstrn(const char *src, int n)
{
	int	i;
	int c;
	int j;

	i = 0;
	c = 0;
	j = 0;
	if (!src)
		return (0);
	while (src[i])
		i++;
	if (n <= 0)
		return (i);
	if (n > i)
		n = i + 1;
	while (src[j] && n--)
	{
		ft_putchar(src[j]);
		j++;
		c++;
	}
	return (c);
}

int	ft_putnbr_hexa(int nbr, char *base)
{
	int		nbr_final[100];
	unsigned int	unbr;
	int		i;
	int		count;

	i = 0;
	unbr = nbr;
	while (unbr)
	{
		nbr_final[i] = unbr % 16;
		unbr = unbr / 16;
		i++;
	}
	count = i;
	while (--i >= 0)
		ft_putchar(base[nbr_final[i]]);
	return (count);
}

int	ft_putnbr_ptr(long int nbr, char *base)
{
	int			nbr_final[100];
	unsigned long int	unbr;
	int	i;
	int	count;

	i = 0;
	unbr = nbr;
	while (unbr)
	{
		nbr_final[i] = unbr % 16;
		unbr = unbr / 16;
		i++;
	}
	count = i;
	while (--i >= 0)
		ft_putchar(base[nbr_final[i]]);
	return (count);
}

int	ft_printf_ptr(va_list ap)
{
	long int	ptr;
	int			count;

	ptr = va_arg(ap, long int);
	write(1, "0x", 2);
	count = 2;
	if (ptr == 0)
		count++;
	while(ptr != 0)
	{
		count++;
		ptr /= 10;
	}	
	ft_putnbr_ptr(ptr, "0123456789abcdef");
	return(count);
}

int	ft_printf_hexa1(va_list ap)
{
	int	nbr;
	int	count;

	nbr = va_arg(ap, int);
	count = ft_putnbr_hexa(nbr, "0123456789abcdef");
	return (count);
}

int	ft_printf_hexa2(va_list ap)
{
	int	nbr;
	int	count;

	nbr = va_arg(ap, int);
	count = ft_putnbr_hexa(nbr, "0123456789ABCDEF");
	return (count);
}

int	ft_printf_str(va_list ap)
{
	char	*str;
	int	count;

	str = va_arg(ap, char *);
	write(1, str, ft_strlen(str));
	count = ft_strlen(str);
	return (count);
}

int	ft_printf_char(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(long int x)
{
	if (x < 0)
	{
		x = -x;
		write(1, "-", 1);
	}
	if (x > 9)
		ft_putnbr(x / 10);
	write(1, &"0123456789"[x % 10], 1);
}

void	ft_putunbr(unsigned int x)
{
	if (x > 9)
		ft_putnbr(x / 10);
	write(1, &"0123456789"[x % 10], 1);
}

int	ft_printf_nbr(va_list ap)
{
	int			nbr;
	long int	x;
	int		count;

	nbr = va_arg(ap, int);
	x = nbr;
	count = 0;
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		count++;
		nbr /= 10;
	}
	if (x < 0)
	{
		x = -x;
		write(1, "-", 1);
		count++;
	}
	if (x > 9)
		ft_putnbr(x / 10);
	write(1, &"0123456789"[x % 10], 1);
	return (count);
}

int	ft_printf_unbr(va_list ap)
{
	unsigned int	unbr;
	unsigned int	unbr2;
	int		nbr;
	int		count;

	nbr = va_arg(ap, int);
	unbr = nbr;
	unbr2 = unbr;
	count = 0;
	if (unbr2 == 0)
		count++;
	while (unbr2 != 0)
	{
		count++;
		unbr2 /= 10;
	}
	if (unbr > 9)
		ft_putunbr(unbr / 10);
	write(1, &"0123456789"[unbr % 10], 1);
	return (count);
}

int  ft_getnbr(char const *str)
{
	int i;
	int neg;
	long int number;

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

void fill_tab(s_printf *pr)
{
	pr->ptr[0] = &ft_printf_str;
	pr->ptr[1] = &ft_printf_nbr;
	pr->ptr[2] = &ft_printf_nbr;
	pr->ptr[3] = &ft_printf_char;
	pr->ptr[4] = &ft_printf_unbr;
	pr->ptr[5] = &ft_printf_hexa1;
	pr->ptr[6] = &ft_printf_hexa2;
	pr->ptr[7] = &ft_printf_ptr;
}

int	corresponding(char c, char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		if (c == string[i])
			return (1);
		i++;
	}
	return (0);
}

int check_tab(const char comp)
{
	int i;
	char *list;

	i = 0;
	list = ft_strdup("sdicuxXp");
	while (comp != list[i]) {
		if (list[i] == 0)
			return (-1);
		i++;
	}
	return (i);
}

int len_nbr(int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int len_base(unsigned int nb, int b)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / b;
		i++;
	}
	return (i);
}

int ft_putspace(int len1, int len2, char l)
{
	int res;
	int count;

	res = len1 - len2;
	count = 0;
	if (res <= 0)
		return (0);
	while (res > 0)
	{
		ft_putchar(l);
		res--;
		count++;
	}
	return (count);
}

int ft_len(char c, s_printf *pr)
{
	if (corresponding(c, "di") == 1)
		return (len_nbr(va_arg(pr->pa, int)));
	if (corresponding(c, "xX"))
		return (len_base(va_arg(pr->pa, unsigned int), 16));
	if (corresponding(c, "p"))
		return (len_base(va_arg(pr->pa, unsigned int), 16) + 2);
	if (corresponding(c, "s") == 1)
		return (ft_strlen(va_arg(pr->pa, char *)));
	if (corresponding(c, "c%") == 1)
		return (1);
	else
	return (0);
}

char *get_nbr(const char *str)
{
	char *output;
	int i;

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

void	get_argstar(s_printf *pr)
{
	pr->star_int = va_arg(pr->ap, int);
	va_arg(pr->pa, int);
}

void	get_argstar2(s_printf *pr)
{
	pr->star_int2 = va_arg(pr->ap, int);
	va_arg(pr->pa, int);
}

void	star(s_printf *pr,int format_int, int min)
{
		if (min == 1)
		{
			pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
			if (format_int > pr->star_int2)
				pr->c = pr->c + ft_putspace(format_int, pr->star_int2, ' ');
		}
		else
		{
			if (format_int > pr->star_int2)
				pr->c = pr->c + ft_putspace(format_int, pr->star_int2, ' ');
			pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
		}
}

void	dot_stringstar(s_printf *pr, int min)
{
	pr->cpy = va_arg(pr->ap, char *);
	va_arg(pr->pa, char *);

	if (min == 1)
	{
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
		if (pr->star_int > pr->star_int2)
			pr->c = pr->c + ft_putspace(pr->star_int, pr->star_int2, ' ');
	}
	else
	{
		if (pr->star_int > pr->star_int2)
			pr->c = pr->c + ft_putspace(pr->star_int, pr->star_int2, ' ');
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
	}
}

void	dot_string(s_printf *pr, int format_int, int min)
{
	pr->cpy = va_arg(pr->ap, char *);
	va_arg(pr->pa, char *);
	if (pr->star_int != 0)
	{
		if (min == 1)
		{
			pr->c = pr->c + ft_putstrn(pr->cpy, format_int);
			if (format_int < pr->star_int)
				pr->c = pr->c + ft_putspace(pr->star_int, format_int, ' ');
		}
		else
		{
			if (format_int < pr->star_int)
				pr->c = pr->c + ft_putspace(pr->star_int, format_int, ' ');
			pr->c = pr->c + ft_putstrn(pr->cpy, format_int);
		}
	}
	else if (pr->star_int2 != 0)
		star(pr, format_int, min);
	else
		pr->c = pr->c + ft_putstrn(pr->cpy, format_int);
}

void	precisionstar(const char *fmt, s_printf *pr, int l_fmt, int fmt_int)
{
	int len;

	get_argstar2(pr);
	len = ft_len(fmt[pr->i + l_fmt + 3], pr);
	if(fmt[pr->i + l_fmt + 3] == 's')
	{
		pr->cpy = va_arg(pr->ap, char *);
		va_arg(pr->pa, char *);
		if(pr->star_int2 < fmt_int)
			pr->c = pr->c + ft_putspace(fmt_int, pr->star_int2, ' ');
		pr->c = pr->c + ft_putstrn(pr->cpy, pr->star_int2);
	}
	else if(pr->star_int2 < fmt_int)
	{
		pr->c = pr->c + ft_putspace(fmt_int, pr->star_int2, ' ');
		fmt_int = fmt_int - (fmt_int - pr->star_int2);
		pr->c = pr->c + ft_putspace(fmt_int, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
	}
	else
	{
		pr->c = pr->c + ft_putspace(pr->star_int2, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
	}
	pr->i = pr->i + l_fmt + 3;
}

void	precision(const char *fmt, s_printf *pr, int l_fmt, int fmt_int)
{
	int len;
	int l2;
	int fmt_int2;
	char *get_n;

	get_n = get_nbr(&fmt[pr->i + l_fmt + 2]);
	l2 = ft_strlen(get_n);
	fmt_int2 = ft_getnbr(&fmt[pr->i + l_fmt + 2]);
	len = ft_len(fmt[pr->i + l_fmt + l2 + 2], pr);
	if(fmt_int2 < fmt_int)
	{
		pr->c = pr->c + ft_putspace(fmt_int, fmt_int2, ' ');
		fmt_int = fmt_int - (fmt_int - fmt_int2);
		pr->c = pr->c + ft_putspace(fmt_int, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + l2 + 2])](pr->ap);
	}
	else
	{
		pr->c = pr->c + ft_putspace(fmt_int2, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + l2 + 2])](pr->ap);
	}
	pr->i = pr->i + l_fmt + l2 + 2;
}

void	handle_precision(const char *fmt, s_printf *pr, int l_fmt, int fmt_int)
{
	int l_fmt2;
	int fmt_int2;
	char *get_n;

	get_n = get_nbr(&fmt[pr->i + l_fmt + 2]);
	l_fmt2 = ft_strlen(get_n);
	fmt_int2 = ft_getnbr(&fmt[pr->i + l_fmt + 2]);
	if(fmt[pr->i + l_fmt + 2] == '*')
		precisionstar(fmt, pr, l_fmt, fmt_int);
	else
	{
		if(fmt[pr->i + l_fmt + l_fmt2 + 2] == 's')
		{
			pr->cpy = va_arg(pr->ap, char *);
			va_arg(pr->pa, char *);
			if(fmt_int2 < fmt_int)
				pr->c = pr->c + ft_putspace(fmt_int, fmt_int2, ' ');
			pr->c = pr->c + ft_putstrn(pr->cpy, fmt_int2);
			pr->i = pr->i + l_fmt + l_fmt2 + 2;
		}
		else
			precision(fmt, pr, l_fmt, fmt_int);
	}
	pr->star_int2 = 0;
}

void handle_minstardotstar(const char * fmt, s_printf *pr)
{
	int len;

	get_argstar(pr);
	get_argstar2(pr);
	if (fmt[pr->i + 5] == 's')
		dot_stringstar(pr, 1);
	else
	{
		len = ft_len(fmt[pr->i + 5], pr);
		if (pr->star_int > pr->star_int2)
		{
			pr->temp = pr->star_int - (pr->star_int - pr->star_int2);
			pr->c = pr->c + ft_putspace(pr->temp, len, '0');
			pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + 5])](pr->ap);
			pr->c = pr->c + ft_putspace(pr->star_int, pr->star_int2, ' ');
		}
		else
		{
			pr->c = pr->c + ft_putspace(pr->star_int2, len, '0');
			pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + 5])](pr->ap);
		}
	}
	pr->i = pr->i + 5;
	pr->star_int = 0;
	pr->star_int2 = 0;
}

void handle_zerostar(const char *format, s_printf *pr)
{
	int len;

	get_argstar2(pr);
	if (format[pr->i + 3] == 's')
		dot_string(pr, 1, 0);
	else
	{
		len = ft_len(format[pr->i + 3], pr);
		pr->c += ft_putspace(pr->star_int2, len, '0');
		pr->c += pr->ptr[check_tab(format[pr->i + 3])](pr->ap);
	}
		pr->i += 3;
		pr->star_int2 = 0;
}

void mindot(const char *fmt, s_printf *pr, int l_fmt, int fmt_int)
{
	int		fmt_int2;
	int		l2;
	char	*get_n;
	int		len;

	get_n = get_nbr(&fmt[pr->i + l_fmt + 2]);
	l2 = ft_strlen(get_n);
	fmt_int2 = ft_getnbr(&fmt[pr->i + l_fmt + 2]);
	len = ft_len(fmt[pr->i + l_fmt + l2 + 2], pr);
	fmt_int = fmt_int * (-1);
	if(fmt_int > fmt_int2)
	{
		pr->temp = fmt_int - (fmt_int - fmt_int2);
		pr->c = pr->c + ft_putspace(pr->temp, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + l2 + 2])](pr->ap);
		pr->c = pr->c + ft_putspace(fmt_int, fmt_int2, ' ');
	}
	else
	{
		pr->c = pr->c + ft_putspace(fmt_int2, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + l2 + 2])](pr->ap);
	}
}

void handle_mindotstar(const char *fmt, s_printf *pr, int l_fmt, int fmt_int)
{
	int len;
	int res;
	int n;

	get_argstar2(pr);
	n = fmt_int * (-1);
	len = ft_len(fmt[pr->i + l_fmt + 3], pr);
	if (fmt[pr->i + l_fmt + 3] == 's')
		dot_string(pr, n, 1);
	else if (n > pr->star_int2)
	{
		res = n - (n - pr->star_int2);
		pr->c = pr->c + ft_putspace(res, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
		pr->c = pr->c + ft_putspace(n, pr->star_int2, ' ');
	}
	else
	{
		pr->c = pr->c + ft_putspace(pr->star_int2, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
	}
	pr->i = pr->i + l_fmt + 3;
	pr->star_int2 = 0;
}

void handle_stardotstar(const char *fmt, s_printf *pr)
{
	int len;

	get_argstar(pr);
	get_argstar2(pr);
	if (fmt[pr->i + 4] == 's')
		dot_stringstar(pr, 0);
	else
	{
		len = ft_len(fmt[pr->i + 4], pr);
		if (pr->star_int > pr->star_int2)
		{
			pr->temp = pr->star_int - (pr->star_int - pr->star_int2);
			pr->c = pr->c + ft_putspace(pr->star_int, pr->star_int2, ' ');
			pr->c = pr->c + ft_putspace(pr->temp, len, '0');
			pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + 4])](pr->ap);
		}
		else
		{
			pr->c = pr->c + ft_putspace(pr->star_int2, len, '0');
			pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + 4])](pr->ap);
		}
	}
	pr->i = pr->i + 4;
	pr->star_int = 0;
	pr->star_int2 = 0;
}

void	minstardot(const char *fmt, s_printf *pr, int l_fmt, int fmt_int)
{
	int len;
	int res;

	len = ft_len(fmt[pr->i + l_fmt + 4], pr);
	if (fmt_int < pr->star_int)
	{
		res = pr->star_int - (pr->star_int - fmt_int);
		pr->c = pr->c + ft_putspace(res, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 4])](pr->ap);
		pr->c = pr->c + ft_putspace(pr->star_int, fmt_int, ' ');
	}
	else
	{
		pr->c = pr->c + ft_putspace(fmt_int, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 4])](pr->ap);
	}
}

void	stardot(const char *fmt, s_printf *pr, int l_fmt, int fmt_int)
{
	int len;
	int res;

	len = ft_len(fmt[pr->i + l_fmt + 3], pr);
	if (fmt_int < pr->star_int)
	{
		pr->c = pr->c + ft_putspace(pr->star_int, fmt_int, ' ');
		res = pr->star_int - (pr->star_int - fmt_int);
		pr->c = pr->c + ft_putspace(res, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
	}
	else
	{
		pr->c = pr->c + ft_putspace(pr->star_int, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 3])](pr->ap);
	}
}

void handle_minstardot(const char *fmt, s_printf *pr)
{
	int format_int;
	int l_fmt;
	char *get_n;

	if (fmt[pr->i + 4] == '*')
		handle_minstardotstar(fmt, pr);
	else
	{
		get_argstar(pr);
		get_n = get_nbr(&fmt[pr->i + 4]);
		l_fmt = ft_strlen(get_n);
		format_int = ft_getnbr(&fmt[pr->i + 4]);
		if (fmt[pr->i + l_fmt + 4] == 's')
			dot_string(pr, format_int, 1);
		else
			minstardot(fmt, pr, l_fmt, format_int);
		pr->i = pr->i + l_fmt + 4;
		pr->star_int = 0;
	}
}

void handle_mindot(const char *fmt, s_printf *pr, int l_fmt, int fmt_int)
{
	int		fmt_int2;
	int		l2;
	char	*get_n;

	if(fmt[pr->i + l_fmt + 2] == '*')
		handle_mindotstar(fmt, pr, l_fmt, fmt_int);
	else
	{
		get_n = get_nbr(&fmt[pr->i + l_fmt + 2]);
		l2 = ft_strlen(get_n);
		fmt_int2 = ft_getnbr(&fmt[pr->i + l_fmt + 2]);
		if (fmt[pr->i + l_fmt + l2 + 2] == 's')
			dot_string(pr, fmt_int, 1);
		else
			mindot(fmt, pr, l_fmt, fmt_int);
		pr->i = pr->i + l_fmt + l2 + 2;
	}
}


void handle_stardot(const char *fmt, s_printf *pr)
{
	int format_int;
	int l_fmt;
	char *get_n;

	if (fmt[pr->i + 3] == '*')
		handle_stardotstar(fmt, pr);
	else
	{
		get_argstar(pr);
		get_n = get_nbr(&fmt[pr->i + 3]);
		l_fmt = ft_strlen(get_n);
		format_int = ft_getnbr(&fmt[pr->i + 3]);
		if (fmt[pr->i + l_fmt + 3] == 's')
			dot_string(pr, format_int, 0);
		else
			stardot(fmt, pr, l_fmt, format_int);
		pr->i = pr->i + l_fmt + 3;
		pr->star_int = 0;
	}
}

void handle_minstar(const char *format, s_printf *pr)
{
	int star_int;
	int len;

	if(format[pr->i + 3] == '.')
		handle_minstardot(format, pr);
	else
	{
		star_int = va_arg(pr->ap, int);
		va_arg(pr->pa, int);
		len = ft_len(format[pr->i + 3], pr);
		pr->c += pr->ptr[check_tab(format[pr->i + 3])](pr->ap);
		pr->c += ft_putspace(star_int, len, ' ');
		pr->i += 3;
	}
}

void	handle_zero(const char *fmt, s_printf *pr)
{
	int format_int;
	int l_fmt;
	int len;
	char *get_n;

	if(fmt[pr->i + 2] == '*')
		handle_zerostar(fmt, pr);
	else
	{
		get_n = get_nbr(&fmt[pr->i + 1]);
		l_fmt = ft_strlen(get_n);
		format_int = ft_getnbr(&fmt[pr->i + 1]);
		len = ft_len(fmt[pr->i + l_fmt + 1], pr);
		pr->c = pr->c + ft_putspace(format_int, len, '0');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 1])](pr->ap);
		pr->i = pr->i + l_fmt + 1;
	}
}

void	handle_dot(const char *fmt, s_printf *pr)
{
	int format_int;
	int l_fmt;
	int len;
	char *get_n;

	if (fmt[pr->i + 2] == '*')
		handle_zerostar(fmt, pr);
	else
	{
		get_n = get_nbr(&fmt[pr->i + 2]);
		l_fmt = ft_strlen(get_n);
		format_int = ft_getnbr(&fmt[pr->i + 2]);
		len = ft_len(fmt[pr->i + l_fmt + 2], pr);
		if (fmt[pr->i + l_fmt + 2] == 's')
			dot_string(pr, format_int, 0);
		else
		{
			pr->c = pr->c + ft_putspace(format_int, len, '0');
			pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + l_fmt + 2])](pr->ap);
		}
		pr->i = pr->i + l_fmt + 2;
	}
}

void	handle_star(const char *format,s_printf *pr)
{
	int len;

	if (format[pr->i + 2] == '.')
		handle_stardot(format, pr);
	else
	{
		get_argstar(pr);
		len = ft_len(format[pr->i + 2], pr);
		pr->c += ft_putspace(pr->star_int, len, ' ');
		pr->c += pr->ptr[check_tab(format[pr->i + 2])](pr->ap);
		pr->i += 2;
	}
	pr->star_int = 0;
}

void handle_minus(const char *fmt, s_printf *pr)
{
	int format_int;
	int len_format;
	int len;
	char *get_n;

	if (fmt[pr->i + 2] == '*')
		handle_minstar(fmt, pr);
	else
	{
		get_n = get_nbr(&fmt[pr->i + 1]);
		len_format = ft_strlen(get_n);
		format_int = ft_getnbr(&fmt[pr->i + 1]);
		if (fmt[pr->i + len_format + 1] == '.')
			handle_mindot(fmt, pr, len_format, format_int);
		else
		{
			len = ft_len(fmt[pr->i + len_format + 1], pr);
			pr->c += pr->ptr[check_tab(fmt[pr->i + len_format + 1])](pr->ap);
			pr->c += ft_putspace((format_int * (-1)), len, ' ');
			pr->i += len_format + 1;
		}
	}
}

void handle_width(const char *fmt, s_printf *pr)
{
	int format_int;
	int len_format;
	int len;
	char *get_n;

	get_n = get_nbr(&fmt[pr->i + 1]);
	len_format = ft_strlen(get_n);
	format_int = ft_getnbr(&fmt[pr->i + 1]);
	len = ft_len(fmt[pr->i + len_format + 1], pr);
	if (fmt[pr-> i + len_format + 1] == '.')
		handle_precision(fmt, pr, len_format, format_int);
	else
	{
		pr->c = pr->c + ft_putspace(format_int, len, ' ');
		pr->c = pr->c + pr->ptr[check_tab(fmt[pr->i + len_format + 1])](pr->ap);
		pr->i = pr->i + len_format + 1;
	}
}

void	formating(const char *fmt, s_printf *pr)
{
	char *get_n;
	int len_format;

	if (fmt[pr->i + 1] == '.')
		handle_dot(fmt, pr);
	else
	{
		get_n = get_nbr(&fmt[pr->i + 1]);
		len_format = ft_strlen(get_n);
		if (fmt[pr->i + 2] == '*')
			pr->star = 1;
		if (get_n[0] == '0' 
			&& corresponding(fmt[pr->i + len_format + pr->star + 1], "sc") != 1)
				handle_zero(fmt, pr);
		else if (fmt[pr->i + 1] == '-')
			handle_minus(fmt, pr);
		else if (check_tab(fmt[pr->i + len_format + 1] == -1) 
			&& fmt[pr->i + len_format + 1] != '.')
		{
			pr->c++;
			ft_putchar('%');
		}
		else
			handle_width(fmt, pr);
	}
}
void handle_percent(const char *format, s_printf *pr)
{
	if (corresponding(format[pr->i + 1], "*") == 1)
		handle_star(format, pr);
	else if (corresponding(format[pr->i + 1], ".-0123456789") == 1)
		formating(format, pr);
	else if (format[pr->i + 1] == '%')
	{
		ft_putchar('%');
		pr->c++;
		pr->i++;
	}
	else if (check_tab(format[pr->i + 1]) != -1)
	{
		va_arg(pr->pa, int);
		pr->c += pr->ptr[check_tab(format[pr->i + 1])](pr->ap);
		pr->i++;
	}
	else if (check_tab(format[pr->i + 1]) == -1
	&& corresponding(check_tab(format[pr->i + 1]), ".*-0123456789") != 1)
	{
		pr->c++;
		ft_putchar('%');
	}
}

int ft_printf(const char *format, ...)
{
	s_printf	*pr;
	
	pr = malloc(sizeof(s_printf));
	va_start(pr->ap, format);
	va_start(pr->pa, format);
	init_struct(pr);
	fill_tab(pr);
	while (format[pr->i] != '\0')
	{
		if (format[pr->i] == '%')
			handle_percent(format, pr);
		else
	{
			pr->c++;
			ft_putchar(format[pr->i]);
		}
		pr->i++;
	}
	va_end(pr->pa);
	va_end(pr->ap);
	return (pr->c);
}

int	main()
{
	int	a;
	int	b;

	a = ft_printf("test : salut %12.11i mec %%\n", 123);
	b = printf("test : salut %12.11i mec %%\n", 123);
	printf("%d\n%d\n", a, b);
}
