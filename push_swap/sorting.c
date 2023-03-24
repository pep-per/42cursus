/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:42:00 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/24 23:45:51 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *a, t_info *info)
{
	info->a = 1;
	if (info->size == 2)
	{
		if (a->data[0] > a->data[1])
			print_operation(swap(a, info));
		return ;
	}
	
	// if (a->data[0] > a->data[1] && a->data[1] > a->data[2])
	// {
	// 	print_operation(swap(a, info));
	// 	print_operation(reverse_rotate(a, info));
	// }

	// if (a->data[0] > a->data[2])
	// {
	// 	print_operation(rotate(a, info));
	// }


	if (a->data[0] < a->data[1] && a->data[1] > a->data[2])
	{
		print_operation(reverse_rotate(a, info));
	}
	else if (a->data[0] > a->data[1] && a->data[0] > a->data[2])
	{
		print_operation(rotate(a, info));
	}
	if (a->data[a->front] > a->data[a->front + 1])
		print_operation(swap(a, info));
	printf("idx %d : %d\n", 0, a->data[0]);
	printf("idx %d : %d\n", 1, a->data[1]);
	printf("idx %d : %d\n", 2, a->data[2]);

	printf("top idx %d\n : %d\n", a->front, a->data[a->front]);
	printf("bottom idx %d\n : %d\n", a->rear, a->data[a->rear]);


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
		b_to_a(a, b, info);
		chunk_idx++;
	}
}

void	 sort_stack(t_stack *a, t_info *info)
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
