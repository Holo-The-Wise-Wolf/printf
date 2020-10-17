#include "ft_printf.h"

void	t_arg_init(t_arg *arg)
{
	arg->flags		= 0;
	arg->width		= 0;
	arg->precision	= 0;
	arg->length		= '\0';
	arg->specifier	= '\0';
}

t_arg	parse_arg(t_printf *pr)
{
	t_arg arg;

	arg.flags		= parse_flags(pr);
	arg.width		= parse_width(pr);
	arg.precision	= parse_precision(pr);
	arg.length		= parse_length(pr);
	arg.specifier	= parse_specifier(pr);

	return arg;
}

long	parse_flags(t_printf *pr)
{
	long	flags = 0;

	while (corresponding(pr->fmt[pr->i], "-+ #0"))
	{
		if (pr->fmt[pr->i] == '-')
			flags |= LEFT_JUSTIFY;
		if (pr->fmt[pr->i] == '+')
			flags |= SHOW_SIGN;
		if (pr->fmt[pr->i] == ' ')
			flags |= NO_SIGN;
		if (pr->fmt[pr->i] == '#')
			flags |= SHOW_PREFIX;
		if (pr->fmt[pr->i] == '0')
			flags |= PAD_ZERO;

		pr->i += 1;
	}

	return flags;
}

int		parse_width(t_printf *pr)
{
	int		width = 0;

	while (corresponding(pr->fmt[pr->i], "*0123456789"))
	{
		if (pr->fmt[pr->i] == '*')
			width = va_arg(pr->args, int);
		else
		{
			width = width * 10 + (pr->fmt[pr->i] - '0');
		}
		pr->i += 1;
	}

	return (width);
}

int		parse_precision(t_printf *pr)
{
}

char	parse_length(t_printf *pr)
{
}

char	parse_specifier(t_printf *pr)
{
}
