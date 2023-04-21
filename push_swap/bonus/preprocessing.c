/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:59:34 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/21 23:02:17 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	quick_swap(int arr[], int left, int right)
{
	int	temp;

	temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

void	ft_quick_sort(int arr[], int l, int r)
{
	int	left;
	int	right;
	int	pivot;

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
			quick_swap(arr, left, right);
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

	data = (int *)malloc(sizeof(int) * (size + 1));
	if (!data)
		error_exit();
	get_data(argv, data, size);
	if (is_duplicate(data, size))
		free_error(data);
	return (data);
}

void	index_data(int *data, int size, int *sorted)
{
	int	i;
	int	idx;

	i = 0;
	while (i < size)
	{
		idx = 0;
		while (sorted[idx] != data[i])
			idx++;
		data[i] = idx;
		i++;
	}
	free(sorted);
}

void	set_stack(t_stack *a, char **argv)
{
	int		*data;
	int		*copy;
	int		size;

	size = count_data(argv, ' ');
	if (size == 0)
		error_exit();
	data = validate_data(argv, size);
	initialize_a(a, size + 1, data);
	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		free_error(data);
	ft_memcpy(copy, data, sizeof(int) * size);
	ft_quick_sort(copy, 0, size - 1);
	index_data(data, size, copy);
}
