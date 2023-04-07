/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 05:06:17 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/08 07:24:25 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_move_in_a(t_stack *a, t_move *move, int data)
{
	move->ra_cnt = 0;
	move->rra_cnt = 0;
	if ()
	{
		
	}
}

int	count_move_in_b(t_stack *b, t_move *move, int idx)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = idx;
	while (i != front(b))
	{
		i = (i + 1 + b->size) % b->size;
		cnt++;
	}
	if (cnt > b->size / 2)
	{
		cnt = b->size - cnt;
		move->rrb_cnt = cnt;
		move->rb_cnt = 0;
	}
	else
	{
		move->rb_cnt = cnt;
		move->rrb_cnt = 0;
	}
	return (cnt);
}

int	sum_move_count(t_stack *a, t_stack *b, t_move *move, int i)
{
	return (count_move_in_a(a, move, b->data[i]) \
			+ count_move_in_b(b, move, i) + 1);
}

int	select_optimal_choice(t_stack *a, t_stack *b, t_move *move)
{
	int	min_cnt;
	int	move_cnt;
	int	i;
	int	optimal_idx;

	i = front(b);
	min_cnt = sum_move_count(a, b, move, b->rear);
	optimal_idx = 0;
	while (i != b->rear)
	{
		move_cnt = sum_move_count(a, b, move, i);
		if (move_cnt < min_cnt)
		{
			min_cnt = move_cnt;
			optimal_idx = i;
		}
		i = (i + 1 + b->size) % b->size;
	}
	return (optimal_idx);
}

void	double_move(t_stack *a, t_stack *b, t_move *move)
{
	if (move->rb_cnt > move->ra_cnt)
	{
		move->rb_cnt -= move->ra_cnt;
		while (move->ra_cnt-- > 0)
			rotate_double(a, b);
	}
	else
	{
		move->ra_cnt -= move->rb_cnt;
		while (move->rb_cnt-- > 0)
			rotate_double(a, b);
	}
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

void	run_optimal_move(t_stack *a, t_stack *b, t_move *move, int i)
{
	if ((move->ra_cnt && move->rb_cnt) || (move->rra_cnt && move->rrb_cnt))
		double_move(a, b, move);
	while (move->ra_cnt-- > 0)
		rotate(a);
	while (move->rra_cnt-- > 0)
		reverse_rotate(a);
	push(b, a);
	while (move->rb_cnt-- > 0)
		rotate(b);
	while (move->rrb_cnt-- > 0)
		reverse_rotate(b);
}
