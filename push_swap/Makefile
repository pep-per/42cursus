# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 22:58:21 by jiyeolee          #+#    #+#              #
#    Updated: 2023/03/02 01:32:31 by jiyeolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = main.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -c -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)

%.o : %.c
	$(lib)
	$(CC) $(CFLAGS) $^ -o $@  -LLibft -lft

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