/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:41:50 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/28 19:30:55 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_upper(int idx, t_stack *stack)
{
	return (idx + 1 <= stack->len / 2);
}

int	in_range(int min, int max, int data)
{
	return ((min <= data) && (data <= max));
}

// int	in_order(t_stack *a, t_info *info)
// {
// 	if (a->len <= 1)
// 		return (1);
// 	return (get_top(a, info->size) < a->data[(a->front + 2) % info->size]);
// }

// int	is_min_or_max_on_top(t_info *info, int data)
// {
// 	return (info->min == data || info->max == data);
// }
