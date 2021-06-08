# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaela <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 14:03:12 by lbaela            #+#    #+#              #
#    Updated: 2021/06/08 16:25:52 by lbaela           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFILES =	ft_printf.c				print_control_string.c\
			print_arg.c				get_arg.c					modify_arg.c\
			trim_and_align_str.c	trim_and_align_digit.c\
			ft_itoa_d.c				ft_itoa_u.c					ft_itoa_x.c\
			convert_arg_s.c			convert_arg_c_prc.c\
			convert_arg_d_u_i.c		convert_arg_x_p.c\
			convert_arg_temp.c

OBJS = $(CFILES:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra -Iincludes

all : $(NAME)

$(NAME) : $(OBJS)
	@cd ./libft && make
	@cp ./libft/libft.a ./$(NAME)
	ar rcs $(NAME) $?

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(NAME)

clean :
	@cd ./libft && make clean
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	@cd ./libft && make fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
