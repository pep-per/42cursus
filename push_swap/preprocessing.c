/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:59:34 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/05 14:17:04 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_a(t_stack *a, int size, int *data)
{
	a->data = (int *)malloc(sizeof(int) * size);
	if (!a->data)
		free_error(data);
	a->front = size - 1;
	a->rear = size - 2;
	a->len = size - 1;
	a->size = size;
	a->a = 1;
}

void	initialize_b(t_stack *b, int size, int *data)
{
	b->data = (int *)malloc(sizeof(int) * size);
	if (!b->data)
		free_error(data);
	b->front = 0;
	b->rear = 0;
	b->len = 0;
	b->size = size;
	b->a = 0;
}


void	ft_quick_sort(int arr[], int l, int r)
{
	int	left;
	int	right;
	int	pivot;
	int	temp;

	left = l;
	right = r;
	pivot = arr[(l + r) / 2];
	while (left <= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}
	if (l < right)
		ft_quick_sort(arr, l, right);
	if (left < r)
		ft_quick_sort(arr, left, r);
}

int	*validate_data(char **argv, int size)
{
	int	*data;

	data = (int *)malloc(sizeof(int) * size);
	if (!data)
		error_exit();
	get_data(argv, data, size);
	if (is_duplicate(data, size) || size == 0)
		free_error(data);
	if (is_sorted(data, size))
	{
		free(data);
		exit(1);
	}
	return (data);
}

void	set_stack(t_stack *a, char **argv)
{
	int		*data;
	int		*copy;
	int		size;

	size = count_data(argv, ' ');
	data = validate_data(argv, size);
	initialize_a(a, size + 1, data);
	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		free_all_error(a, data);
	ft_memcpy(copy, data, sizeof(int) * size);
	ft_quick_sort(copy, 0, a->size - 2);
	index_data(data, size, copy, a);
}
