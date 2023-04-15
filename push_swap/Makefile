# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 22:58:21 by jiyeolee          #+#    #+#              #
#    Updated: 2023/04/14 16:42:45 by jiyeolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = 	main.c \
		preprocessing.c \
		parsing.c \
		indexing.c \
		Initialization.c \
		sorting.c \
		partitioning.c \
		greedy.c \
		operation.c \
		stack1.c \
		stack2.c \
		printing.c \
		error_handling.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -LLibft -lft
LIB = ./Libft

all 	:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C $(LIB) all
			$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS) -fsanitize=address

%.o 	:	%.c
			$(CC) -c $(CFLAGS) $^ -o $@

clean 	:
			make -C $(LIB) clean
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME) $(LIB)/libft.a

re		:
			make fclean
			make all

.PHONY	:	all re clean fclean lib
