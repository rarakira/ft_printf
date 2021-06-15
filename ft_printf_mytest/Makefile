NAME		= test

SRCS		= main.c	# ${wildcard ${LIBDIR}/*.c}

OBJS		= ${SRCS:.c=.o}

SRC2		= main-2.c

LIB			= ftprintf

LIBDIR		= ../ft_printf

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I../ft_printf/includes

RM			= rm -f

all:	${NAME}

lib:
		${MAKE} -C ${LIBDIR}

${NAME}: lib ${OBJS}	
		${CC} ${CFLAGS} ${OBJS} -L${LIBDIR} -l${LIB} -o ${NAME}

%.o : %.c
		${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

2 :
		${CC} ${CFLAGS} ${INCLUDES} ${SRC2} -L${LIBDIR} -l${LIB} -o ${NAME}

norm_a:
	@norminette ${LIBDIR}/*.c ${LIBDIR}/*/*.c

norm:
	@norminette ${LIBDIR}/*.c ${LIBDIR}/arg_parser/*.c	\
	${LIBDIR}/str_converter/*.c ${LIBDIR}/includes

clean:
		${RM} ${OBJS}
		${MAKE} clean -C ${LIBDIR}

fclean:	clean
		${RM} ${NAME}
		${MAKE} fclean -C ${LIBDIR}

lib_re:
		${MAKE} re -C ${LIBDIR}

re:		fclean all

play: all
		@./test

leaks: all
		@valgrind --leak-check=full --show-leak-kinds=all ./test

.PHONY: all clean fclean re test play leaks norm
