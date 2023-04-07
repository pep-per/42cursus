// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   greedy_a.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/18 18:42:04 by jiyeolee          #+#    #+#             */
// /*   Updated: 2023/04/08 05:05:21 by jiyeolee         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// // unsigned int	count_rotation(t_stack *stack, t_info *info, int idx)
// // {
// // 	if (in_upper(idx, stack))
// // 	{
// // 		// printf("ra count : %d\n", ft_abs(idx - ((stack->front + 1 + info->size) % info->size)));
// // 		return (ft_abs(idx - ((stack->front + 1 + info->size) % info->size)));
// // 	}
// // 	else
// // 	{
// // 		// printf("rra count : %d\n", ft_abs(stack->rear - idx + 1));
// // 		return (ft_abs(stack->rear - idx + 1));
// // 	}
// // }

// void	put_on_top_rr(int rr_count, t_stack *stack, t_info *info)
// {
// 	int	i;

// 	i = 0;
// 	while (i < rr_count)
// 	{
// 		print_operation(reverse_rotate(stack, info));
// 		i++;
// 	}
// }

// void	put_on_top_r(int r_count, t_stack *stack, t_info *info)
// {
// 	int	i;

// 	i = 0;
// 	while (i < r_count)
// 	{
// 		print_operation(rotate(stack, info));
// 		i++;
// 	}
// }

// void	greedy_on_a(t_stack *a, t_info *info)
// {
// 	int	r_count;
// 	int	rr_count;

// 	r_count = search_from_top(a, info);
// 	rr_count = search_from_bottom(a, info) + 1;
// 	if (r_count <= rr_count)
// 		put_on_top_r(r_count, a, info);
// 	else
// 		put_on_top_rr(rr_count, a, info);
// }

// void	a_to_b(t_stack *a, t_stack *b, t_info *info, int chunk)
// {
// 	for (int i = (a->front + 1 + info->size) % info->size; i != a->front; i = (i + 1 + info->size) % info->size)
// 			printf("%d\n", a->data[i]);
// 	info->a = 1;
// 	while (chunk > 0)
// 	{
// 		greedy_on_a(a, info);
// 		printf("-------\n");
// 		for (int i = (a->front + 1 + info->size) % info->size; i != a->front; i = (i + 1 + info->size) % info->size)
// 			printf("%d\n", a->data[i]);
// 		printf("-------\n");
// 		print_operation(push(a, b, info));
// 		chunk--;
// 	}
// }
// 	// int	chunk;
// 	// int	min;
// 	// int	max;
// 	// int	rest;

// 	// chunk = (info->size / 3);
// 	// min = chunk_idx * chunk;
// 	// max = (chunk_idx + 1) * chunk;
// 	// rest = (info->size % 3);
// 	// if (chunk_idx == 2 && rest != 0)
// 	// {
// 	// 	max += rest;
// 	// 	chunk += rest;
// 	// }
