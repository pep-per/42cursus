/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:38:13 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/21 23:00:25 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_from_top(int limit_min, int limit_max, t_stack *a)
{
	int	idx;

	idx = a->front;
	while (++idx <= a->rear)
	{
		if (in_range(limit_min, limit_max, a->data[idx]))
			return (idx);
	}
	return (NOTHING_TO_PUSH);
}

int	search_from_bottom(int limit_min, int limit_max, t_stack *a)
{
	int	idx;

	idx = a->rear;
	while (idx++ > a->front)
	{
		if (in_range(limit_min, limit_max, a->data[idx]))
			return (idx);
	}
	return (NOTHING_TO_PUSH);
}

int	search(int num, t_stack *b)
{
	int	idx;

	idx = b->front;
	while (++idx <= b->rear)
	{
		if (b->data[idx] == num)
			return (idx);
	}
	return (NOTHING_TO_PUSH);
}

// int	search_max(t_stack *a, t_stack *b)
// {
// 	int	idx;
// 	int	max;

// 	max = a->data[a->rear] + 1;
// 	idx = b->front;
// 	while (++idx <= b->rear)
// 	{
// 		if (b->data[idx] == max)
// 			return (idx);
// 	}
// 	return (NOTHING_TO_PUSH);
// }
