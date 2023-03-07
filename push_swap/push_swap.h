/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:17:03 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/07 22:06:35 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"
# include "./ft_printf/mandatory/ft_printf.h"
// # define INT_MAX 2147483647

typedef struct s_deque
{
	int	*data;
	int	front;
	int	rear;
	int	len;
}	t_deque;

typedef struct s_stack
{
	t_deque	a;
	t_deque	b;
	int		size;
	int		pivot1;
	int		pivot2;
}	t_stack;

enum e_cmd
{
	// DOUB,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

void	display_error(void);
void	free_strs(char **strs);
void	invalid_data_error(char **strs, int *data);
void	duplicate_data_error(int *data);


#endif