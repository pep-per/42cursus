/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 05:06:17 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/10 23:31:31 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_in_order(t_stack *a)
{
	int	i;
	int	max;

	i = front(a);
	max = top(a);
	while (i != (a->rear + 1 + a->size) % a->size)
	{
		if (a->data[i] >= max)
			max = a->data[i];
		else
			return (i - 1);
		i = (i + 1 + a->size) % a->size;
	}
	return (i);
}

int	find_max(t_stack *a)
{
	int	i;
	int	max;
	int	max_idx;

	i = front(a);
	max = top(a);
	while (i != (a->rear + 1 + a->size) % a->size)
	{
		if (a->data[i] >= max)
		{
			max = a->data[i];
			max_idx = i;
		}
		i = (i + 1 + a->size) % a->size;
	}
	return (max_idx);
}

int	count_move_in_a(t_stack *a, t_move *move, int data)
{
	int	cnt;
	int	i;
	int	max_idx;

	max_idx = find_max_in_order(a);
	cnt = 0;
	move->ra_cnt = 0;
	move->rra_cnt = 0;
	if (data > top(a))
	{
		i = front(a);
		if (data > a->data[max_idx])
			cnt = max_idx + 1;
		else
		{
			while (data > a->data[i])
			{
				i = (i + 1 + a->size) % a->size;
				cnt++;
			}
		}
		move->ra_cnt = cnt;
	}
	else if (data + 1 != top(a))
	{
		i = max_idx + 1;
		while (data < a->data[i])
		{
			i = (i + 1 + a->size) % a->size;
			cnt++;
		}
		move->rra_cnt = cnt;
	}
	return (cnt);
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
	// if (cnt > b->len)
	// 	cnt = b->size - cnt;
	move->rb_cnt = 0;
	move->rrb_cnt = 0;
	if (idx > b->size / 2)
	{
		cnt = b->size - cnt;
		move->rrb_cnt = cnt;
	}
	else
	{
		move->rb_cnt = cnt;
	}
	return (cnt);
}

int	sum_move_count(t_stack *a, t_stack *b, t_move *move, int i)
{
	return (count_move_in_a(a, move, b->data[i]) \
			+ count_move_in_b(b, move, i) + 1);
}

void	select_optimal_choice(t_stack *a, t_stack *b, t_move *move)
{
	int	min_cnt;
	int	move_cnt;
	int	i;
	int	optimal_idx;

	i = front(b);
	min_cnt = sum_move_count(a, b, move, i);
	optimal_idx = i;
	while (i != (b->rear + 1 + b->size) % b->size)
	{
		move_cnt = sum_move_count(a, b, move, i);
		if (move_cnt < min_cnt)
		{
			min_cnt = move_cnt;
			optimal_idx = i;
		}
		i = (i + 1 + b->size) % b->size;
	}
	sum_move_count(a, b, move, optimal_idx);
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

void	run_optimal_move(t_stack *a, t_stack *b, t_move *move)
{
	if ((move->ra_cnt && move->rb_cnt) || (move->rra_cnt && move->rrb_cnt))
		double_move(a, b, move);
	// printf("ra : %d, rb : %d, rra : %d, rrb %d\n", move->ra_cnt, move->rb_cnt, move->rra_cnt, move->rrb_cnt);
	// return ;
	while ((move->ra_cnt)-- > 0)
		rotate(a);
	while (move->rra_cnt-- > 0)
		reverse_rotate(a);
	push(b, a);
	while (move->rb_cnt-- > 0)
		rotate(b);
	while (move->rrb_cnt-- > 0)
		reverse_rotate(b);
}
