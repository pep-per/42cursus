/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:38:13 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/20 20:47:25 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_upper(int to_push, t_stack *a)
{
	return (to_push <= a->len / 2);
}

int	search_from_top(int limit_min, int limit_max, t_stack *a)
{
	int	i;

	i = a->front + 1;
	while (i++ < a->rear)
	{
		if (in_range(limit_min, limit_max, a->data[i]))
			return (i);
	}
	return (NOTHING_TO_PUSH);
}

int	search_from_bottom(int limit_min, int limit_max, t_stack *a)
{
	int	i;

	i = a->rear;
	while (i++ < a->front)
	{
		if (in_range(limit_min, limit_max, a->data[i]))
			return (i);
	}
	return (NOTHING_TO_PUSH);
}
