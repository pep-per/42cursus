/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:38:13 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/31 22:06:53 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_from_top(t_stack *a, t_info *info)
{
	int	idx;
	int	ra_count;

	idx = (a->front + 1 + info->size) % info->size;
	ra_count = 0;
	while (idx != a->front)
	{
		if (in_range(info->min, info->max, a->data[idx]))
			return (ra_count);
		idx = (idx + 1 + info->size) % info->size;
		ra_count++;
	}
	return (ra_count);
}

int	search_from_bottom(t_stack *a, t_info *info)
{
	int	idx;
	int	rra_count;

	idx = a->rear;
	rra_count = 0;
	while (idx != a->front)
	{
		if (in_range(info->min, info->max, a->data[idx]))
			return (rra_count);
		idx = (idx - 1 + info->size) % info->size;
		rra_count++;
	}
	return (rra_count);
}

int	search(t_stack *b, t_info *info, int data, int *count)
{
	int	idx;

	idx = (b->front + 1 + info->size) % info->size;
	*count = 0;
	while (idx != b->front)
	{
		if (b->data[idx] == data)
			return (idx);
		idx = (idx + 1 + info->size) % info->size;
		(*count)++;
	}
	return (ERROR);
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
