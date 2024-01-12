NAME 	=	ex00
SRCS 	= main.cpp \
				Animal.cpp \
				Cat.cpp \
				Dog.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp
OBJS 	= 	$(SRCS:.cpp=.o)
CC 		= 	c++
CFLAGS 	= 	-Wall -Wextra -Werror -std=c++98
INCLUDE =	-I ./Animal.hpp -I Dog.hpp -I Cat.hpp -I WrongAnimal.hpp -I WrongCat.hpp

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