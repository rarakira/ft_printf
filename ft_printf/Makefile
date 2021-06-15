NAME = libftprintf.a

LIBFT = libft

CFILES =	ft_printf.c								\
			print_control_string.c					\
			arg_parser/print_arg.c					\
			arg_parser/get_arg.c					\
			arg_parser/modify_arg.c					\
			str_converter/trim_and_align_str.c		\
			str_converter/trim_and_align_digit.c	\
			str_converter/ft_itoa_d.c				\
			str_converter/ft_itoa_u.c				\
			str_converter/ft_itoa_x.c				\
			str_converter/ft_itoa_f.c				\
			str_converter/ft_itoa_f_utils.c			\
			str_converter/convert_arg_s.c			\
			str_converter/convert_arg_c_prc.c		\
			str_converter/convert_arg_d_u_i_f.c		\
			str_converter/convert_arg_x_p.c

OBJS = $(CFILES:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra -Iincludes

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT)
	@cp ./libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(NAME)

clean :
	$(MAKE) clean -C $(LIBFT)
	rm -f $(OBJS)

fclean : clean
	$(MAKE) fclean -C $(LIBFT)
	rm -f $(NAME)

re : fclean all

norme :
	@norminette $(CFILES) includes/*.h libft/*.c

.PHONY : all clean fclean re bonus norme
