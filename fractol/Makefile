# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 22:58:21 by jiyeolee          #+#    #+#              #
#    Updated: 2023/05/08 07:04:53 by jiyeolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = 	main.c \
		preprocessing.c \
		image.c \
		hook.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -LLibft -lft -Lmlx -lmlx 
LDFLAGS = -framework OpenGL -framework Appkit -Imlx
FT = ./Libft
MLX = ./mlx
all 	:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C $(FT) all
			$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS) $^ -o $@

%.o 	:	%.c
			$(CC) $(CFLAGS) -c $^ -o $@

clean 	:
			make -C $(FT) clean
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME) $(FT)/libft.a
			
re		:
			make fclean
			make all

.PHONY	:	all re clean fclean
