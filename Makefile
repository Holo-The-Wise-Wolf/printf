NAME = libftprintf.a

SRCS = ft_printf.c check.c ft_putspace.c handle_minus.c handle_minus2.c handle_star.c handle_zero.c precision.c print_nbr.c ft_len.c libft.c period_s.c print.c putnbr.c get.c handle_width.c int_neg.c

INCLUDES	= ft_printf.h

OBJS	= ${SRCS:.c=.o}

GCC		= gcc

ARRC	= ar rc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${ARRC} ${NAME} ${OBJS}
			ranlib ${NAME}
all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re :		fclean all

.PHONY:		all clean fclean re
