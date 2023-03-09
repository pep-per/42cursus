/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:59:34 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/09 23:08:48 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_deque(t_deque *deque, int count)
{
	deque->data = (int *)malloc(sizeof(int) * count);
	if (!deque->data)
		return (0);
	deque->front = 0;
	deque->rear = 0;
	deque->len = 0;
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

t_stack	set_stack(int argc, char **argv)
{
	t_stack	stack;
	int		*data;
	int		*copy;
	int		*sorted;
	int		count;

	count = count_data(argv, ' ');
	data = get_data(argv, data, count);
	if (is_duplicate(data, count))
		free_error(data);
	if (is_sorted(data, count))
	{
		free(data);
		exit(1);
	}
	if (!initialize_stack(&stack, data, count))
		free_error(data);
	copy = (int *)malloc(sizeof(int) * count);
	if (!copy)
		free_all_error(&stack, data);
	ft_quick_sort(ft_memcpy(copy, data, sizeof(data)), 0, count - 1);
	index_data(data, count, copy, &stack);
	return (stack);
}
