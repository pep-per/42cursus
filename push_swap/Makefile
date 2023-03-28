# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 22:58:21 by jiyeolee          #+#    #+#              #
#    Updated: 2023/03/28 06:12:19 by jiyeolee         ###   ########.fr        #
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
		range.c \
		operation.c \
		stack1.c \
		stack2.c \
		printing.c \
		error_handling.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
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
