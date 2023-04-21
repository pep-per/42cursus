/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:48:53 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/20 22:39:32 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	int	top;

	if (stack->len < 2)
		return ;
	top = pop_front(stack);
	push_rear(stack, top);
	if (stack->a)
		print_operation(RA);
	else
		print_operation(RB);
}

void	reverse_rotate(t_stack *stack)
{
	int	bottom;

	if (stack->len < 2)
		return ;
	bottom = pop_rear(stack);
	push_front(stack, bottom);
	if (stack->a)
		print_operation(RRA);
	else
		print_operation(RRB);
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->len < 2)
		return ;
	tmp = top(stack);
	stack->data[front(stack)] \
	= stack->data[(stack->front + 2 + stack->size) % stack->size];
	stack->data[(stack->front + 2 + stack->size) % stack->size] = tmp;
	if (stack->a)
		print_operation(SA);
	else
		print_operation(SB);
}

void	push(t_stack *from, t_stack *to)
{
	if (from->len == 0)
		return ;
	push_front(to, pop_front(from));
	if (to->a)
		print_operation(PA);
	else
		print_operation(PB);
}
