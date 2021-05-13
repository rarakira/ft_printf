# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaela <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 14:03:12 by lbaela            #+#    #+#              #
#    Updated: 2021/05/13 14:39:19 by lbaela           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFILES =	ft_printf.c	

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
