# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 22:58:21 by jiyeolee          #+#    #+#              #
#    Updated: 2023/04/25 20:37:00 by jiyeolee         ###   ########.fr        #
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
			./bonus/preprocessing_bonus.c \
			./bonus/parsing_bonus.c \
			./bonus/initialization_bonus.c \
			./bonus/operation1_bonus.c \
			./bonus/operation2_bonus.c \
			./bonus/stack1_bonus.c \
			./bonus/stack2_bonus.c \
			./bonus/error_handling_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
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
