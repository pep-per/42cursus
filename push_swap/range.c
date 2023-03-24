/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:41:50 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/22 23:25:05 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_upper(int idx, t_stack *stack)
{
	return (idx + 1 <= stack->len / 2);
}

int	in_range(int limit_min, int limit_max, int idx)
{
	return ((limit_min <= idx) && (idx < limit_max));
}

int	in_order(t_stack *a)
{
	if (a->len <= 1)
		return (1);
	return (a->data[a->front + 1] < a->data[a->front + 2]);
}

int	is_min_or_max_on_top(t_stack *a, int data)
{
	if (a->len == 0)
		return (data == 0);
	return (a->data[a->front + 1] - 1 == data || a->data[a->rear] + 1 == data);
}
