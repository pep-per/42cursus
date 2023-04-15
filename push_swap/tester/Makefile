NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = \
		pushswap.c \
		init.c \
		parsing.c \
		preprocessing.c \
		hardcoding.c \
		greedy.c \
		greedy_count.c \
		greedy_locate.c \
		deque.c \
		operations_push_swap.c \
		operations_rotate.c \
		operations_reverse_rotate.c \

OBJS = $(SRCS:.c=.o)
RM = rm -rf

all : $(NAME)

%.o: %.c
	cc $(CFLAGS) -I./ -c $< -o $@

$(NAME) : $(OBJS)
	cc -o $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
