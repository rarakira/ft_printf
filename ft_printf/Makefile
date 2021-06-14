NAME = libftprintf.a

LIBFT = libft

CFILES =	ft_printf.c					print_control_string.c\
			print_arg.c					get_arg.c\
			modify_arg.c\
			trim_and_align_str.c		trim_and_align_digit.c\
			ft_itoa_d.c					ft_itoa_u.c\
			ft_itoa_x.c					ft_itoa_f.c\
			ft_itoa_f_utils.c\
			convert_arg_s.c				convert_arg_c_prc.c\
			convert_arg_d_u_i_f.c		convert_arg_x_p.c

OBJS = $(CFILES:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra -Iincludes

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT)
	@cp ./libft/libft.a ./$(NAME)
	ar rcs $(NAME) $?

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(NAME)

clean :
	$(MAKE) clean -C $(LIBFT)
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	$(MAKE) fclean -C $(LIBFT)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
