/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:42:04 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/31 22:08:08 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// unsigned int	count_rotation(t_stack *stack, t_info *info, int idx)
// {
// 	if (in_upper(idx, stack))
// 	{
// 		// printf("ra count : %d\n", ft_abs(idx - ((stack->front + 1 + info->size) % info->size)));
// 		return (ft_abs(idx - ((stack->front + 1 + info->size) % info->size)));
// 	}
// 	else
// 	{
// 		// printf("rra count : %d\n", ft_abs(stack->rear - idx + 1));
// 		return (ft_abs(stack->rear - idx + 1));
// 	}
// }

void	put_on_top_rra(int rra_count, t_stack *stack, t_info *info)
{
	int	i;

	i = 0;
	while (i < rra_count)
	{
		print_operation(reverse_rotate(stack, info));
		i++;
	}
}

void	put_on_top_ra(int ra_count, t_stack *stack, t_info *info)
{
	int	i;

	i = 0;
	while (i < ra_count)
	{
		print_operation(rotate(stack, info));
		i++;
	}
}

void	greedy_on_a(t_stack *a, t_info *info)
{
	int	ra_count;
	int	rra_count;

	ra_count = search_from_top(a, info);
	rra_count = search_from_bottom(a, info);
	printf("1.%d\n2.%d\n", ra_count, rra_count);
	// if (ra_count == ERROR && rra_count == ERROR)
	// 	return ;
	if (ra_count <= rra_count)
		put_on_top_ra(ra_count, a, info);
	else
		put_on_top_rra(rra_count, a, info);

	// if (count_rotation(a, info, idx_from_top) 
	// 	<= count_rotation(a, info, idx_from_bottom))
	// 	put_on_top(idx_from_top, a, info);
	// else
	// 	put_on_top(idx_from_bottom, a, info);
}

void	a_to_b(t_stack *a, t_stack *b, t_info *info, int chunk)
{
	info->a = 1;
	while (chunk > 0)
	{
		greedy_on_a(a, info);
		print_operation(push(a, b, info));
		chunk--;
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
