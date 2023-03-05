# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 23:24:12 by jiyeolee          #+#    #+#              #
#    Updated: 2023/01/06 23:24:14 by jiyeolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isdigit.c ft_strlen.c ft_itoa.c ft_strdup.c \
		ft_putstr_free.c ft_uitoa.c ft_put_hexa.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -c -Wall -Wextra -Werror
AR = ar -rc

all : $(NAME)

$(NAME) : $(OBJS)
		$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	fclean
	all

.PHONY: all re clean fclean