/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 05:06:38 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/18 21:11:33 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partitioning(t_stack *a, t_stack *b, int pivot1, int pivot2)
{
	int	len;
	int	i;

	len = a->len;
	while (len-- > 0)
	{
		i = front(a);
		if (a->data[i] < pivot1)
		{
			if (len-- > 1 && a->data[(i + 1 + a->size) % a->size] >= pivot2)
			{
				push(a, b);
				rotate_double(a, b);
			}
			else
			{
				push(a, b);
				rotate(b);
			}
		}
		else if (a->data[i] < pivot2)
			push(a, b);
		else
			rotate(a);
	}
}
