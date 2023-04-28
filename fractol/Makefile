# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 22:58:21 by jiyeolee          #+#    #+#              #
#    Updated: 2023/04/26 23:06:40 by jiyeolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = 	main.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIB = -LLibft -lft -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
LIB = ./Libft
MLX = ./mlx
all 	:	$(NAME)

bonus	:	$(BONUS)

$(NAME)	:	$(OBJS)
			make -C $(LIB) all
			$(CC) $(CFLAGS) $(CLIB) $^ -o $@

$(BONUS):	$(BONUS_OBJS)

%.o 	:	%.c
			$(CC) -c $(CFLAGS) $^ -o $@ -I ./bonus

clean 	:
			make -C $(LIB) clean
			make -C $(MLX) clean
			rm -rf $(OBJS) $(BONUS_OBJS)

fclean	:	clean
			rm -rf $(NAME) $(BONUS) $(LIB)/libft.a
			
re		:
			make fclean
			make all

.PHONY	:	all re clean fclean bonus
