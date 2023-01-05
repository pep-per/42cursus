NAME = libftprintf.a
SRCS = ./mandatory/ft_printf_bonus.c ./mandatory/type_bonus.c ./mandatory/option_bonus.c \
			./mandatory/init_bonus.c ./mandatory/ft_put_bonus.c ./mandatory/exception_handling_bonus.c
BONUS_SRCS = ./bonus/ft_printf_bonus.c ./bonus/type_bonus.c ./bonus/option_bonus.c \
			./bonus/init_bonus.c ./bonus/ft_put_bonus.c ./bonus/exception_handling_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC = cc
CFLAGS = -c -Wall -Wextra -Werror
AR = ar -rc
libft = make -C ./Libft libft.a

all : $(NAME)

bonus : $(NAME)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME) : $(BONUS_OBJS)
		$(libft)
		cp ./Libft/libft.a $@
		$(AR) $@ $^
else
$(NAME) : $(OBJS)
		$(libft)
		cp ./Libft/libft.a $@
		$(AR) $@ $^
endif

%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@

clean :
		make -C ./Libft clean
		rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
		rm -rf $(NAME) ./Libft/libft.a

re :
	make fclean
	make all

.PHONY: all re clean fclean bonus