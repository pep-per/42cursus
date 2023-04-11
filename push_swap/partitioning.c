/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 05:06:38 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/11 21:27:55 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partitioning(t_stack *a, t_stack *b)
{
	int	pivot1;
	int	pivot2;
	int	i;

	pivot1 = (a->size - 1) / 3;
	pivot2 = pivot1 + (a->size - 1) / 3;
	i = 0;
	while (i != a->size - 1)
	{
		if (a->data[i] < pivot1)
		{
			push(a, b);
			rotate(b);
		}
		else if (a->data[i] < pivot2)
			push(a, b);
		else
			rotate(a);
		i++;
	}
	while (a->len > 3)
		push(a, b);
}
