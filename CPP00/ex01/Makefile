# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 15:28:38 by jiyeolee          #+#    #+#              #
#    Updated: 2023/11/20 21:27:01 by jiyeolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	phonebook
SRCS 	= 	PhoneBook.cpp \
			Contact.cpp \
			main.cpp
OBJS 	= 	$(SRCS:.cpp=.o)
CC 		= 	c++
CFLAGS 	= 	-Wall -Wextra -Werror -std=c++98
INCLUDE =	-I ./PhoneBook.hpp -I ./Contact.hpp

all 	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

%.o 	:	%.c
			$(CC) -c $(CFLAGS) $^ -o $@ $(INCLUDE)

clean 	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:
			make fclean
			make all

.PHONY	:	all re clean fclean bonus
