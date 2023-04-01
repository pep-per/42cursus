/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:55:57 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/01 22:14:29 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// void	greedy_on_b(t_stack *b, t_info *info, int min, int max)
// {	
// 	int	min_idx;
// 	int	max_idx;
// 	int	op_count1;
// 	int	op_count2;

// 	min_idx = search(b, info, min, &op_count1);
// 	max_idx = search(b, info, max, &op_count2);
// 	if (op_count1 + 1 < op_count2)
// 	{
// 		if (in_upper(min_idx, b))
// 			put_on_top_ra(op_count1, b, info);
// 		else
// 			put_on_top_rra(op_count1, b, info);
// 	}
// 	else
// 	{
// 		if (in_upper(max_idx, b))
// 			put_on_top_ra(op_count2, b, info);
// 		else
// 			put_on_top_rra(op_count2, b, info);
// 	}
// }
// int	greedy_on_b(t_stack *b, t_info *info, int min, int max)
// {
// 	int	index;
// 	int	count;
// 	int	is_min_on_top;

// 	count = 0;
// 	index = (b->front + 1 + info->size) % info->size;
// 	is_min_on_top = 0;
// 	while (index != b->front)
// 	{
// 		if (b->data[index] == min)
// 		{
// 			is_min_on_top = 1;
// 			break ;
// 		}
// 		else if (b->data[index] == max)
// 			break ;
// 		count++;
// 		index = (index + 1 + info->size) % info->size;
// 	}
// 	if (count > info->size / 2)
// 	{
// 		count = info->size - count;
// 		put_on_top_rra(count, b, info);
// 	}
// 	else
// 		put_on_top_ra(count, b, info);
// 	return (is_min_on_top);
// }

void	greedy_on_b(t_stack *b, t_info *info, int min, int max)
{
	int	count;

	count = search(b, info, min, max);
	if (count > info->size / 2)
	{
		count = info->size - count;
		put_on_top_rr(count, b, info);
	}
	else
		put_on_top_r(count, b, info);
}

void	b_to_a(t_stack *a, t_stack *b, t_info *info, int chunk)
{
	int	min;
	int	max;

	printf("-------\n");
	for (int i = (b->front + 1 + info->size) % info->size; i != b->front; i = (i + 1 + info->size) % info->size)
		printf("%d\n", b->data[i]);
	printf("-------\n");

	min = info->min;
	max = info->max;
	while (chunk > 0)
	{
		info->a = 0;
		greedy_on_b(b, info, min, max);
		printf("-------\n");
		for (int i = (b->front + 1 + info->size) % info->size; i != b->front; i = (i + 1 + info->size) % info->size)
			printf("%d\n", b->data[i]);
		printf("-------\n");
		print_operation(push(b, a, info));

		if (get_top(a, info->size) == min)
		{
			info->a = 1;
			print_operation(rotate(a, info));
			min++;
		}
		else if (get_top(a, info->size) == max)
			max--;
		else
			printf("error\n");
		chunk--;
	}
}
