#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_printf
{
    int c;
    int i;
}	s_print;

typedef struct s_list
{
    va_list(ap);
    va_list(pa);
}	s_list;


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

int	ft_printf_percent(va_list ap)
{
	ft_putchar('%');
	return (1);
}

int	ft_putnbr_hexa(int nbr, char *base)
{
	int		nbr_final[100];
	unsigned int 	unbr;
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
	unsigned long int 	unbr;
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
	long	int	ptr;
	int	 	count;

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
	int 		nbr;
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

/*
int	findIndex(char *tab, char elem)
{
	int index = 0;

	while (tab[index])
	{
		if (tab[index] == elem)
			return (index);
		index++;
	}
	return(-1);
}


int	ft_printf(const char *fmt, ...)
{
	int (*tabFunction[]) (va_list) = {};
	char tabIndex[5] = {'.', '-', '0', '*', 0};
	int (*tabFunction2[8]) (va_list) = {ft_printf_str, ft_printf_nbr, ft_printf_nbr, ft_printf_char, ft_printf_unbr, ft_printf_hexa1, ft_printf_hexa2, ft_printf_ptr};
	char tabIndex2[9] = {'s', 'd', 'i', 'c', 'u', 'x', 'X', 'p', 0};
	va_list ap;
	int i;
	int tmpIndex;
	int tmpIndex2;
	int count;

	i = 0;
	tmpIndex = 0;
	tmpIndex2 = 0;
	count = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			if (fmt[i + 1] == '%')
			{
				ft_putchar('%');
				count++;
			}
			i++;
			while (tmpIndex = findIndex(tabIndex, fmt[i]) != -1)
			{
				count += (*tabFunction[tmpIndex]) (ap);
				i++;
			}
			tmpIndex2 = findIndex(tabIndex2, fmt[i]);
			if (tmpIndex2 != -1)
				count += (*tabFunction2[tmpIndex2]) (ap);
		}
		else if (fmt[i] != '%')
		{
			write(1, &fmt[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
*/

void fill_tab(int(*ptr[9])(va_list))
{
    ptr[0] = &ft_printf_str;
    ptr[1] = &ft_printf_nbr;
    ptr[2] = &ft_printf_nbr;
    ptr[3] = &ft_printf_char;
    ptr[4] = &ft_printf_unbr;
    ptr[5] = &ft_printf_hexa1;
    ptr[6] = &ft_printf_hexa2;
    ptr[7] = &ft_printf_ptr;
    ptr[8] = &ft_printf_percent;
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
    list = ft_strdup("sdicuxXp%");
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

int ft_len(char c, s_list *lis)
{
    int i = 0;
    if (corresponding(c, "di") == 1)
        return (len_nbr(va_arg(lis->pa, int)));
    if (corresponding(c, "xX"))
        return (len_base(va_arg(lis->pa, unsigned int), 16));
    if (corresponding(c, "p"))
        return (len_base(va_arg(lis->pa, unsigned int), 16) + 2);
    if (corresponding(c, "s") == 1)
        return (ft_strlen(va_arg(lis->pa, char *)));
    if (corresponding(c, "c%") == 1)
        return (1);
}

char *get_nbr(const char *str)
{
    char *output;
    int i;
   
    i = 0;
    output = malloc(sizeof(char) * 8);
    while (str[i] >= '0' && str[i] <= '9' || str[i] == '-')
    {
        output[i] = str[i];
        i++;
    }
    output[i] = '\0';
    return (output);
}


void handle_zerostar(const char *format, s_list *lis, s_print *pr, int(*ptr[9])(va_list))
{
	int format_int;
	int len_format;
	int len;
	char *get_n;
}

void handle_minstar(const char *format, s_list *lis, s_print *pr, int(*ptr[9])(va_list))
{
	int format_int;
	int len_format;
	int len;
	char *get_n;
}

void handle_zero(const char *format, s_list *lis, s_print *pr, int(*ptr[9])(va_list))
{
	int format_int;
	int len_format;
	int len;
	char *get_n;

	get_n = get_nbr(&format[pr->i + 1]);
	len_format = ft_strlen(get_n);
 	format_int = ft_getnbr(&format[pr->i + 1]);
        len = ft_len(format[pr->i + len_format + 1], lis);
        pr->c = pr->c + ft_putspace(format_int, len, '0');
        pr->c = pr->c + ptr[check_tab(format[pr->i + len_format + 1])](lis->ap);
        pr->i = pr->i + len_format + 1;
}

void handle_star(const char *format, s_list *lis, s_print *pr, int(*ptr[9])(va_list))
{
	int format_int;
	int len_format;
	int len;
	char *get_n;
}

void handle_minus(const char *format, s_list *lis, s_print *pr, int(*ptr[9])(va_list))
{
	int format_int;
	int len_format;
	int len;
	char *get_n;

	if (format[pr->i + 2] == '*')
	    handle_minstar(format, lis, pr, ptr);
	else
	{
	get_n = get_nbr(&format[pr->i + 1]);
	len_format = ft_strlen(get_n);
	format_int = ft_getnbr(&format[pr->i + 1]);
	len = ft_len(format[pr->i + len_format + 1], lis);
	pr->c += ptr[check_tab(format[pr->i + len_format + 1])](lis->ap);
	pr->c += ft_putspace((format_int * (-1)), len, ' ');
	pr->i += len_format + 1;
	}
}

void handle_width(const char *format, s_list *lis, s_print *pr, int(*ptr[9])(va_list))
{
	int format_int;
	int len_format;
	int len;
	char *get_n;

	get_n = get_nbr(&format[pr->i + 1]);
	len_format = ft_strlen(get_n);
 	format_int = ft_getnbr(&format[pr->i + 1]);
        len = ft_len(format[pr->i + len_format + 1], lis);
        pr->c = pr->c + ft_putspace(format_int, len, ' ');
        pr->c = pr->c + ptr[check_tab(format[pr->i + len_format + 1])](lis->ap);
        pr->i = pr->i + len_format + 1;
}

int formating(const char *format, s_list *lis, s_print *pr, int(*ptr[9])(va_list))
{
    char *get_n;
    int len_format;
    //int len;
    //int format_int;
     
    get_n = get_nbr(&format[pr->i + 1]);
    len_format = ft_strlen(get_n);
    if (check_tab(format[pr->i + len_format + 1]) == -1)
    {
        pr->c++;
        ft_putchar('%');
        return (0);
    }
    if (format[pr->i + 1] == '-')
	handle_minus(format, lis, pr, ptr);
    else
    {
        if (get_n[0] == '0' && corresponding(format[pr->i + len_format + 1], "sc") != 1)
	    handle_zero(format, lis, pr, ptr);
	else if (format[pr->i + 1] == '*')
		handle_star(format, lis, pr, ptr);
	else
		handle_width(format, lis, pr, ptr);
        /*len = ft_len(format[pr->i + len_format + 1], lis);
        pr->c = pr->c + ft_putspace(format_int, len, ' ');
        pr->c = pr->c + ptr[check_tab(format[pr->i + len_format + 1])](lis->ap);
        pr->i = pr->i + len_format + 1;*/
    }
}

int handle_percent(const char *format, s_list *lis, s_print *pr, int(*ptr[9])(va_list))
{
    int a = 0;
    int len = 0;
    int add;

    if (corresponding(format[pr->i + 1], ".*-0123456789") == 1)
    {
        formating(format, lis, pr, ptr);
        return (0);
    }
    if (check_tab(format[pr->i + 1]) != -1)
    {
        len = va_arg(lis->pa, int);
        pr->c += ptr[check_tab(format[pr->i + 1])](lis->ap);
        pr->i++;
        return (0);
    }
    if (check_tab(format[pr->i + 1]) == -1
    && corresponding(check_tab(format[pr->i + 1]), "-0123456789") != 1)
    {
        pr->c++;
        ft_putchar('%');
        return (0);
    }
}

int ft_printf(const char *format, ...)
{
    s_print *pr = malloc(sizeof(s_print));
    s_list *lis = malloc(sizeof(s_list));

    pr->i = 0;
    pr->c = 0;
    int(*ptr[9])(va_list);
    va_start(lis->ap, format);
    va_start(lis->pa, format);
    fill_tab(ptr);
    while (format[pr->i] != '\0')
    {
        if (format[pr->i] == '%')
	{
            handle_percent(format, lis, pr, ptr);
        }
       	else 
	{
            pr->c++;
            ft_putchar(format[pr->i]);
        }
        pr->i++;
    }
    va_end(lis->pa);
    va_end(lis->ap);
    return (pr->c);
}

int	main()
{
	int	a;
	int	b;

	a = ft_printf("test : salut%03i mec %%\n", 12);
	b = printf("test : salut%03i mec %%\n", 12);
	printf("%d\n%d\n", a, b);
}
