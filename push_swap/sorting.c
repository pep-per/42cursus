/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:42:00 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/23 22:44:25 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_three(t_stack *a, int *first, int *second, int *third)
{
	*first = top(a);
	*second = a->data[(a->front + 2 + a->size) % a->size];
	*third = a->data[(a->front + 3 + a->size) % a->size];
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	get_three(a, &first, &second, &third);
	if (a->len > 2)
	{
		if (first < second && second > third)
		{
			reverse_rotate(a);
			if (first < third)
				swap(a);
		}
		else if (first > second && first > third)
		{
			rotate(a);
			if (second > third)
				swap(a);
		}
		else if (first > second)
			swap(a);
	}
	else if (first > second)
		swap(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	optimize_rotation(a, 0);
	push(a, b);
	optimize_rotation(a, 1);
	push(a, b);
	sort_three(a);
	push(b, a);
	push(b, a);
}

void	sort_big(t_stack *a, t_stack *b)
{
	t_move	move;
	int		pivot1;
	int		pivot2;

	pivot1 = (a->size - 1) / 3;
	pivot2 = pivot1 + (a->size - 1) / 3;
	partitioning(a, b, pivot1, pivot2);
	while (a->len > 3)
		push(a, b);
	sort_three(a);
	while (b->len > 0)
	{
		select_optimal_choice(a, b, &move);
		run_optimal_move(a, b, &move);
	}
	optimize_rotation(a, 0);
}
