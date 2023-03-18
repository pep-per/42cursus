/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:55:57 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/18 23:30:42 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_order(t_stack *a, t_stack *b, int data)
{
	return (a->data[a->front] - 1 == data || a->data[a->rear] + 1 == data);
}

void	greedy_on_b(t_stack *b, t_info *info)
{	
	int	to_push_from_top;
	int	to_push_from_bottom;
	int	rb_count;
	int	rrb_count;

	to_push_from_top = search_min_max_from_top();
	to_push_from_bottom = search_min_max_from_bottom();
	put_min_or_max_on_top(b, info);
}

void	b_to_a(t_stack *a, t_stack *b, t_info *info)
{
	info->a = 0;
	while (b->len > 0)
	{
		greedy_on_b(b, info);
		if (in_order(a, b, b->data[b->front]))
		{
			push(b, a, info);
		}
	}
}
