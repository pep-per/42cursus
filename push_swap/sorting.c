/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:42:00 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/14 22:14:53 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmd(int cmd)
{
	if (cmd == SA)
		write(1, "sa\n", 3);
	else if (cmd == SB)
		write(1, "sb\n", 3);
	else if (cmd == SS)
		write(1, "ss\n", 3);
	else if (cmd == PA)
		write(1, "pa\n", 3);
	else if (cmd == PB)
		write(1, "pb\n", 3);
	else if (cmd == RA)
		write(1, "ra\n", 3);
	else if (cmd == RB)
		write(1, "rb\n", 3);
	else if (cmd == RR)
		write(1, "rr\n", 3);
	else if (cmd == RRA)
		write(1, "rra\n", 4);
	else if (cmd == RRB)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
}

void	sort_small(t_stack *a, t_info *info)
{
	int	*data;

	info->a = 1;
	data = a->data;
	if (info->size == 2)
	{
		if (data[0] > data[1])
			print_cmd(swap(a, info));
		return ;
	}
	if (data[0] < data[1] && data[1] > data[2])
	{
		print_cmd(reverse_rotate(a, info));
	}
	else if (data[0] > data[1])
	{
		if (data[0] > data[2])
			print_cmd(rotate(a, info));
	}
	if (data[0] > data[1])
		print_cmd(swap(a, info));
}

// void	a_to_b(int chunk_idx, t_stack *a, t_stack *b, t_info *info)
// {
// 	int	i;

// 	info->a = 0;
// 	i = chunk_idx * CHUNK_CONSTANT;
// 	while (i < (chunk_idx + 1) * CHUNK_CONSTANT)
// 	{
// 		push(a, b, info);
// 		i++;
// 	}
// }

void	a_to_b(int chunk_idx, t_stack *a, t_stack *b, t_info *info)
{
	int	i;
	int	min;
	int	max;

	info->a = 0;
	i = 0;
	while (i < info->size)
	{
		to_
		push(a, b, info);
		i++;
	}
}

void	greedy()
{
		min = find_min();
		max = find_max();
	
}
	//idx < len / 2 -> rb
	//idx > len / 2 -> rrb

void	b_to_a()
{
	//rb
	//rrb
	
}

int	in_range()
{

}

int	partition()
{

}

void	sort_complex(t_stack *a, t_stack *b, t_info *info)
{
	int	chunk_idx;
	int	min;
	int	max;
	int	pivot;

	chunk_idx = (info->size / 3);
	while ()
	{
		pivot = partition();
		// a_to_b(chunk_idx, a, b, info);
		greedy();
		// b_to_a();
		chunk_idx++;
	}

	// while (chunk_idx < chunk_cnt)
	// {
	// 	a_to_b(chunk_idx, a, b, info);
	// 	greedy();
	// 	b_to_a();
	// 	chunk_idx++;
	// }
}

void	sort_stack(t_stack *a, t_info *info)
{
	t_stack	b;

	if (!initialize(&b, info->size))
		free_error(a->data);
	if (info->size <= 3)
		sort_small(a, info);
	else
		sort_complex(a, &b, info);
	free(a->data);
	free(b.data);
}
