/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:48:53 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/21 23:03:12 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack *stack, t_info *info)
{
	int	top;

	top = pop_front(stack, info->size);
	push_rear(stack, top, info->size);
	if (info->a)
		return (RA);
	return (RB);
}

int	reverse_rotate(t_stack *stack, t_info *info)
{
	int	bottom;

	bottom = pop_rear(stack, info->size);
	push_front(stack, bottom, info->size);
	if (info->a)
		return (RRA);
	return (RRB);
}

int	swap(t_stack *stack, t_info *info)
{
	int	tmp;

	if (stack->len < 2)
		return (-1);
	tmp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = tmp;
	if (info->a)
		return (SA);
	return (SB);
}

int	push(t_stack *from, t_stack *to, t_info *info)
{
	if (from->len == 0)
		return (-1);
	push_front(to, pop_front(from, info->size), info->size);
	if (info->a)
		return (PB);
	return (PA);
}
