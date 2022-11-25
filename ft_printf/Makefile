NAME = libftprintf.a
SRCS = printf.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -c -Wall -Wextra -Werror
AR = ar -rc

libft : make libft.a -C ./Libft

all : $(NAME)

$(NAME) : libftprintf.a $(OBJS)
		libft
		cp ./Libft/libft.a libftprintf.a 
		$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	fclean
	all

.PHONY: all re clean fclean libft