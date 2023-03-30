/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:42:00 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/30 21:52:54 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_three_data(t_stack *a, int *first, int *second, int *third)
{
	*first = a->data[0];
	*second = a->data[1];
	*third = a->data[2];
}

void	sort_small(t_stack *a, t_info *info)
{
	int	first;
	int	second;
	int	third;

	get_three_data(a, &first, &second, &third);
	if (info->size == 2)
	{
		if (first > second)
			print_operation(swap(a, info));
		return ;
	}
	if (first < second && second > third)
	{
		print_operation(reverse_rotate(a, info));
		if (first < third)
			print_operation(swap(a, info));
	}
	else if (first > second && first > third)
	{
		print_operation(rotate(a, info));
		if (second > third)
			print_operation(swap(a, info));
	}
	else
		print_operation(swap(a, info));
}

void	sort_complex(t_stack *a, t_stack *b, t_info *info)
{
	int	chunk_idx;
	int	chunk;
	int	rest;

	chunk_idx = 0;
	chunk = (info->size - 1) / 3;
	rest = (info->size - 1) % 3;
	while (chunk_idx < 3)
	{
		info->min = chunk_idx * chunk;
		info->max = (chunk_idx + 1) * chunk - 1;
		// printf("%d\n", info->min);
		// printf("%d\n", info->max);
		// printf("%d%d%d%d\n", a->data[0], a->data[1], a->data[2], a->data[3]);
		if (chunk_idx == 2 && rest != 0)
		{
			info->max += rest;
			chunk += rest;
		}
		a_to_b(a, b, info, chunk);
		b_to_a(a, b, info, chunk);
		arrange_chunk(a, info, chunk_idx);
		chunk_idx++;
	}
}

void	sort_stack(t_stack *a, t_info *info)
{
	t_stack	b;

	if (!initialize(&b, info->size))
		free_error(a->data);
	info->a = 1;
	if (info->size - 1 <= 3)
		sort_small(a, info);
	else
		sort_complex(a, &b, info);
	free(a->data);
	free(b.data);
}
