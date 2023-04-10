/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:17:51 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/10 19:47:25 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_a(t_stack *a, int size, int *data)
{
	a->data = data;
	a->front = size - 1;
	a->rear = size - 2;
	a->len = size - 1;
	a->size = size;
	a->a = 1;
}

void	initialize_b(t_stack *b, int size, int *data)
{
	b->data = (int *)malloc(sizeof(int) * size);
	if (!b->data)
		free_error(data);
	b->front = 0;
	b->rear = 0;
	b->len = 0;
	b->size = size;
	b->a = 0;
}
