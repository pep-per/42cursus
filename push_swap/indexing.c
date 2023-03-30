/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:48:00 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/30 20:35:37 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_data(int *data, int size, int *sorted, t_stack *stack)
{
	int	i;
	int	idx;

	i = 0;
	while (i < size)
	{
		idx = 0;
		while (sorted[idx] != data[i])
			idx++;
		stack->data[i] = idx;
		i++;
	}
	stack->len = size;
	stack->front = 0;
	stack->rear = size - 1;
	free(sorted);
	free(data);
}
