NAME 	=	ex01
SRCS 	= main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp
OBJS 	= 	$(SRCS:.cpp=.o)
CC 		= 	c++
CFLAGS 	= 	-Wall -Wextra -Werror -std=c++98
INCLUDE =	-I ./ClapTrap.hpp -I ./ScavTrap.hpp

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

.PHONY	:	all re clean fclean