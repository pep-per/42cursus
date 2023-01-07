# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 22:56:13 by jiyeolee          #+#    #+#              #
#    Updated: 2023/01/07 19:56:35 by jiyeolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ./mandatory/ft_printf.c ./mandatory/type.c \
		./mandatory/precision.c ./mandatory/width.c \
		./mandatory/init.c ./mandatory/ft_put.c \
		./mandatory/exception_handling.c
BONUS_SRCS = ./bonus/ft_printf_bonus.c ./bonus/type_bonus.c \
			./bonus/precision_bonus.c ./bonus/width_bonus.c \
			./bonus/init_bonus.c ./bonus/ft_put_bonus.c \
			./bonus/exception_handling_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC = cc
CFLAGS = -c -Wall -Wextra -Werror
AR = ar -rcs

all : $(NAME)

bonus : $(NAME)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME) : $(BONUS_OBJS)
	make -C ./Libft libft.a
	cp ./Libft/libft.a $@
	$(AR) $@ $^
else
$(NAME) : $(OBJS)
	make -C ./Libft libft.a
	cp ./Libft/libft.a $@
	$(AR) $@ $^
endif

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

.PHONY: all re clean fclean bonus