# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 22:56:13 by jiyeolee          #+#    #+#              #
#    Updated: 2023/03/02 00:50:18 by jiyeolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ./mandatory/ft_printf.c ./mandatory/type.c \
		./mandatory/precision.c ./mandatory/width.c \
		./mandatory/init.c ./mandatory/ft_put.c \
		./mandatory/exception_handling.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -c -Wall -Wextra -Werror
AR = ar -rcs

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./Libft libft.a
	cp ./Libft/libft.a $@
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@

clean :
	make -C ./Libft clean
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME) ./Libft/libft.a

re :
	make fclean
	make all

.PHONY: all re clean fclean