/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:49:05 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/23 22:46:18 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_rotation(t_stack *a, int data)
{
	int	cnt;

	cnt = count_to_top(a, data);
	if (cnt > a->len / 2)
	{
		cnt = a->len - cnt;
		while (cnt-- > 0)
			reverse_rotate(a);
	}
	else
	{
		while (cnt-- > 0)
			rotate(a);
	}
}

int	is_right_position(t_stack *a, int curr, int next, int new)
{
	if (a->data[next] < new && new < a->data[curr])
		return (1);
	else if (a->data[curr] < a->data[next])
	{
		if (new > a->data[curr] && new > a->data[next])
			return (1);
		else if (new < a->data[curr] && new < a->data[next])
			return (1);
	}
	return (0);
}

int	count_to_top(t_stack *stack, int data)
{
	int	i;
	int	cnt;

	i = stack->rear;
	cnt = 0;
	while (i != stack->front)
	{
		cnt++;
		if (stack->data[i] == data)
			break ;
		i = (i - 1 + stack->size) % stack->size;
	}
	return (stack->len - cnt);
}

int	count_move_in_a(t_stack *a, t_move *move, int new)
{
	int	cnt;
	int	curr;
	int	next;

	move->ra_cnt = 0;
	move->rra_cnt = 0;
	cnt = 0;
	curr = a->rear;
	while (curr != a->front)
	{
		next = (curr - 1 + a->size) % a->size;
		cnt++;
		if (is_right_position(a, curr, next, new))
			break ;
		curr = (curr - 1 + a->size) % a->size;
	}
	if (cnt > a->len / 2)
	{
		cnt = a->len - cnt;
		move->ra_cnt = cnt;
	}
	else
		move->rra_cnt = cnt;
	return (cnt);
}

int	count_move_in_b(t_stack *b, t_move *move, int data)
{
	int	cnt;
	int	i;

	move->rb_cnt = 0;
	move->rrb_cnt = 0;
	i = front(b);
	cnt = count_to_top(b, data);
	if (cnt > b->len / 2)
	{
		cnt = b->len - cnt;
		move->rrb_cnt = cnt;
	}
	else
		move->rb_cnt = cnt;
	return (cnt);
}
