/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:42:00 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/10 22:28:02 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *a, t_stack *b, char *output)
{

}

void	sort_complex(t_stack *a, t_stack *b, t_info *info, char *output)
{
	int	chunk_idx;
	int	chunk_min;
	int	chunk_max;
	
	if (info->size == 0)
	{
		
	}
}

void	sort_stack(t_stack *a, t_info *info, char *output)
{
	t_stack	b;

	if (!initialize(&b, info->size))
		free_error(a->data);
	if (info->size <= CHUNK_MIN_CONSTANT)
		sort_small(a, &b, output);
	else
		sort_complex(a, &b, info, output);
	free(a->data);
	free(b.data);
}
