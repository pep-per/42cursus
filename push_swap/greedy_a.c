/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:42:04 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/18 23:28:00 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_range(int limit_min, int limit_max, int to_push)
{
	return ((limit_min <= to_push) && (to_push < limit_max));
}

void	put_on_top(int to_push, t_stack *a, t_info *info)
{	
	if (to_push == NOTHING_TO_PUSH)
		return ;
	if (in_upper(to_push, a))
	{
		while (a->data[a->front] == a->data[to_push])
			print_operation(rotate(a, info));
	}
	else
	{
		while (a->data[a->front] == a->data[to_push])
			print_operation(reverse_rotate(a, info));
	}
}

void	greedy_on_a(int limit_min, int limit_max, t_stack *a, t_info *info)
{
	int	to_push_from_top;
	int	to_push_from_bottom;
// 옮길 인덱스
	to_push_from_top = search_from_top(limit_min, limit_max, a);
	to_push_from_bottom = search_from_bottom(limit_min, limit_max, a);
	if (to_push_from_top < to_push_from_bottom)
		put_on_top(to_push_from_top, a, info);
	else
		put_on_top(to_push_from_bottom, a, info);
}

void	a_to_b(t_stack *a, t_stack *b, t_info *info, int chunk_idx)
{
	int	chunk;
	int	limit_min;
	int	limit_max;
	int	rest;

	chunk = (info->size / 3);
	limit_min = chunk_idx * chunk;
	limit_max = (chunk_idx + 1) * chunk;
	rest = (info->size % 3);
	if (chunk_idx == 2 && rest != 0)
	{
		limit_max += rest;
		chunk += rest;
	}
	info->a = 1;
	while (chunk > 0)
	{
		greedy_on_a(limit_min, limit_max, a, info);
		if (in_range(limit_min, limit_max, a->data[a->front]))
		{
			push(a, b, info);
			chunk--;
		}
	}
}
