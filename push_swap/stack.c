/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:50:28 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/12 20:53:42 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *stack, int n, int size)
{
	stack->front = (stack->front + size - 1) % size;
	stack->data[stack->front] = n;
	stack->len += 1;
}

void	push_rear(t_stack *stack, int n, int size)
{
	stack->rear = (stack->rear + 1) % size;
	stack->data[stack->rear] = n;
	stack->len += 1;
}

int	pop_front(t_stack *stack, int size)
{
	int	n;

	n = stack->data[stack->front];
	stack->front = (stack->front + 1) % size;
	stack->len -= 1;
	return (n);
}

int	pop_rear(t_stack *stack, int size)
{
	int	n;

	n = stack->data[stack->rear];
	stack->rear = (stack->rear + size - 1) % size;
	stack->len -= 1;
	return (n);
}
