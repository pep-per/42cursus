NAME 	= 	megaphone
SRCS 	= 	megaphone.cpp
OBJS 	= 	$(SRCS:.cpp=.o)
CC 		= 	c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98

all 	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

%.o 	:	%.cpp
			$(CC) -c $(CFLAGS) $^ -o $@

clean 	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:
			make fclean
			make all

.PHONY	:	all re clean fclean
