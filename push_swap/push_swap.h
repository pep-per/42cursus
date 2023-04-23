/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:17:03 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/23 22:47:00 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"

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

void	quick_swap(int arr[], int left, int right);
void	ft_quick_sort(int arr[], int l, int r);
int		*validate_data(char **argv, int size);
void	index_data(int *data, int size, int *sorted);
void	set_stack(t_stack *a, char **argv);

void	plus_count(char *s, char c, int *count);
int		count_data(char **s, char c);
int		is_sorted(int *data, int size);
int		is_duplicate(int *data, int size);
void	get_data(char **argv, int *data, int size);

void	initialize_a(t_stack *a, int size, int *data);
void	initialize_b(t_stack *b, int size, int *data);

void	get_three(t_stack *a, int *first, int *second, int *third);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);

void	partitioning(t_stack *a, t_stack *b, int pivot1, int pivot2);

void	optimize_rotation(t_stack *a, int data);
int		is_right_position(t_stack *a, int curr, int next, int new);
int		count_to_top(t_stack *a, int data);
int		count_move_in_a(t_stack *a, t_move *move, int new);
int		count_move_in_b(t_stack *b, t_move *move, int data);

int		sum_move_count(t_stack *a, t_stack *b, t_move *move, int data);
void	select_optimal_choice(t_stack *a, t_stack *b, t_move *move);
void	double_move(t_stack *a, t_stack *b, t_move *move);
void	double_move_reverse(t_stack *a, t_stack *b, t_move *move);
void	run_optimal_move(t_stack *a, t_stack *b, t_move *move);

void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);

void	rotate_double(t_stack *a, t_stack *b);
void	reverse_rotate_double(t_stack *a, t_stack *b);
void	swap_double(t_stack *a, t_stack *b);

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