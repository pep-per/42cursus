/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:48:53 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/12 21:21:18 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, t_info *info)
{
	int	top;

	top = pop_front(stack, info->size);
	push_rear(stack, top, info->size);
}

void	reverse_rotate(t_stack *stack, t_info *info)
{
	int	bottom;

	bottom = pop_rear(stack, info->size);
	push_front(stack, bottom, info->size);
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = tmp;
}

void	push(t_stack *from, t_stack *to, t_info *info)
{
	int	top;

	if (from->len == 0)
		return ;
	push_front(to, pop_front(from, info->size), info->size);
}
