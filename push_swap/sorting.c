/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:42:00 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/07 02:03:27 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_three_data(t_stack *a, int *first, int *second, int *third)
{
	*first = a->data[0];
	*second = a->data[1];
	*third = a->data[2];
}

void	sort_small(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	get_three_data(a, &first, &second, &third);
	if (a->size == 2)
	{
		if (first > second)
			swap(a);
		return ;
	}
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
	else
		swap(a);
}


void	sort_complex(t_stack *a, t_stack *b)
{
	
}

// void	sort_complex(t_stack *a, t_stack *b)
// {
// 	int	chunk_idx;
// 	int	chunk;
// 	int	rest;

// 	chunk_idx = 0;
// 	chunk = (info->size - 1) / 3;
// 	rest = (info->size - 1) % 3;
// 	while (chunk_idx < 3)
// 	{
// 		info->min = chunk_idx * chunk;
// 		info->max = (chunk_idx + 1) * chunk - 1;
// 		if (chunk_idx == 2 && rest != 0)
// 		{
// 			info->max += rest;
// 			chunk += rest;
// 		}
// 		printf("min : %d\n", info->min);
// 		printf("max : %d\n", info->max);
// 		a_to_b(a, b, info, chunk);
// 		b_to_a(a, b, info, chunk);
// 		arrange_chunk(a, info, chunk_idx);
// 		chunk_idx++;
// 	}
// 	printf("-------\n");
// 	for (int i = (a->front + 1 + info->size) % info->size; i != a->front; i = (i + 1 + info->size) % info->size)
// 		printf("%d\n", a->data[i]);
// 	printf("-------\n");
// }

// void	sort_stack(t_stack *a)
// {
// 	t_stack	b;

// 	initialize(&b, a->size, a->data);
// 	info->a = 1;
// 	if (info->size - 1 <= 3)
// 		sort_small(a, info);
// 	else
// 		sort_complex(a, &b, info);
// 	free(a->data);
// 	free(b.data);
// }
