/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:48:00 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/05 14:08:14 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_data(int *data, int size, int *sorted, t_stack *a)
{
	int	i;
	int	idx;

	i = 0;
	while (i < a->size - 1)
	{
		idx = 0;
		while (sorted[idx] != data[i])
			idx++;
		a->data[i] = idx;
		i++;
	}
	free(sorted);
	free(data);
}
