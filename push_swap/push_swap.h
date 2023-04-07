/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:17:03 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/08 05:27:47 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"
// # include "./ft_printf/mandatory/ft_printf.h"
# define ERROR -1
// # define IS_EMPTY -1

// # define CHUNK_MIN_CONSTANT 3





# include <stdio.h>








typedef struct s_stack
{
	int	*data;
	int	front;
	int	rear;
	int	len;
	int	size;
	int	a;
}	t_stack;

typedef struct s_move
{
	int	ra_cnt;
	int	rra_cnt;
	int	rb_cnt;
	int	rrb_cnt;
}	t_move;

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

void	ft_quick_sort(int arr[], int l, int r);
int		*validate_data(char **argv, int size);
void	set_stack(t_stack *a, char **argv);

int		count_data(char **s, char c);
int		is_sorted(int *data, int size);
int		is_duplicate(int *data, int size);
void	get_data(char **argv, int *data, int size);

void	initialize_a(t_stack *a, int size, int *data);
void	initialize_b(t_stack *b, int size, int *data);

void	index_data(int *data, int size, int *sorted);

void	get_three_data(t_stack *a, int *first, int *second, int *third);
void	sort_complex(t_stack *a, t_stack *b);
void	sort_small(t_stack *a);

void	partitioning(t_stack *a, t_stack *b);

void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	swap(t_stack *a);
void	push(t_stack *from, t_stack *to);

void	rotate_double(t_stack *a, t_stack *b);
void	reverse_rotate_double(t_stack *a, t_stack *b);

void	push_front(t_stack *stack, int data);
void	push_rear(t_stack *stack, int data);
int		pop_front(t_stack *stack);
int		pop_rear(t_stack *stack);

int		front(t_stack *stack);
int		top(t_stack *stack);
int		bottom(t_stack *stack);

void	print_operation(int op);

void	error_exit(void);
void	free_strs(char **strs);
void	invalid_data_error(char **strs, int *data);
void	free_error(int *data);

#endif