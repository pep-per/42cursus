/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:55:57 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/20 20:52:04 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_order(t_stack *a, t_stack *b, int data)
{
	return (a->data[a->front] - 1 == data || a->data[a->rear] + 1 == data);
}

int	search_min_max_from_top()
{

}

int	search_min_max_from_bottom()
{

}

int	put_min_or_max_on_top()
{

}

int	search_min(int min, t_stack *b)
{
	int	idx;

	idx = b->front;
	while (++idx < b->rear)
	{
		if (b->data[idx])
			return (i);
	}
	return (NOTHING_TO_PUSH);
}

void	greedy_on_b(int min, int max, t_stack *b, t_info *info)
{	
	int	min_idx;
	int	max_idx;

	min_idx = search_min(min, b);
	max_idx = search_max(max, b);
	
	if (count_operation()  < count_operation())
		rb_count = put_min_or_max_on_top(to_push_from_top);
	else
		rrb_count = put_min_or_max_on_top(to_push_from_bottom);
}

void	b_to_a(t_stack *a, t_stack *b, t_info *info)
{
	int	min;
	int	max;

	min = 0;
	max = 0;
	info->a = 0;
	while (b->len > 0)
	{
		greedy_on_b(min, max, b, info);
		if (in_order(a, b, b->data[b->front]))
		{
			push(b, a, info);
		}
		min = a->data[a->front] - 1;
		max = a->data[a->rear] + 1;
	}
}
