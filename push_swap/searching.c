// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   searching.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/18 21:38:13 by jiyeolee          #+#    #+#             */
// /*   Updated: 2023/04/01 20:57:00 by jiyeolee         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// int	search_from_top(t_stack *a, t_info *info)
// {
// 	int	idx;
// 	int	r_count;

// 	idx = (a->front + 1 + info->size) % info->size;
// 	r_count = 0;
// 	while (idx != a->front)
// 	{
// 		if ((info->min <= a->data[idx]) && (a->data[idx] <= info->max))
// 			return (r_count);
// 		r_count++;
// 		idx = (idx + 1 + info->size) % info->size;
// 	}
// 	return (r_count);
// }

// int	search_from_bottom(t_stack *a, t_info *info)
// {
// 	int	idx;
// 	int	rr_count;

// 	idx = a->rear;
// 	rr_count = 0;
// 	while (idx != a->front)
// 	{
// 		if ((info->min <= a->data[idx]) && (a->data[idx] <= info->max))
// 			return (rr_count);
// 		rr_count++;
// 		idx = (idx - 1 + info->size) % info->size;
// 	}
// 	return (rr_count);
// }

// int	search(t_stack *b, t_info *info, int min, int max)
// {
// 	int	idx;
// 	int	count;

// 	idx = (b->front + 1 + info->size) % info->size;
// 	count = 0;
// 	while (idx != b->front)
// 	{
// 		if (b->data[idx] == min || b->data[idx] == max)
// 			break ;
// 		count++;
// 		idx = (idx + 1 + info->size) % info->size;
// 	}
// 	return (count);
// }

// // int	search_max(t_stack *a, t_stack *b)
// // {
// // 	int	idx;
// // 	int	max;

// // 	max = a->data[a->rear] + 1;
// // 	idx = b->front;
// // 	while (++idx <= b->rear)
// // 	{
// // 		if (b->data[idx] == max)
// // 			return (idx);
// // 	}
// // 	return (NOTHING_TO_PUSH);
// // }
