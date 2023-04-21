/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:38:28 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/21 22:13:46 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted_result(t_stack *a)
{
	int	i;
	int	next;

	i = a->rear;
	next = (i - 1 + a->size) % a->size;
	while (i != front(a))
	{
		if (a->data[i] < a->data[next])
			return (0);
		i = (i - 1 + a->size) % a->size;
		next = (i - 1 + a->size) % a->size;
	}
	return (1);
}

void	check_sorting(t_stack *a, t_stack *b)
{
	if (is_sorted_result(a) && b->len == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	execute_command(char *input, int *error, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(input, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp(input, "sb\n", 3))
		swap(b);
	else if (!ft_strncmp(input, "ss\n", 3))
		swap_double(a, b);
	else if (!ft_strncmp(input, "pa\n", 3))
		push(b, a);
	else if (!ft_strncmp(input, "pb\n", 3))
		push(a, b);
	else if (!ft_strncmp(input, "ra\n", 3))
	{
		printf("res %d\n", ft_strncmp(input, "ra\n", 3));
		rotate(a);
	}
	else if (!ft_strncmp(input, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(input, "rr\n", 3))
		rotate_double(a, b);
	else if (!ft_strncmp(input, "rra\n", 4))
		reverse_rotate(a);
	else if (!ft_strncmp(input, "rrb\n", 4))
		reverse_rotate(b);
	else if (!ft_strncmp(input, "rrr\n", 4))
		reverse_rotate_double(a, b);
	else
		*error = 1;
}

void	check_command(t_stack *a, t_stack *b)
{
	char	*input;
	int		error;

	error = 0;
	input = get_next_line(&error);
	while (input)
	{
		printf("input %s\n", input);
		execute_command(input, &error, a, b);
		for (int i = front(a); i != (a->rear + 1 + a->size) % a->size; i = (i + 1 + a->size) % a->size)
			printf("%d\n", a->data[i]);

		if (error)
			break ;
		free(input);
		input = get_next_line(&error);
	}
	free(input);
	if (error)
	{
		free(a->data);
		free(b->data);
		write(2, "Error\n", 6);
		exit(1);
	}
	check_sorting(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		return (0);
	set_stack(&a, &argv[1]);
	initialize_b(&b, a.size, a.data);
	check_command(&a, &b);
	free(b.data);
	free(a.data);
	return (0);
}
