# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaela <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 14:03:12 by lbaela            #+#    #+#              #
#    Updated: 2021/05/25 12:55:04 by lbaela           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFILES =	ft_printf.c			print_control_string.c		print_arg.c	\
			check_format.c		trim_and_align.c			ft_itoa_d.c\
			convert_arg_s.c		convert_arg_c.c\
			convert_arg_d.c		convert_arg_u.c\
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

clean :
	@cd ./libft && make clean
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	@cd ./libft && make fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
