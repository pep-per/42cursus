/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:42:04 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/20 20:00:12 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_range(int limit_min, int limit_max, int idx)
{
	return ((limit_min <= idx) && (idx < limit_max));
}

void	put_on_top(int idx, t_stack *a, t_info *info)
{
	int	to_push;

	if (idx == NOTHING_TO_PUSH)
		return ;
	to_push = a->data[idx];
	if (in_upper(idx, a))
	{
		while (a->data[a->front] != to_push)
			print_operation(rotate(a, info));
	}
	else
	{
		while (a->data[a->front] != to_push)
			print_operation(reverse_rotate(a, info));
	}
}

void	greedy_on_a(int limit_min, int limit_max, t_stack *a, t_info *info)
{
	int	idx_from_top;
	int	idx_from_bottom;
	int	count;

	idx_from_top = search_from_top(limit_min, limit_max, a);
	idx_from_bottom = search_from_bottom(limit_min, limit_max, a);
	if (a->front - idx_from_top <= a->rear - idx_from_bottom + 1)
		put_on_top(idx_from_top, a, info);
	else
		put_on_top(idx_from_bottom, a, info);
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
			print_operation(push(a, b, info));
			chunk--;
		}
	}
}
