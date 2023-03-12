/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:42:00 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/12 22:25:35 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *a, t_info *info, char *output)
{
	int	*data;

	data = a->data;
	if (info->size == 2 && data[0] > data[1])
	{
		swap(a);
		return ;
	}
	if (data[0] < data[1] && data[1] > data[2])
	{
		reverse_rotate(a, info);
	}
	else if (data[0] > data[1])
	{
		if (data[0] > data[2])
			rotate(a, info);
	}
	if (data[0] > data[1])
		swap(a);
}

void	sort_complex(t_stack *a, t_stack *b, t_info *info, char *output)
{
	int	chunk_idx;
	int	chunk_min;
	int	chunk_max;


	if (info->size == 0)
	{ 

	}
}

void	sort_stack(t_stack *a, t_info *info, char *output)
{
	t_stack	b;

	if (!initialize(&b, info->size))
		free_error(a->data);
	if (info->size <= 3)
		sort_small(a, info, output);
	else
		sort_complex(a, &b, info, output);
	free(a->data);
	free(b.data);
}
