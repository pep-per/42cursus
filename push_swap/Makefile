# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 22:58:21 by jiyeolee          #+#    #+#              #
#    Updated: 2023/04/21 21:45:19 by jiyeolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
SRCS = 	main.c \
		preprocessing.c \
		parsing.c \
		initialization.c \
		sorting.c \
		partitioning.c \
		greedy.c \
		optimization.c \
		operation1.c \
		operation2.c \
		stack1.c \
		stack2.c \
		printing.c \
		error_handling.c
BONUS_SRCS = ./bonus/checker_bonus.c \
			 ./bonus/get_next_line_bonus.c \
			./bonus/preprocessing.c \
			./bonus/parsing.c \
			./bonus/initialization.c \
			./bonus/operation1.c \
			./bonus/operation2.c \
			./bonus/stack1.c \
			./bonus/stack2.c \
			./bonus/error_handling.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LFLAGS = -LLibft -lft
LIB = ./Libft

all 	:	$(NAME)

bonus	:	$(BONUS)

$(NAME)	:	$(OBJS)
			make -C $(LIB) all
			$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(BONUS):	$(BONUS_OBJS)
			make -C $(LIB) all
			$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS) -I ./bonus

%.o 	:	%.c
			$(CC) -c $(CFLAGS) $^ -o $@ -I ./bonus

clean 	:
			make -C $(LIB) clean
			rm -rf $(OBJS) $(BONUS_OBJS)

fclean	:	clean
			rm -rf $(NAME) $(BONUS) $(LIB)/libft.a

re		:
			make fclean
			make all

.PHONY	:	all re clean fclean bonus
