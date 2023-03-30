/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:42:04 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/30 22:49:04 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	count_rotation(t_stack *stack, t_info *info, int idx)
{
	if (in_upper(idx, stack))
		return (ft_abs(idx - ((stack->front + 1) % info->size)));
	else
		return (ft_abs(stack->rear - idx + 1));
}

void	put_on_top(int idx, t_stack *stack, t_info *info)
{
	int	to_push;

	if (idx == ERROR)
	{
		// printf("eeee");
		return ;
	}
	to_push = stack->data[idx];
	if (in_upper(idx, stack))
	{
		while (get_top(stack, info->size) != to_push)
			print_operation(rotate(stack, info));
	}
	else
	{
		while (get_top(stack, info->size) != to_push)
			print_operation(reverse_rotate(stack, info));
	}
}

void	greedy_on_a(t_stack *a, t_info *info)
{
	int	idx_from_top;
	int	idx_from_bottom;

	idx_from_top = search_from_top(a, info);
	idx_from_bottom = search_from_bottom(a, info);
	if (idx_from_top == ERROR && idx_from_bottom == ERROR)
		return ;
	// printf("top:%d bottom:%d\n", idx_from_top, idx_from_bottom);
	if (count_rotation(a, info, idx_from_top) \
		<= count_rotation(a, info, idx_from_bottom))
		put_on_top(idx_from_top, a, info);
	else
		put_on_top(idx_from_bottom, a, info);
}

void	a_to_b(t_stack *a, t_stack *b, t_info *info, int chunk)
{
	info->a = 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
	while (chunk > 0)
	{
		greedy_on_a(a, info);
		if (in_range(info->min, info->max, get_top(a, info->size)))
		{
			print_operation(push(a, b, info));
			chunk--;
		}
	}
}
	// int	chunk;
	// int	min;
	// int	max;
	// int	rest;

	// chunk = (info->size / 3);
	// min = chunk_idx * chunk;
	// max = (chunk_idx + 1) * chunk;
	// rest = (info->size % 3);
	// if (chunk_idx == 2 && rest != 0)
	// {
	// 	max += rest;
	// 	chunk += rest;
	// }
