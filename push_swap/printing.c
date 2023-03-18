/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:44:45 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/18 22:02:42 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(int op)
{
	if (op == SA)
		write(1, "sa\n", 3);
	else if (op == SB)
		write(1, "sb\n", 3);
	else if (op == SS)
		write(1, "ss\n", 3);
	else if (op == PA)
		write(1, "pa\n", 3);
	else if (op == PB)
		write(1, "pb\n", 3);
	else if (op == RA)
		write(1, "ra\n", 3);
	else if (op == RB)
		write(1, "rb\n", 3);
	else if (op == RR)
		write(1, "rr\n", 3);
	else if (op == RRA)
		write(1, "rra\n", 4);
	else if (op == RRB)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
}
