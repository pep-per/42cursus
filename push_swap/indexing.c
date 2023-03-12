/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:48:00 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/12 22:32:58 by jiyeolee         ###   ########.fr       */
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
			//minus
		stack->data[i] = idx;
		i++;
	}
	free(sorted);
	free(data);
}
