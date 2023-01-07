# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 22:56:22 by jiyeolee          #+#    #+#              #
#    Updated: 2023/01/07 19:25:48 by jiyeolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_put.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -c -Wall -Wextra -Werror
AR = ar -rcs

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./Libft libft.a
	cp ./Libft/libft.a libftprintf.a
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@

clean :
	make -C ./Libft clean
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) ./Libft/libft.a

re :
	make fclean
	make all

.PHONY: all re clean fclean