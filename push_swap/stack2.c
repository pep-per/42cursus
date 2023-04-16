/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:41:58 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/17 04:52:11 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	front(t_stack *stack)
{
	return ((stack->front + 1 + stack->size) % stack->size);
}

int	top(t_stack *stack)
{
	return (stack->data[front(stack)]);
}

int	bottom(t_stack *stack)
{
	return (stack->data[stack->rear]);
}
