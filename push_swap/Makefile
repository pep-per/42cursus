# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 22:58:21 by jiyeolee          #+#    #+#              #
#    Updated: 2023/03/21 22:44:57 by jiyeolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = 	main.c \
		preprocessing.c \
		parsing.c \
		indexing.c \
		sorting.c \
		greedy_a.c \
		greedy_b.c \
		searching.c \
		operation.c \
		stack.c \
		printing.c \
		error_handling.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -c -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)

%.o : %.c
	make -C ./Libft all
	$(CC) $(CFLAGS) $^ -o $@

lib :
	make -C ./Libft all

clean :
	make -C ./Libft clean
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) ./Libft/libft.a

re :
	make fclean
	make all

.PHONY: all re clean fclean lib