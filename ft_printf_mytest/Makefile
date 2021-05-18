NAME		= test

SRCS		= main.c

LIB			= ftprintf

LIBDIR		= ../ft_printf

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -I../ft_printf/includes

RM			= rm -f

all:	lib ${NAME}

lib:
		cd ${LIBDIR} && make

${NAME}: ${LIBDIR}/libftprintf.a
		${CC} ${CFLAGS} ${SRCS} -L${LIBDIR} -l${LIB} -o ${NAME}

clean:
		${RM} ${OBJS}
		cd ${LIBDIR} && make clean

fclean:	clean
		${RM} ${NAME}
		cd ${LIBDIR} && make fclean

libft_re:
		cd ${LIBDIR} && make re

re:		fclean all

play: all
		@./test

.PHONY: all clean fclean re test play
