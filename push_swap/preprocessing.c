/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:59:34 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/01 20:09:05 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize(t_stack *stack, int size)
{
	stack->data = (int *)malloc(sizeof(int) * size);
	if (!stack->data)
		return (0);
	stack->front = 0;
	stack->rear = 0;
	stack->len = 0;
	return (1);
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

void	set_stack(t_stack *stack, t_info *info, char **argv)
{
	int		*data;
	int		*copy;

	info->size = count_data(argv, ' ') + 1;
	data = (int *)malloc(sizeof(int) * info->size);
	if (!data)
		error_exit();
	get_data(argv, data, info->size - 1);
	if (is_duplicate(data, info->size))
		free_error(data);
	if (is_sorted(data, info->size))
	{
		free(data);
		exit(1);
	}
	if (!initialize(stack, info->size))
		free_error(data);
	copy = (int *)malloc(sizeof(int) * info->size);
	if (!copy)
		free_all_error(stack, data);
	ft_memcpy(copy, data, sizeof(int) * info->size);
	ft_quick_sort(copy, 0, info->size - 2);
	index_data(data, info->size - 1, copy, stack);
}
