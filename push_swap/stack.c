/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:50:28 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/10 22:36:43 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *stack, int n, int size)
{
	if (stack->len == 0)
	{

	}
	stack->front += 1;
	stack->data[(stack->front + size - 1) % size] = n;
	stack->len += 1;
}

void	push_rear(t_stack *stack, int n, int size)
{
	stack->rear += 1;
	stack->data[(stack->rear) % size] = n;
	stack->len += 1;
}

int	pop_front(t_stack *stack)
{
	int	n;

	n = stack->data[stack->front];
	stack->front -= 1;
	stack->len -= 1;
	return (n);
}

int	pop_rear(t_stack *stack)
{
	int	n;

	n = stack->data[stack->rear];
	stack->rear -= 1;
	stack->len -= 1;
	return (n);
}

// int	get_front(t_stack *stack)
// {
	
// }

// int	get_rear(t_stack *stack)
// {
	
// }