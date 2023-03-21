/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:55:57 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/21 22:16:09 by jiyeolee         ###   ########.fr       */
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

void	greedy_on_b(t_stack *a, t_stack *b, t_info *info)
{	
	int	min;
	int	max;
	int	min_idx;
	int	max_idx;

	min = a->data[a->front] - 1;
	max = a->data[a->rear] + 1;
	min_idx = search(min, b);
	max_idx = search(max, b);
	if (count_rotation(b, min_idx) <= count_rotation(b, max_idx) + 1)
		put_on_top(min_idx, b, info);
	else
		put_on_top(max_idx, b, info);
}

void	b_to_a(t_stack *a, t_stack *b, t_info *info)
{
	info->a = 0;
	while (b->len > 0)
	{
		greedy_on_b(a, b, info);
		if (is_min_or_max_on_top(a, b->data[b->front]))
		{
			print_operation(push(b, a, info));
			if (!in_order(a))
				print_operation(rotate(a, info));
		}
	}
}
