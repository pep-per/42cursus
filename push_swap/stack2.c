/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:41:58 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/30 21:37:48 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_top(t_stack *stack, int size)
{
	return (stack->data[(stack->front + 1) % size]);
}

int	get_bottom(t_stack *stack)
{
	return (stack->data[stack->rear]);
}
