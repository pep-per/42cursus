/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:29:11 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/07 22:47:22 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	push_front(int data)
{

}

void	initialize_deque(t_deque *deque, int size)
{
	deque->data = (int *)malloc(sizeof(int) * size);
	if (!deque->data)
		exit(1);
	deque->front = 0;
	deque->rear = 0;
	deque->len = 0;
}

void	initialize_stack(t_stack *stack, int *data, int count)
{
	int	*copy;

	index_data(copy);
	initialize_deque(&stack->a, size);
	initialize_deque(&stack->b, size);
	stack->size = size;
	stack->pivot1 = 0;
	stack->pivot2 = 0;
	free(data);
}

int	is_duplicate(int *data, int count)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (data[i] == data[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	count_data(char **s, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			while (s[i][j] == c)
				j++;
			if (s[i][j])
				count++;
			while (s[i][j] != c && s[i][j])
				j++;
		}
		i++;
	}
	return (count);
}

int	*get_data(char **argv, int *data, int count)
{
	int		i;
	int		j;
	int		k;
	int		num;
	char	*strs;

	data = (int *)malloc(sizeof(int) * count);
	i = 0;
	j = 0;
	k = 0;
	while (i < count)
	{
		strs = ft_split(argv[j++], ' ');
		k = 0;
		while (strs[k])
		{
			if (!ft_atoi_valid(strs[k++], &num))
				invalid_data_error(strs, data);
			data[i++] = num;
		}
		free_strs(strs);
	}
	return (data);
}

int	*index_data(int *data, int count)
{

}

t_stack	set_stack(int argc, char **argv)
{
	t_stack	stack;
	int		*data;
	int		count;

	count = count_data(argv, ' ');
	data = get_data(argv, data, count);
	if (is_duplicate(data, count))
		duplicate_data_error(data);
	initialize_stack(&stack, data, count);
	return (stack);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	// 인자를 받아서 정수 배열로 파싱
	set_stack(argc, &argv[1]);
	// 처음부터 정렬되어 있으면 아무것도 출력 안하기
	return (0);
}
