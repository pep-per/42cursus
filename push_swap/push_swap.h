/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:17:03 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/14 21:53:32 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"
# include "./ft_printf/mandatory/ft_printf.h"
// # define CHUNK_CONSTANT 50
// # define CHUNK_MIN_CONSTANT 3

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

void	sort_stack(t_stack *a, t_info *info);

int		rotate(t_stack *stack, t_info *info);
int		reverse_rotate(t_stack *stack, t_info *info);
int		swap(t_stack *stack, t_info *info);
int		push(t_stack *from, t_stack *to, t_info *info);

void	push_front(t_stack *stack, int n, int size);
void	push_rear(t_stack *stack, int n, int size);
int		pop_front(t_stack *stack, int size);
int		pop_rear(t_stack *stack, int size);

void	print_operations(char *output);

void	error_exit(void);
void	free_strs(char **strs);
void	invalid_data_error(char **strs, int *data);
void	free_all_error(t_stack *stack, int *data);
void	free_error(int *data);

#endif