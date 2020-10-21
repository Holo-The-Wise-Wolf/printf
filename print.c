#include "ft_printf.h"

void 	t_formatted_init(t_formatted *f)
{
	f->spaces = 0;
	f->zeroes = 0;
	f->sign = '\0';
	f->left_justify = 0;
	f->prefix = '\0';
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
	ft_putchar(f->prefix);
	ft_putspace(f->zeroes, '0');
	ft_putstr_fd(f->content);
	if (f->left_justify == 1)
		ft_putspace(f->spaces, ' ');
	//[espaces][sign][prefix][zeroes][contenu][espaces]
	//contenu -> zeroes(precision) -> prefix -> sign -> espaces(width)
	//print des espaces a gauche ou droite
	//print sign
	//si precision on peut print 0
	//print content
}

int		print_arg(t_printf *pr, t_arg *arg)
{
	int	count;
	t_formatted f;

	t_formatted_init(&f);
	count += handle_specifier(&arg, &f);
	count += handle_flags(&arg, &f);
	count += handle_width(&arg, &f)
	do_print(&f);
	t_formatted_free(&f);
	return (count);
}