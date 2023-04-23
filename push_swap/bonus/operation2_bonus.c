/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:50:05 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/21 21:31:08 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate_double(t_stack *a, t_stack *b)
{
	int	top;

	if (a->len < 2 || b->len < 2)
		return ;
	top = pop_front(a);
	push_rear(a, top);
	top = pop_front(b);
	push_rear(b, top);
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
}

void	swap_double(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->len < 2 || b->len < 2)
		return ;
	tmp = top(a);
	a->data[front(a)] \
	= a->data[(a->front + 2 + a->size) % a->size];
	a->data[(a->front + 2 + a->size) % a->size] = tmp;
	tmp = top(b);
	b->data[front(b)] \
	= b->data[(b->front + 2 + b->size) % b->size];
	b->data[(b->front + 2 + b->size) % b->size] = tmp;
}
