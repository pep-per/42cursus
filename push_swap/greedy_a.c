/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:42:04 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/21 22:00:39 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rotation(t_stack *stack, int idx)
{
	if (in_upper(idx, stack))
		return (stack->front - idx);
	else
		return (stack->rear - idx + 1);
}

void	put_on_top(int idx, t_stack *stack, t_info *info)
{
	int	to_push;

	if (idx == NOTHING_TO_PUSH)
		return ;
	to_push = stack->data[idx];
	if (in_upper(idx, stack))
	{
		while (stack->data[stack->front] != to_push)
			print_operation(rotate(stack, info));
	}
	else
	{
		while (stack->data[stack->front] != to_push)
			print_operation(reverse_rotate(stack, info));
	}
}

void	greedy_on_a(int limit_min, int limit_max, t_stack *a, t_info *info)
{
	int	idx_from_top;
	int	idx_from_bottom;

	idx_from_top = search_from_top(limit_min, limit_max, a);
	idx_from_bottom = search_from_bottom(limit_min, limit_max, a);
	if (count_rotation(a, idx_from_top) <= count_rotation(a, idx_from_bottom))
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
