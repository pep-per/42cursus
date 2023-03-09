/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:42:00 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/09 23:09:17 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *stack)
{

}

void	sort_complex(t_stack *stack)
{
	stack->pivot1 = stack->size * (1 / 3);
	stack->pivot2 = stack->size * (2 / 3);
	if (stack->size == 0)
	{
		/* code */
	}
	
}

int	initialize_stack(t_stack *stack, int *data, int count)
{
	int	*copy;

	if (!initialize_deque(&stack->a, count))
		return (0);
	if (!initialize_deque(&stack->b, count))
	{
		free(stack->a.data);
		return (0);
	}
	stack->size = count;
	stack->pivot1 = 0;
	stack->pivot2 = 0;
}

void	sort(t_stack stack)
{
	t_deque	b;

	b = initialize_deque(b, );
	if (stack.size < 3)
		sort_small(&stack);
	else
		sort_complex(&stack);
	free(stack.a.data);
	free(stack.b.data);
}
