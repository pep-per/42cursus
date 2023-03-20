/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:42:00 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/20 20:24:55 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *a, t_info *info)
{
	int	*data;

	info->a = 1;
	data = a->data;
	if (info->size == 2)
	{
		if (data[0] > data[1])
			print_cmd(swap(a, info));
		return ;
	}
	if (data[0] < data[1] && data[1] > data[2])
	{
		print_cmd(reverse_rotate(a, info));
	}
	else if (data[0] > data[1])
	{
		if (data[0] > data[2])
			print_cmd(rotate(a, info));
	}
	if (data[0] > data[1])
		print_cmd(swap(a, info));
}

void	sort_complex(t_stack *a, t_stack *b, t_info *info)
{
	int	chunk_idx;

	chunk_idx = 0;
	while (chunk_idx < 3)
	{
		a_to_b(a, b, info, chunk_idx);
		chunk_idx++;
	}
	chunk_idx = 0;
	while (chunk_idx < 3)
	{
		b_to_a(a, b, info, chunk_idx);
		chunk_idx++;
	}
}

void	sort_stack(t_stack *a, t_info *info)
{
	t_stack	b;

	if (!initialize(&b, info->size))
		free_error(a->data);
	if (info->size <= 3)
		sort_small(a, info);
	else
		sort_complex(a, &b, info);
	free(a->data);
	free(b.data);
}
