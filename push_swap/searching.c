/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:38:13 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/28 19:52:58 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_from_top(t_stack *a, t_info *info)
{
	int	idx;

	idx = a->front;
	while (++idx % info->size != a->rear)
	{
		if (in_range(info->min, info->max, a->data[idx]))
			return (idx);
	}
	return (ERROR);
}

int	search_from_bottom(t_stack *a, t_info *info)
{
	int	idx;

	idx = a->rear - 1;
	while (++idx % info->size != (a->front + 1) % info->size)
	{
		if (in_range(info->min, info->max, a->data[idx]))
			return (idx);
	}
	return (ERROR);
}

int	search(t_stack *b, t_info *info, int data)
{
	int	idx;

	idx = b->front;
	while (++idx % info->size != b->front)
	{
		if (b->data[idx] == data)
			return (idx);
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
