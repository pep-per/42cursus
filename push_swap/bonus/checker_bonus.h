/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:39:32 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/21 23:03:12 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"


#include <stdio.h>




typedef struct s_stack
{
	int	*data;
	int	front;
	int	rear;
	int	len;
	int	size;
	int	a;
}	t_stack;

char	*get_next_line(int *error);

void	quick_swap(int arr[], int left, int right);
void	ft_quick_sort(int arr[], int l, int r);
int		*validate_data(char **argv, int size);
void	index_data(int *data, int size, int *sorted);
void	set_stack(t_stack *a, char **argv);

int		count_data(char **s, char c);
int		is_sorted(int *data, int size);
int		is_duplicate(int *data, int size);
void	get_data(char **argv, int *data, int size);

void	initialize_a(t_stack *a, int size, int *data);
void	initialize_b(t_stack *b, int size, int *data);

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

void	error_exit(void);
void	free_strs(char **strs);
void	invalid_data_error(char **strs, int *data);
void	free_error(int *data);

#endif