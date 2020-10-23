NAME = libftprintf.a

SRCS = ft_printf.c parser.c print.c utils.c handle.c specifier.c specifier_bonus.c struct.c utils_2.c parser_length_bonus.c

INCLUDES	= ft_printf.h

OBJS	= ${SRCS:.c=.o}

GCC		= gcc

ARRC	= ar rc

RM		= rm -f

CFLAGS	= -g -Wall -Wextra -Werror

.c.o:
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${ARRC} ${NAME} ${OBJS}
			ranlib ${NAME}
all:		${NAME}

bonus:	all

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re :		fclean all

.PHONY:		all clean fclean re
