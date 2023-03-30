/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:55:57 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/30 22:48:37 by jiyeolee         ###   ########.fr       */
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
	}
	else
	{
		while (get_top(a, info->size) != info->min)
			print_operation(reverse_rotate(a, info));
	}
}

void	greedy_on_b(t_stack *b, t_info *info, int min, int max)
{	
	int	min_idx;
	int	max_idx;

	if (min > max)
		return ;
	min_idx = search(b, info, min);
	max_idx = search(b, info, max);
	if (min_idx == ERROR || max_idx == ERROR)
		return ;
	if (count_rotation(b, info, min_idx) \
		<= count_rotation(b, info, max_idx) + 1)
		put_on_top(min_idx, b, info);
	else
		put_on_top(max_idx, b, info);
}

void	b_to_a(t_stack *a, t_stack *b, t_info *info, int chunk)
{
	int	min;
	int	max;
	int	top;

	min = info->min;
	max = info->max;
	info->a = 0;
	while (chunk > 0)
	{
		greedy_on_b(b, info, min, max);
		top = get_top(b, info->size);
		if (top == min || top == max)
		{
			print_operation(push(b, a, info));
			if (get_top(a, info->size) == min)
				print_operation(rotate(a, info));
			chunk--;
			min++;
			max--;
		}
	}
}
