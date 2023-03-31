/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:55:57 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/31 23:17:15 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	put_min_or_max_on_top(int idx, t_stack *b, t_info *info)
// {
// 	int	to_push;

// 	if (idx == NOTHING_TO_PUSH)
// 		return ;
// 	to_push = b->data[idx];
// 	if (in_upper(idx, b))
// 	{
// 		while (b->data[a->front] != to_push)
// 			print_operation(rotate(b, info));
// 	}
// 	else
// 	{
// 		while (a->data[a->front] != to_push)
// 			print_operation(reverse_rotate(b, info));
// 	}
// }
void	arrange_chunk(t_stack *a, t_info *info, int chunk_idx)
{
	if (chunk_idx == 0)
	{
		while (get_bottom(a) != info->max)
			print_operation(rotate(a, info));
		// printf("max : %d\n", info->max);
	}
	else
	{
		while (get_top(a, info->size) != info->min)
			print_operation(reverse_rotate(a, info));
		// printf("min : %d\n", info->max);
		
	}
}

void	greedy_on_b(t_stack *b, t_info *info, int min, int max)
{	
	int	min_idx;
	int	max_idx;
	int	op_count1;
	int	op_count2;

	min_idx = search(b, info, min, &op_count1);
	max_idx = search(b, info, max, &op_count2);
	if (op_count1 + 1 < op_count2)
	{
		if (in_upper(min_idx, b))
			put_on_top_ra(op_count1, b, info);
		else
			put_on_top_rra(op_count1, b, info);
	}
	else
	{
		if (in_upper(max_idx, b))
			put_on_top_ra(op_count2, b, info);
		else
			put_on_top_rra(op_count2, b, info);
	}
}

int	greedy_example_b(t_stack *b, t_info *info, int min, int max)
{
	int	index;
	int	count;
	int flag;

	count = 0;
	index = (b->front + 1 + info->size) % info->size;
	while (index != b->front)
	{
		if (b->data[index] == min)
		{
			flag = 1;
			break;
		}
		else if (b->data[index] == max)
		{
			flag = 0;
			break;
		}
		count++;
		index = (index + 1 + info->size) % info->size;
	}
	if (count > info->size / 2)
	{
		count = info->size - count;
		while (count)
		{
			reverse_rotate(b, info);
			count--;
		}
	}
	else
	{
		while (count)
		{
			rotate(b, info);
			count--;
		}
	}
	if (flag == 1)
		return (1);
	else
		return (0);
}

void	b_to_a(t_stack *a, t_stack *b, t_info *info, int chunk)
{
	int	min;
	int	max;

	min = info->min;
	max = info->max;
	info->a = 0;
	while (chunk > 0)
	{
		greedy_on_b(b, info, min, max);
//      value = greedy_example(b, info ...)
		print_operation(push(b, a, info));
//		if (value == 1)
//			rotate(a,info);
//          min++;
//		else if (value == 0)
//			max--;
		if (get_top(a, info->size) == min)
		{
			print_operation(rotate(a, info));
			min++;
		}
		else
			max--;
		chunk--;
	}
}
