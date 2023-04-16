/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 05:06:17 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/17 05:41:33 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sum_move_count(t_stack *a, t_stack *b, t_move *move, int data)
{
	return (count_move_in_b(b, move, data) + count_move_in_a(a, move, data));
}

void	select_optimal_choice(t_stack *a, t_stack *b, t_move *move)
{
	int	min_cnt;
	int	move_cnt;
	int	i;
	int	optimal_idx;

	i = front(b);
	min_cnt = sum_move_count(a, b, move, b->data[i]);
	optimal_idx = i;
	while (i != (b->rear + 1 + b->size) % b->size)
	{
		move_cnt = sum_move_count(a, b, move, b->data[i]);
		if (move_cnt < min_cnt)
		{
			min_cnt = move_cnt;
			optimal_idx = i;
		}
		i = (i + 1 + b->size) % b->size;
	}
	sum_move_count(a, b, move, b->data[optimal_idx]);
	// printf("optimal data : %d\n", b->data[optimal_idx]);
	// printf("ra %d , rb %d\n", move->ra_cnt, move->rb_cnt);
	// printf("rra %d , rrb %d\n", move->rra_cnt, move->rrb_cnt);
	// printf("\n");
}

void	double_move(t_stack *a, t_stack *b, t_move *move)
{
	if (move->rb_cnt > move->ra_cnt)
	{
		move->rb_cnt -= move->ra_cnt;
		while (move->ra_cnt-- > 0)
			rotate_double(a, b);
	}
	else if (move->ra_cnt >= move->rb_cnt)
	{
		move->ra_cnt -= move->rb_cnt;
		while (move->rb_cnt-- > 0)
			rotate_double(a, b);
	}
}

void	double_move_reverse(t_stack *a, t_stack *b, t_move *move)
{
	if (move->rrb_cnt > move->rra_cnt)
	{
		move->rrb_cnt -= move->rra_cnt;
		while (move->rra_cnt-- > 0)
			reverse_rotate_double(a, b);
	}
	else
	{
		move->rra_cnt -= move->rrb_cnt;
		while (move->rrb_cnt-- > 0)
			reverse_rotate_double(a, b);
	}
}

void	run_optimal_move(t_stack *a, t_stack *b, t_move *move)
{
	if (move->ra_cnt > 0 && move->rb_cnt > 0)
		double_move(a, b, move);
	else if (move->rra_cnt > 0 && move->rrb_cnt > 0)
		double_move_reverse(a, b, move);
	while (move->rb_cnt > 0)
	{
		rotate(b);
		move->rb_cnt--;
	}
	while (move->rrb_cnt > 0)
	{
		reverse_rotate(b);
		move->rrb_cnt--;
	}
	while (move->ra_cnt > 0)
	{
		rotate(a);
		move->ra_cnt--;
	}
	while (move->rra_cnt > 0)
	{
		reverse_rotate(a);
		move->rra_cnt--;
	}
	push(b, a);
}
