/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:17:03 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/09 23:09:15 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"
# include "./ft_printf/mandatory/ft_printf.h"
// # define INT_MAX 2147483647

typedef struct s_stack
{
	int	*data;
	int	front;
	int	rear;
	int	len;
}	t_stack;

typedef struct s_info
{
	// t_deque	a;
	// t_deque	b;
	int		size;
	int		pivot1;
	int		pivot2;
}	t_info;

enum e_cmd
{
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

int		initialize_deque(t_deque *deque, int count);
int		initialize_stack(t_stack *stack, int *data, int count);
void	ft_quick_sort(int arr[], int l, int r);
t_stack	set_stack(int argc, char **argv);

int		count_data(char **s, char c);
int		is_sorted(int *data, int count);
int		is_duplicate(int *data, int count);
int		*get_data(char **argv, int *data, int count);

void	index_data(int *data, int count, int *sorted, t_stack *stack);

void	error_exit(void);
void	free_strs(char **strs);
void	invalid_data_error(char **strs, int *data);
void	free_all_error(t_stack *stack, int *data);
void	free_error(int *data);

#endif