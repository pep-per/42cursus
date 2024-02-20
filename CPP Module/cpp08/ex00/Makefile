NAME			=	ex00
SRCS			=	main.cpp
OBJS 			=	$(SRCS:.cpp=.o)
CC 				= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CPPFLAGS 	= -I./easyfind.hpp

all		 	:	$(NAME)

$(NAME)	:	$(OBJS)
					$(CC) $(CXXFLAGS) $^ -o $@

%.o 		:	%.c
					$(CC) -c $(CXXFLAGS) $^ -o $@ $(CPPFLAGS)

clean 	:
					rm -rf $(OBJS)

fclean	:	clean
					rm -rf $(NAME)

re			:
					make fclean
					make all

.PHONY	:	all re clean fclean