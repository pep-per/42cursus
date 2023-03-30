/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:48:53 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/30 21:55:20 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack *stack, t_info *info)
{
	int	top;

	if (stack->len == 0)
		return (ERROR);
	top = pop_front(stack, info->size);
	push_rear(stack, top, info->size);
	if (info->a)
		return (RA);
	return (RB);
}

int	reverse_rotate(t_stack *stack, t_info *info)
{
	int	bottom;

	if (stack->len == 0)
		return (ERROR);
	bottom = pop_rear(stack, info->size);
	push_front(stack, bottom, info->size);
	if (info->a)
		return (RRA);
	return (RRB);
}

int	swap(t_stack *stack, t_info *info)
{
	int	tmp;
	int	size;

	if (stack->len < 2)
		return (ERROR);
	size = info->size;
	tmp = stack->data[(stack->front + 1) % size];
	stack->data[(stack->front + 1) % size] \
	= stack->data[(stack->front + 2) % size];
	stack->data[(stack->front + 2) % size] = tmp;
	if (info->a)
		return (SA);
	return (SB);
}

int	push(t_stack *from, t_stack *to, t_info *info)
{
	if (from->len == 0)
		return (ERROR);
	push_front(to, pop_front(from, info->size), info->size);
	// to->front = (to->front - 1 + info->size) % info->size;
	if (info->a)
		return (PB);
	return (PA);
}
