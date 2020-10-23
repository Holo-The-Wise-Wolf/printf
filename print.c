#include "ft_printf.h"

void 	t_formatted_init(t_formatted *f)
{
	f->spaces = 0;
	f->zeroes = 0;
	f->sign = '\0';
	f->left_justify = 0;
	f->prefix = '\0';
	f->c_null = 0;
	f->content = NULL;
}

void 	t_formatted_free(t_formatted *f)
{
	free(f->content);
}

void 	do_print(t_formatted *f)
{
	if(f->left_justify == 0)
		ft_putspace(f->spaces, ' ');
	ft_putchar(f->sign);
	if(f->prefix == 'x')
		ft_putstr("0x");
	if(f->prefix == 'X')
		ft_putstr("0X");
	ft_putspace(f->zeroes, '0');
	if(f-> c_null == 1)
		write(1, "\0", 1);
	else
		ft_putstr(f->content);
	if (f->left_justify == 1)
		ft_putspace(f->spaces, ' ');
}

int 	count_printed(t_formatted *f)
{
	int	count;

	if (f->c_null == 1)
		count = 1;
	else
		count = ft_strlen(f->content);
	count += f->zeroes;
	count += f->spaces;
	if (f->sign != '\0')
		count += 1;
	if (f->prefix != '\0')
		count += 2;
	return (count);
}

int		print_arg(t_printf *pr, t_arg *arg)
{
	int			count;
	t_formatted f;

	t_formatted_init(&f);
	handle_specifier(pr, arg, &f);
	handle_flags(arg, &f);
	handle_width(arg, &f);
	do_print(&f);
	count = count_printed(&f);
	t_formatted_free(&f);
	return (count);
}