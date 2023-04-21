/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:50:28 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/21 21:40:08 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_front(t_stack *stack, int data)
{
	stack->data[stack->front] = data;
	stack->front = (stack->front - 1 + stack->size) % stack->size;
	stack->len += 1;
}

void	push_rear(t_stack *stack, int data)
{
	stack->rear = (stack->rear + 1 + stack->size) % stack->size;
	stack->data[stack->rear] = data;
	stack->len += 1;
}

int	pop_front(t_stack *stack)
{
	int	data;

	data = top(stack);
	stack->front = (stack->front + 1 + stack->size) % stack->size;
	stack->len -= 1;
	return (data);
}

int	pop_rear(t_stack *stack)
{
	int	data;

	data = bottom(stack);
	stack->rear = (stack->rear - 1 + stack->size) % stack->size;
	stack->len -= 1;
	return (data);
}
