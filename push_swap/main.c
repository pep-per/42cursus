/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:29:11 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/05 22:43:45 by jiyeolee         ###   ########.fr       */
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

void	initialize_stack(t_stack *stack, int size)
{
	initialize_deque(&stack->a, size);
	initialize_deque(&stack->b, size);
	stack->size = size;
	stack->pivot1 = 0;
	stack->pivot2 = 0;
}



int	is_duplicate(int **arrays)
{
	int	i;
	int	j;

	i = 0;
	while (arrays[i])
	{
		j = 0;
		while (arrays[i][j])
		{
			if (arrays[i][j] == )
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}



void	fill_stack()
{

}

int	*get_data(char *argv, int **arrays)
{
	char	**strs;
	int		i;
	int		num;
	int		count;
	int		*array;

	strs = ft_split(argv, ' ');
	count = 0;
	while (strs[count])
		count++;
	array = (int *)malloc(sizeof(int) * count);
	i = 0;
	while (strs[i])
	{
		if (!ft_atoi_valid(strs[i], &num))
			invalid_data_error(strs, arrays);
		array[i] = num;
		i++;
	}
	free_strs(strs);
	return (array);
}

t_stack	set_stack(int argc, char **argv)
{
	t_stack	stack;
	int		**arrays;
	int		i;

	arrays = (int **)malloc(sizeof(int *) * (argc - 1));
	i = 0;
	while (argv[i])
	{
		arrays[i] = get_data(argv[i], arrays);
		i++;
	}
	initialize_stack(&stack, arrays);
	fill_stack();
	if (is_duplicate(stack.a.data))
		duplicate_datat_error();
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
