/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:42:00 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/17 06:36:12 by jiyeolee         ###   ########.fr       */
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
	}
	else if (first > second)
		swap(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	cnt1;
	int	cnt2;
	// for (int i = front(a); i != (a->rear + 1 + a->size) % a->size; i = (i + 1 + a->size) % a->size)
	// 	printf("%d\n", a->data[i]);
	// printf("\n");
	// for (int i = front(b); i != (b->rear + 1 + b->size) % b->size; i = (i + 1 + b->size) % b->size)
	// 	printf("%d\n", b->data[i]);
	cnt1 = count_to_top(a, 0);
	cnt2 = count_to_top(a, 1);
	if (cnt2 + 1 < cnt1)
	{
		optimize_rotation(a, 1);
		push(a, b);
		optimize_rotation(a, 0);
		push(a, b);
		swap(b);
	}
	else
	{
		optimize_rotation(a, 0);
		push(a, b);
		optimize_rotation(a, 1);
		push(a, b);
	}
	sort_three(a);
	push(b, a);
	push(b, a);
}

// void	join_triangles(t_stack *a)
// {
// 	int	cnt;

// 	cnt = count_to_top(a, 0);
// 	if (cnt > a->len / 2)
// 	{
// 		cnt = a->len - cnt;
// 		while (cnt-- > 0)
// 			reverse_rotate(a);
// 	}
// 	else
// 	{
// 		while (cnt-- > 0)
// 			rotate(a);
// 	}
// }

void	sort_big(t_stack *a, t_stack *b)
{
	t_move	move;
	int		pivot1;
	int		pivot2;

	pivot1 = (a->size - 1) / 3;
	pivot2 = pivot1 + (a->size - 1) / 3;
	partitioning(a, b, pivot1, pivot2);
	while (a->len > 5)
		push(a, b);
	sort_five(a, b);
	while (b->len > 0)
	{
		select_optimal_choice(a, b, &move);
		run_optimal_move(a, b, &move);
		// for (int i = front(a); i != (a->rear + 1 + a->size) % a->size; i = (i + 1 + a->size) % a->size)
		// 	printf("%d\n", a->data[i]);
	}
	optimize_rotation(a, 0);
	// join_triangles(a);
	// printf("\nresult :\n");
	// for (int i = front(a); i != (a->rear + 1 + a->size) % a->size; i = (i + 1 + a->size) % a->size)
	// 	printf("%d\n", a->data[i]);
}
