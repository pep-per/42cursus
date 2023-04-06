/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:48:53 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/07 01:58:52 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	int	top;

	if (stack->len == 0)
		return ;
	top = pop_front(stack);
	push_rear(stack, top);
	if (stack->a)
		print_operation(RA);
	print_operation(RB);
}

void	reverse_rotate(t_stack *stack)
{
	int	bottom;

	if (stack->len == 0)
		return ;
	bottom = pop_rear(stack);
	push_front(stack, bottom);
	if (stack->a)
		print_operation(RRA);
	print_operation(RRB);
}

void	swap(t_stack *a)
{
	int	tmp;

	if (a->len < 2)
		return ;
	tmp = get_top(a);
	a->data[get_front(a)] = a->data[(a->front + 2 + a->size) % a->size];
	a->data[(a->front + 2 + a->size) % a->size] = tmp;
	print_operation(SA);
}

void	push(t_stack *from, t_stack *to)
{
	if (from->len == 0)
		return (ERROR);
	push_front(to, pop_front(from));
	if (to->a)
		print_operation(PA);
	print_operation(PB);
}
