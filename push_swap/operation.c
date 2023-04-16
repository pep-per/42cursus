/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:48:53 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/17 05:49:00 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_double(t_stack *a, t_stack *b)
{
	int	top;

	if (a->len < 2 || b->len < 2)
		return ;
	top = pop_front(a);
	push_rear(a, top);
	top = pop_front(b);
	push_rear(b, top);
	print_operation(RR);
}

void	reverse_rotate_double(t_stack *a, t_stack *b)
{
	int	bottom;

	if (a->len < 2 || b->len < 2)
		return ;
	bottom = pop_rear(a);
	push_front(a, bottom);
	bottom = pop_rear(b);
	push_front(b, bottom);
	print_operation(RRR);
}

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

void	swap(t_stack *a)
{
	int	tmp;

	if (a->len < 2)
		return ;
	tmp = top(a);
	a->data[front(a)] = a->data[(a->front + 2 + a->size) % a->size];
	a->data[(a->front + 2 + a->size) % a->size] = tmp;
	print_operation(SA);
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
