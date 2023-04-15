/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 05:06:17 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/15 23:00:05 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_between_triangles(t_stack *a)
{
	int	i;
	int	next;

	i = front(a);
	next = (i + 1 + a->size) % a->size;
	while (i != a->rear)
	{
		if (a->data[i] > a->data[next])
			return (next);
		i = (i + 1 + a->size) % a->size;
		next = (i + 1 + a->size) % a->size;
	}
	return (next);
}

// int	find_max(t_stack *a)
// {
// 	int	i;
// 	int	max;
// 	int	max_idx;

// 	i = front(a);
// 	max = top(a);
// 	while (i != (a->rear + 1 + a->size) % a->size)
// 	{
// 		if (a->data[i] >= max)
// 		{
// 			max = a->data[i];
// 			max_idx = i;
// 		}
// 		i = (i + 1 + a->size) % a->size;
// 	}
// 	return (max_idx);
// }

int	count_to_top(t_stack *a, int data)
{
	int	i;
	int	cnt;

	i = a->rear;
	cnt = 0;
	while (i != a->front)
	{
		cnt++;
		if (a->data[i] == data)
			break ;
		i = (i - 1 + a->size) % a->size;
	}
	return (a->len - cnt);
}

int	count_move_in_a(t_stack *a, t_move *move, int new)
{
	int	cnt;
	int	i;
	int	between;

	move->ra_cnt = 0;
	move->rra_cnt = 0;
	between = find_between_triangles(a);
	cnt = 0;
	if (new > top(a))
	{
		i = front(a);
		while (i != between && a->data[i] < new)
		{
			i = (i + 1 + a->size) % a->size;
			cnt++;
		}
		if (cnt > a->len / 2)
		{
			cnt = a->len - cnt;
			move->rra_cnt = cnt;
		}
		else
			move->ra_cnt = cnt;
		printf("ra %d , rra %d\n", move->ra_cnt, move->rra_cnt);
	}
	else if (top(a) > bottom(a))
	{
		i = a->rear;
		while (top(a) > a->data[i] && a->data[i] > new)
		{
			i = (i - 1 + a->size) % a->size;
			cnt++;
		}
		if (cnt > a->len / 2)
		{
			cnt = a->len - cnt;
			move->ra_cnt = cnt;
		}
		else
			move->rra_cnt = cnt;
		printf("down ra %d , rra %d\n", move->ra_cnt, move->rra_cnt);
		
	}
	return (cnt);
}

int	count_move_in_b(t_stack *b, t_move *move, int i)
{
	int	cnt;

	move->rb_cnt = 0;
	move->rrb_cnt = 0;
	cnt = 0;
	while (i != front(b))
	{
		i = (i - 1 + b->size) % b->size;
		cnt++;
	}
	if (cnt > b->len / 2)
	{
		cnt = b->len - cnt;
		move->rrb_cnt = cnt;
	}
	else
		move->rb_cnt = cnt;
	// printf("rb_cnt : %d\n", move->rb_cnt);
	// printf("rrb_cnt : %d\n", move->rrb_cnt);

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
	printf("optimal\n");
	printf("ra %d , rb %d\n", move->ra_cnt, move->rb_cnt);
	printf("rra %d , rrb %d\n", move->rra_cnt, move->rrb_cnt);
	printf("\n");
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
		printf("remain ra %d , rb %d\n", move->ra_cnt, move->rb_cnt);
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
