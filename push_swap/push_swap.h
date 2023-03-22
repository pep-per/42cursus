/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:17:03 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/22 17:34:32 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"
// # include "./ft_printf/mandatory/ft_printf.h"
# define NOTHING_TO_PUSH -1
// # define CHUNK_MIN_CONSTANT 3





# include <stdio.h>








typedef struct s_stack
{
	int	*data;
	int	front;
	int	rear;
	int	len;
}	t_stack;

typedef struct s_info
{
	int	size;
	int	pivot1;
	int	pivot2;
	int	a;
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

int		initialize(t_stack *stack, int size);
void	ft_quick_sort(int arr[], int l, int r);
void	set_stack(t_stack *stack, t_info *info, char **argv);

int		count_data(char **s, char c);
int		is_sorted(int *data, int size);
int		is_duplicate(int *data, int size);
int		*get_data(char **argv, int *data, int size);

void	index_data(int *data, int size, int *sorted, t_stack *stack);

void	sort_small(t_stack *a, t_info *info);
void	sort_complex(t_stack *a, t_stack *b, t_info *info);
void	sort_stack(t_stack *a, t_info *info);

int		search_from_top(int limit_min, int limit_max, t_stack *a);
int		search_from_bottom(int limit_min, int limit_max, t_stack *a);
int		search(int num, t_stack *b);

int		count_rotation(t_stack *stack, int idx);
void	put_on_top(int idx, t_stack *stack, t_info *info);
void	greedy_on_a(int limit_min, int limit_max, t_stack *a, t_info *info);
void	a_to_b(t_stack *a, t_stack *b, t_info *info, int chunk_idx);

void	greedy_on_b(t_stack *a, t_stack *b, t_info *info);
void	b_to_a(t_stack *a, t_stack *b, t_info *info);

int		rotate(t_stack *stack, t_info *info);
int		reverse_rotate(t_stack *stack, t_info *info);
int		swap(t_stack *stack, t_info *info);
int		push(t_stack *from, t_stack *to, t_info *info);

void	push_front(t_stack *stack, int n, int size);
void	push_rear(t_stack *stack, int n, int size);
int		pop_front(t_stack *stack, int size);
int		pop_rear(t_stack *stack, int size);

int		in_upper(int idx, t_stack *stack);
int		in_range(int limit_min, int limit_max, int idx);
int		in_order(t_stack *a);
int		is_min_or_max_on_top(t_stack *a, int data);

void	print_operation(int op);

void	error_exit(void);
void	free_strs(char **strs);
void	invalid_data_error(char **strs, int *data);
void	free_all_error(t_stack *stack, int *data);
void	free_error(int *data);

#endif